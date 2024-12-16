#ifndef VGA_H
#define VGA_H

#include <stdint.h>

#define VGA_WIDTH  80
#define VGA_HEIGHT 25

// Clears the VGA buffer with the given color.
void vga_clear(uint8_t color);

// null-terminated string to the VGA buffer.
void vga_write_string(const char* str, int row, int col, uint8_t color);

#endif
