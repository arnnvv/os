#include <stdint.h>

static uint16_t* const VGA_BUFFER = (uint16_t*)0xB8000;
static const int VGA_WIDTH = 80;
static const int VGA_HEIGHT = 25;

static uint16_t make_vga_entry(char c, uint8_t color) {
    return (uint16_t)c | (uint16_t)color << 8;
}

static void vga_clear() {
    for (int y = 0; y < VGA_HEIGHT; y++) {
        for (int x = 0; x < VGA_WIDTH; x++) {
            VGA_BUFFER[y * VGA_WIDTH + x] = make_vga_entry(' ', 0x0F);
        }
    }
}

static void vga_write_string(const char* str, int row, int col, uint8_t color) {
    int i = 0;
    while (str[i]) {
        VGA_BUFFER[row * VGA_WIDTH + col + i] = make_vga_entry(str[i], color);
        i++;
    }
}

void kernel_main() {
    vga_clear();
    vga_write_string("Welcome to My OS Kernel!", 12, 24, 0x0F);
    for (;;);
}
