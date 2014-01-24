# invoke SourceDir generated makefile for main.pe430
main.pe430: .libraries,main.pe430
.libraries,main.pe430: package/cfg/main_pe430.xdl
	$(MAKE) -f Y:\MSP430-OS/src/makefile.libs

clean::
	$(MAKE) -f Y:\MSP430-OS/src/makefile.libs clean

