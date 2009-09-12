TARGET		:=	$(shell basename $(CURDIR))


pc:
	make -f Makefile.pc

ds:
	make -f Makefile.ds

run:
	wine "emulator/nogba.exe" "$(TARGET).nds"

clean:
	make -f Makefile.ds clean
	make -f Makefile.pc clean
