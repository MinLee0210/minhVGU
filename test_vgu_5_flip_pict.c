#include <stdio.h>
#include <stdlib.h>

#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"
#define STB_IMAGE_WRITE_IMPLEMENTATION
#include "stb_image_write.h"


// vertical flipping
int main(void) {
    // read image
    int width, height, channels;
    unsigned char *img = stbi_load("Minh - 06_2013.jpg", &width, &height, &channels, 0);

    // copy
    unsigned int img_size = width * height * channels;
    unsigned char* out_img = malloc(img_size);

    printf("Height: %d   and width: %d  \n", height, width);
    int data[2][2] = {{1, 0},
                      {0, -1}};
    int vector[2];
    for (int x2=0; x2<height; x2++)
    {
        for (int x1=0; x1<width; x1++)
        {
            vector[0] = x1;
            vector[1] = x2;

            int new_x1 = 1*vector[0] + 0*vector[1];
            int new_x2 = 0*vector[0] - 1*vector[1];
            new_x2 = new_x2 + height - 5;

            out_img[new_x2*width + new_x1] = img[x2*width + x1];
        }
    }


    // save image
    stbi_write_png("Minh - 06_2013_vflip_2.jpg", width, height, channels, out_img, width*channels);

    stbi_image_free(img);
    stbi_image_free(out_img);
}


