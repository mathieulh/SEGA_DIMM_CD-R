
#pragma pack(1)

union doubleendian
{
	unsigned char bytes[8];
	struct 
	{
		unsigned int l;
		unsigned int b;
	};
};

struct _iso_primary_record
{
	unsigned char type[1];
	unsigned char ID[6];
	unsigned char zero[1];
	unsigned char system_id[32];
	unsigned char volume_id[32];
	unsigned char zeros1[8];
	doubleendian nsectors;
	unsigned char zeros2[32];
	unsigned char vol_size[4];
	unsigned char vol_seq[4];
	unsigned char secsize[4];
	doubleendian pathtablelength;
	unsigned int pathtable;
	unsigned int pathable2;
	unsigned int pathtablebe;
	unsigned int pathtable2be;
	unsigned char rootrecord[34];
	unsigned char volumesetid[128];
	unsigned char pubid[128];
	unsigned char preparerid[128];
	unsigned char appid[128];
	unsigned char cpy[37];
	unsigned char abst[37];
	unsigned char bib[37];
	unsigned char creation[17];
	unsigned char modif[17];
	unsigned char expires[17];
	unsigned char effective[17];
	unsigned char one[1];
	unsigned char zero2[1];
	unsigned char reserved[512];
	unsigned char zeros3[653];
};
struct _rootdirrecord
{
	unsigned char Size;
	unsigned char ex;
	doubleendian FirstFile;
	doubleendian FileLength;
	unsigned char Y;
	unsigned char M;
	unsigned char D;
	unsigned char H;
	unsigned char Min;
	unsigned char Sec;
	unsigned char GMT;
	unsigned char Flags;
	unsigned char Interleaved;
	unsigned char Gap;
	unsigned char one[4];
	unsigned char Length;
};
#pragma pack()
