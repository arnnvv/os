#include <stdint.h>
#include "vga.h"

static uint16_t* const VGA_BUFFER = (uint16_t*)0xB8000;

static inline uint16_t make_vga_entry(char c, uint8_t color) {
    return (uint16_t)c | (uint16_t)color << 8;
}

void vga_clear(uint8_t color) {
    for (int y = 0; y < VGA_HEIGHT; y++) {
        for (int x = 0; x < VGA_WIDTH; x++) {
            VGA_BUFFER[y * VGA_WIDTH + x] = make_vga_entry(' ', color);
        }
    }
}

void vga_write_string(const char* str, int row, int col, uint8_t color) {
    int i = 0;
    while (str[i]) {
        VGA_BUFFER[row * VGA_WIDTH + col + i] = make_vga_entry(str[i], color);
        i++;
    }
}
