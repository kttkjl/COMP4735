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
	hal_io_video_putc(50, 80, 0xFFFFFFFF, 'a');
	hal_io_video_putc(100, 80, 0xFFFFFFFF, 'b');
	hal_io_video_putc(150, 80, 0xFFFFFFFF, 'c');
	hal_io_video_putc(200, 80, 0xFFFFFFFF, 'd');
	hal_io_video_putc(250, 80, 0xFFFFFFFF, 'e');
	hal_io_video_putc(300, 80, 0xFFFFFFFF, 'f');
	hal_io_video_putc(350, 80, 0xFFFFFFFF, 'g');
	hal_io_video_putc(400, 80, 0xFFFFFFFF, 'h');
	hal_io_video_putc(450, 80, 0xFFFFFFFF, 1);
	hal_io_video_putc(500, 80, 0xFFFFFFFF, 2);
	hal_io_video_putc(550, 80, 0xFFFFFFFF, 'k');
	hal_io_video_putc(600, 80, 0xFFFFFFFF, 'l');
	hal_io_video_putc(650, 80, 0xFFFFFFFF, 'm');
	hal_io_video_putc(700, 80, 0xFFFFFFFF, 'n');
	hal_io_video_putc(750, 80, 0xFFFFFFFF, 'o');
	hal_io_video_putc(800, 80, 0xFFFFFFFF, 'p');
	hal_io_video_putc(850, 80, 0xFFFFFFFF, 'q');
	hal_io_video_putc(900, 80, 0xFFFFFFFF, 'r');
	hal_io_video_putc(50, 110, 0xFFFFFFFF, 's');
	hal_io_video_putc(100, 110, 0xFFFFFFFF, 't');
	hal_io_video_putc(150, 110, 0xFFFFFFFF, 'u');
	hal_io_video_putc(200, 110, 0xFFFFFFFF, 'v');
	hal_io_video_putc(250, 110, 0xFFFFFFFF, 'w');
	hal_io_video_putc(300, 110, 0xFFFFFFFF, 3);
	hal_io_video_putc(350, 110, 0xFFFFFFFF, 4);
	hal_io_video_putc(400, 110, 0xFFFFFFFF, 'z');
	
	//Begin the one-line typewriter
	hal_io_serial_init();

	hal_io_serial_puts(0, "FOIUEHFTOIEWJGPOEWJ[OEWJFPOEWJ]:\n\r");


}