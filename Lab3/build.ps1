
Clear-Host;

$exec=$args[0]
$ErrorActionPreference = "Stop"

Write-Host "Building..."
& 'C:\Program Files (x86)\GNU Tools ARM Embedded\8 2018-q4-major\bin\arm-none-eabi-as.exe' src/boot.s -o output/boot.o
& 'C:\Program Files (x86)\GNU Tools ARM Embedded\8 2018-q4-major\bin\arm-none-eabi-as.exe' src/video_sample.s -o output/video_sample.o
& "C:\Program Files (x86)\GNU Tools ARM Embedded\8 2018-q4-major\bin\arm-none-eabi-gcc.exe" -mcpu=cortex-a7 -fpic -ffreestanding -std=gnu99 -c src/hal.c -o output/hal.o -O0
& "C:\Program Files (x86)\GNU Tools ARM Embedded\8 2018-q4-major\bin\arm-none-eabi-gcc.exe" -mcpu=cortex-a7 -fpic -ffreestanding -std=gnu99 -c src/uart.c -o output/uart.o -O0
& "C:\Program Files (x86)\GNU Tools ARM Embedded\8 2018-q4-major\bin\arm-none-eabi-gcc.exe" -mcpu=cortex-a7 -fpic -ffreestanding -std=gnu99 -c -lc src/kernel.c -o output/kernel.o -O0
& 'C:\Program Files (x86)\GNU Tools ARM Embedded\8 2018-q4-major\bin\arm-none-eabi-ld.exe' output/boot.o output/video_sample.o output/hal.o output/uart.o output/kernel.o -T linker.ld -o output/kernel.elf

& 'C:\Program Files (x86)\GNU Tools ARM Embedded\8 2018-q4-major\bin\arm-none-eabi-objdump.exe' -D output/kernel.o | Out-File -filepath output/kernel_o.lss -Encoding ASCII
& 'C:\Program Files (x86)\GNU Tools ARM Embedded\8 2018-q4-major\bin\arm-none-eabi-objdump.exe' -D output/kernel.elf | Out-File -filepath output/kernel_elf.lss -Encoding ASCII
& 'C:\Program Files (x86)\GNU Tools ARM Embedded\8 2018-q4-major\bin\arm-none-eabi-objdump.exe' -s output/kernel.o | Out-File -filepath output/kernel_o.bin_dump -Encoding ASCII
& 'C:\Program Files (x86)\GNU Tools ARM Embedded\8 2018-q4-major\bin\arm-none-eabi-objdump.exe' -s output/kernel.elf | Out-File -filepath output/kernel_elf.bin_dump -Encoding ASCII

Write-Host "Success"

if ( $exec -eq "exec=true" )
{
  Write-Host "         P I ' S     U A R T 0          "
  Write-Host "= = = = = = = = = = = = = = = = = = = = "
  & 'C:\Program Files\qemu\qemu-system-arm.exe' -m 256 -M raspi2 -serial stdio -kernel output/kernel.elf
}
