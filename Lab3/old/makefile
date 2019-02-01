EAC = arm-none-eabi-as.exe
ECC = arm-none-eabi-gcc.exe
ELD = arm-none-eabi-ld.exe

default: kernel.elf

boot.o:
	$(EAC) boot.s -o boot.o

video_sample.o:
	$(EAC) video_sample.s -o video_sample.o

kernel.o:
	$(ECC) -mcpu=arm6 -fpic -ffreestanding -std=gnu99 -c kernel.c -o kernel.o -O0

kernel.elf: boot.o video_sample.o kernel.o
	$(ELD) boot.o video_sample.o kernel.o -T linker.ld -o kernel.elf

clean:
	$(RM) kernel.elf *.o *~
