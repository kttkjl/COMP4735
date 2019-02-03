#pragma once
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include "uart.h"
#include "letters.h"

void hal_io_video_init();

void hal_io_serial_init();
void hal_io_serial_putc(uint32_t serial_id, uint8_t ch);
void hal_io_serial_puts(uint32_t serial_id, uint8_t * ch);
uint8_t hal_io_serial_getc(uint32_t serial_id);



void hal_io_video_putpixel(int x, int y, uint32_t color);

void hal_io_video_putc(int x, int y, uint32_t color, char ch);

void hex_to_binary(int *bits, unsigned int hex);
