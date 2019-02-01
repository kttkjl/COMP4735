/*
*
*	The Kernel
*
*/

#include "hal.h"

/*
 *		Kernel's entry point
 *
**/

int a;

void main(uint32_t r0, uint32_t r1, uint32_t atags){
	hal_io_video_init();
	hal_io_video_putpixel(500, 50, 0xFFFFFFFF);
	hal_io_video_putc(1000, 1000, 0xFFFFFFFF, 'a');
	//Begin the one-line typewriter
	hal_io_serial_init();

	hal_io_serial_puts(0, "FOIUEHFTOIEWJGPOEWJ[OEWJFPOEWJ]:\n\r");

	while (1)