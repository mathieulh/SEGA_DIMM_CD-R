README:


FIRMWARE: 

This is a port of the 3.17 CD-R Dimm firmware patched originally done by ElSemi to the version 4.02 which patches the media checks to pass on CD-R using the GD-ROM drive on NAOMI.

This firmware does everything the 4.02 firmware does (CF loading with the ability to use use Compact Flash cards from other vendors than HAGIWARA SYS-COM, ability to run on non regular (non-net) DIMM Boards) and adds CD-R support to it.

The TSOP_flash folder contains a TSOP image to be flashed directly with a programmer, the UPDATER folder contains the update to run on an existing dimm board (assuming you have some way of running custom code such as CF loading or netbooting).

As it stands, you will need to use the supplied naoiso tool (in this repository), the image is written at 0x57E4000 (LBA 45000) in the iso file, you may opt to use an original or a zero key PIC. 

I could have patched the LBA limitation but that would have broken GD-ROM compatibility and there are no NAOMI games that use over 512MB anyway for us to need the extra CD-R space.

Credits go to: 

- ELSemi for modified 3.17 CD-R patches
- Mathieulh for porting the CD-R patches to the 4.02 firmware and crafting it into a 4.03 update
- Whomever contributed in making the 4.02 firmware.


NAOISO:

Following the release of the hacked 4.03 SEGA DIMM Firmware (by yours truly) which adds support for CD-R media (using the GD-ROM drive)

One needed a way to convert a game into a proper image that can be burned on a CD-R; ELSemi, the author of the original 3.17 firmware patched for CD-R support upon which the patches in the 4.03 firmware were based from, also made a support tool (which got leaked along with the modified 3.17 firmware) 

So far so good, at least that's the theory, the issue when dealing with leaked software, is that they were not intended for release, and therefore, as such is the case of naoiso, unfinished, naoiso thus suffered from a bug which prevented it from generated a decrypted image file.

This aside another issue was later identified in which the DIMM firmware would perform a LBA check for the location of NAOMIGD.BIN, which would not match the location on an original GD-ROM media when burned to a CD-R, this would cause the Naomi to reboot with an ERROR25, fortunately MetalliC supplied us with the tidbit that a specifc flag in the info file allows to skip that check entirely (and saved me from further investigating the DIMM firmware).

As such I took it upon myself to to craft a new version of the NaoIso application which fixes the bug, and thus allow to generate a decrypted iso for 00 key PICs, as well as to automatically add the flag to the generated iso.

HOW TO USE: 
This tool converts an extracted track03.iso from a GD-ROM dump (or an extracted CHD) into a burnable iso, this means, dump your GD-ROM, or extract your CHD, convert track03 from binary data to iso, (use a tool such as bin2iso to do this.)

then open naiso, select your iso, paste your security PIC key, set the info file name to something that matches your current PIC, (if it's a 00 key PIC, that's usually ABC.BIN), paste a new key if you are using a non zero PIC, and click on "Start"

Credits go to:

- ELSemi for the original NAOISO application
- Mathieulh for the decryption fix and LBA flag (aka update 1.01 and onward of this application)
- MetalliC for telling us how where to set the flag that skips the 2 hour LBA check.
- Idc for all the help he provided while testing both the firmware and NaoIso, especially as I do not own a GD-ROM setup myself.


I am not responsible for whatever damage may occur to your devices, that’s all at your own risk. (ie. The usual disclaimer), I am not responsible if this causes your dimm board to catch on fire or so on.


-Mathieulh
