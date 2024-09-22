#include <stdint.h>

#ifndef MULTIBOOT_H
#define MULTIBOOT_H

struct multiboot_info {
    uint8_t unused[88];
    uint64_t framebuffer_addr;
    uint32_t framebuffer_pitch;
    uint32_t framebuffer_width;
    uint32_t framebuffer_height;
    uint8_t framebuffer_bpp; //bpp=bits per pixel
    uint8_t framebuffer_type; //0 = indexed color, 1 = RGB, 2 = EGA-standard text mode
    union {
      struct {
        uint32_t framebuffer_palette_addr;
        uint16_t framebuffer_palette_num_colors;
      };
      struct {
        uint8_t framebuffer_red_field_position;
        uint8_t framebuffer_red_mask_size;
        uint8_t framebuffer_green_field_position;
        uint8_t framebuffer_green_mask_size;
        uint8_t framebuffer_blue_field_position;
        uint8_t framebuffer_blue_mask_size;
      };
    };
};
#endif
