/* Emacs style mode select -*- C++ -*-
 *
 * des.c - DES and Triple-DES encryption/decryption Algorithm
 *	Copyright (C) 1998 Free Software Foundation, Inc.
 *
 * Please see below for more legal information!
 *
 * According to the definition of DES in FIPS PUB 46-2 from December 1993.
 * For a description of triple encryption, see:
 *   Bruce Schneier: Applied Cryptography. Second Edition.
 *   John Wiley & Sons, 1996. ISBN 0-471-12845-7. Pages 358 ff.
 *
 * This file is part of GnuPG.
 *
 * GnuPG is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * GnuPG is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA
 */


#ifndef __DES_H__
#define __DES_H__

//===========================================================================
//
// GnuPG types.h
//

/* The AC_CHECK_SIZEOF() in configure fails for some machines.
 * we provide some fallback values here */
#if !SIZEOF_UNSIGNED_SHORT
  #undef SIZEOF_UNSIGNED_SHORT
  #define SIZEOF_UNSIGNED_SHORT 2
#endif
#if !SIZEOF_UNSIGNED_INT
  #undef SIZEOF_UNSIGNED_INT
  #define SIZEOF_UNSIGNED_INT 4
#endif
#if !SIZEOF_UNSIGNED_LONG
  #undef SIZEOF_UNSIGNED_LONG
  #define SIZEOF_UNSIGNED_LONG 4
#endif


#include <sys/types.h>


#ifndef HAVE_BYTE_TYPEDEF
  #undef byte	    /* maybe there is a macro with this name */
  typedef unsigned char byte;
  #define HAVE_BYTE_TYPEDEF
#endif

//------------------ unused --------------------

#if 0

#ifndef HAVE_USHORT_TYPEDEF
  #undef ushort     /* maybe there is a macro with this name */
  typedef unsigned short ushort;
  #define HAVE_USHORT_TYPEDEF
#endif

#ifndef HAVE_ULONG_TYPEDEF
  #undef ulong	    /* maybe there is a macro with this name */
  typedef unsigned long ulong;
  #define HAVE_ULONG_TYPEDEF
#endif

#ifndef HAVE_U16_TYPEDEF
  #undef u16	    /* maybe there is a macro with this name */
  #if SIZEOF_UNSIGNED_INT == 2
    typedef unsigned int   u16;
  #elif SIZEOF_UNSIGNED_SHORT == 2
    typedef unsigned short u16;
  #else
    #error no typedef for u16
  #endif
  #define HAVE_U16_TYPEDEF
#endif

#endif 

//---------------------------------------------------------

#ifndef HAVE_U32_TYPEDEF
  #undef u32	    /* maybe there is a macro with this name */
  #if SIZEOF_UNSIGNED_INT == 4
    typedef unsigned int u32;
  #elif SIZEOF_UNSIGNED_LONG == 4
    typedef unsigned long u32;
  #else
    #error no typedef for u32
  #endif
  #define HAVE_U32_TYPEDEF
#endif

#ifndef HAVE_U64_TYPEDEF
  #undef u64	    /* maybe there is a macro with this name */
  #if SIZEOF_UNSIGNED_INT == 8
    typedef unsigned int u64;
    #define HAVE_U64_TYPEDEF
  #elif SIZEOF_UNSIGNED_LONG == 8
    typedef unsigned long u64;
    #define HAVE_U64_TYPEDEF
  #elif __GNUC__ >= 2 || defined(__SUNPRO_C)
    typedef unsigned long long u64;
    #define HAVE_U64_TYPEDEF
  #endif
#endif

typedef union {
    int a;
    short b;
    char c[1];
    long d;
  #ifdef HAVE_U64_TYPEDEF
    u64 e;
  #endif
    float f;
    double g;
} PROPERLY_ALIGNED_TYPE;

typedef struct string_list {
    struct string_list *next;
    unsigned int flags;
    char d[1];
} *STRLIST;

//
//   End of GnuPG types.h
//
//============================================================================

/*
 * Encryption/Decryption context of DES
 */
typedef struct _des_ctx
  {
    u32 encrypt_subkeys[32];
    u32 decrypt_subkeys[32];
  }
des_ctx[1];

/*
 * Handy macros for encryption and decryption of data
 */
#define des_ecb_encrypt(ctx, from, to)		des_ecb_crypt(ctx, from, to, 0)
#define des_ecb_decrypt(ctx, from, to)		des_ecb_crypt(ctx, from, to, 1)
#define tripledes_ecb_encrypt(ctx, from, to)	tripledes_ecb_crypt(ctx, from, to, 0)
#define tripledes_ecb_decrypt(ctx, from, to)	tripledes_ecb_crypt(ctx, from, to, 1)

extern int
des_setkey (struct _des_ctx *ctx, const byte * key);
extern int
des_ecb_crypt (struct _des_ctx *ctx, const byte * from, byte * to, int mode);


#endif
