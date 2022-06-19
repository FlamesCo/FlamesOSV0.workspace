#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    
    //Get the size of the vram buffer
    size_t vram_size = 0x100000000;
    
    //Create a vram buffer
    unsigned char *vram_buffer = (unsigned char*)malloc(vram_size);
    
    //Initialize the vram buffer
    memset(vram_buffer, 0x00, vram_size);
    
    
    //Set the vram pointer to the start of the vram buffer
    unsigned char *vram = vram_buffer;
    
    
    //Set the vram pointer to the start of the framebuffer
    vram += 0x00200000;
    

    //Set the framebuffer width to 640 and the height to 480
    int framebuffer_width = 640;
    int framebuffer_height = 480;

    

    //Calculate the number of pixels in the framebuffer
    int num_pixels = framebuffer_width * framebuffer_height;

    

    //Set the framebuffer stride to the width of the framebuffer in bytes
    int framebuffer_stride = framebuffer_width * 4;

    

    //Set the framebuffer color depth to 32 bits per pixel (4 bytes per pixel)
    int framebuffer_color_depth = 32;

    

    //Create a framebuffer structure 
    struct {

        //The width of the framebuffer in pixels 
        int width;

        //The height of the framebuffer in pixels 
        int height;

        //The number of bytes per row of pixels 
        int stride;

        //The number of bits per pixel 
        int color_depth;

        //Pointer to the start of the pixel data 
        unsigned char* pixels;

    }framebuffer = {framebuffer_width, framebuffer_height, framebuffer_stride, framebuffer_color_depth, vram};

    

    //Declare a variable to store a pixel index 
    int pixel = 0;

    

   /* Draw a gradient from blue to red horizontally across the screen */ 

   for (pixel = 0; pixel < num_pixels; pixel++) {

       float percent = (float)pixel / (float)num_pixels;

       unsigned char r = (unsigned char)(percent * 255.0f);       /* red */ 

       unsigned char g = 0x00;                                    /* green */ 

       unsigned char b = (unsigned char)((1.0f - percent) * 255.0f); /* blue */ 

       unsigned char a = 0xff;                                    /* alpha */ 

       unsigned int color = ((a << 24) | (r << 16) | (g << 8) | b);      /* 32-bit color value */ 

       memcpy(&framebuffer.pixels[pixel*4], &color, 4);           /* write color value to pixel */ 

   }   return 0; /* success! */ }
