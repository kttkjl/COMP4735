EAC = arm-none-eabi-as.exe
ECC = arm-none-eabi-gcc.exe
ELD = arm-none-eabi-ld.exe
QSA = qemu-system-arm.exe

default: kernel.elf

boot.o:
	$(EAC) src/boot.s -o output/boot.o

video_sample.o:
	$(EAC) src/video_sample.s -o output/video_sample.o

kernel.o:
	$(ECC) -mcpu=cortex-a7 -fpic -ffreestanding -std=gnu99 -c src/kernel.c -o output/kernel.o -O0

kernel.elf: output/boot.o output/video_sample.o output/kernel.o
	$(ELD) output/boot.o output/video_sample.o output/kernel.o -T linker.ld -o kernel.elf

start: 
	$(QSA) -m 256 -M raspi2 -serial stdio -kernel kernel.elf

clean:
	$(RM) kernel.elf *.o *~
