#include "multiboot.h"
#include <stdint.h>

void initialize_graphics(struct multiboot_info* multiboot_info_addr){
    void* framebuffer_addr = (void*) multiboot_info_addr->framebuffer_addr;
    uint32_t framebuffer_pitch = multiboot_info_addr->framebuffer_pitch;
    uint32_t framebuffer_width = multiboot_info_addr->framebuffer_width;
    uint32_t framebuffer_height = multiboot_info_addr->framebuffer_height;
    uint8_t framebuffer_bpp = multiboot_info_addr->framebuffer_bpp;
    uint8_t framebuffer_type = multiboot_info_addr->framebuffer_type;
    switch (framebuffer_type){
      case 0: // not implemented yet
        break;
      case 1: //RGB
        uint32_t red = ((1 << multiboot_info_addr->framebuffer_red_mask_size) - 1) << multiboot_info_addr->framebuffer_red_field_position; 
        uint32_t green = ((1 << multiboot_info_addr->framebuffer_green_mask_size) - 1) << multiboot_info_addr->framebuffer_green_field_position; 
        uint32_t blue = ((1 << multiboot_info_addr->framebuffer_blue_mask_size) - 1) << multiboot_info_addr->framebuffer_blue_field_position; 
        uint32_t gold = red | (0xd7 << multiboot_info_addr->framebuffer_green_field_position); 
        uint32_t size = framebuffer_width * framebuffer_height;
        for(uint32_t i = 0; i < size; i++){ //assume pitch == width for now
             switch(framebuffer_bpp){
                case 8: //not implemented yet
                    {
                    }
                    break;
                case 15: //not implemented yet
                    {
                    }
                    break;
                case 16: //not implemented yet
                    {
                    }
                    break;
                case 32:
                    {
                      uint32_t *pixel = (uint32_t*)framebuffer_addr + i;
                      if(i <= 1 * (size/3)) {*pixel = 0;}
                      else if(i <= 2 * (size/3)) {*pixel = red;}
                      else if(i <= 3 * (size/3)) *pixel = gold;
                    }
                    break;
                case 24: //not implemented yet
                    {
                    }
                    break; 
                default:
                    {
                      uint8_t x = 1/0; //throw exception to exit
                    } 
                    break; 
            }
        }
        break;
    }
}

void kernel_main(){
    // grub put the multiboot information structure into ebx according to
    // the manuel https://www.gnu.org/software/grub/manual/multiboot/multiboot.html
    struct multiboot_info* ebx; 
    asm("\t movl %%ebx,%0" : "=r"(ebx));
    initialize_graphics(ebx);
    return;
}
