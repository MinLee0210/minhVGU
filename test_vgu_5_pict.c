#include <stdio.h>
#include <stdlib.h>

#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"
#define STB_IMAGE_WRITE_IMPLEMENTATION
#include "stb_image_write.h"

// copy color image
int main_1(void) {
    int width, height, channels;
    unsigned char *img = stbi_load("nature.jpg", &width, &height, &channels, 0);
    if(img == NULL) {
        printf("Error in loading the image\n");
        exit(1);
    }
    printf("Width of %dpx, a height of %dpx and %d channels\n", width, height, channels);


    // Convert the input image to gray
    unsigned int img_size = width * height * channels;
    unsigned char* out_img = malloc(img_size);

    for(unsigned char *p = img, *pout = out_img; p != img + img_size; p += channels, pout += channels) {
        *pout = (uint8_t)*p;
        *(pout+1) = (unsigned char)*(p+1);
        *(pout+2) = (unsigned char)*(p+2);
    }


    stbi_write_png("nature_copy.png", width, height, channels, out_img, width*channels);

    stbi_image_free(img);
    stbi_image_free(out_img);
}

// copy color image
int main(void) {
    int width, height, channels;
    unsigned char *img = stbi_load("nature.jpg", &width, &height, &channels, 0);
    printf("Width of %dpx, a height of %dpx and %d channels\n", width, height, channels);


    // Convert the input image to gray
    unsigned int img_size = width * height * channels;
    unsigned char* out_img = malloc(img_size);


    for (int i=0; i<height; i++)
    {
        for (int j=0; j<width; j++)
        {
            // pixel
            for (int c=0; c<3; c++)
            {
                out_img[i*width*channels + j*channels + c] = img[i*width*channels + j*channels + c];
            }
        }
    }

    stbi_write_png("nature_copy_2.png", width, height, channels, out_img, width*channels);

    stbi_image_free(img);
    stbi_image_free(out_img);
}

// convert to grayscale image
int main_3(void) {
    int width, height, channels;
    unsigned char *img_color = stbi_load("nature.jpg", &width, &height, &channels, 0);
    if(img_color == NULL) {
        printf("Error in loading the image\n");
        exit(1);
    }
    printf("Width of %dpx, a height of %dpx and %d channels\n", width, height, channels);


    // Convert the input image to gray
    unsigned int img_size = width * height * channels;
    int gray_channels = 1;
    unsigned int gray_img_size = width * height * gray_channels;
    unsigned char *gray_img = malloc(gray_img_size);

    for(unsigned char *p = img_color, *pg = gray_img; p != img_color + img_size; p += channels, pg += gray_channels) {
        *pg = (unsigned char)((*p + *(p + 1) + *(p + 2))/3.0);
    }


    stbi_write_png("nature_gray.png", width, height, gray_channels, gray_img, width * gray_channels);

    stbi_image_free(img_color);
    stbi_image_free(gray_img);
}

// convert to grayscale image
int main_4(void) {
    int width, height, channels;
    unsigned char *img_color = stbi_load("nature.jpg", &width, &height, &channels, 0);
    if(img_color == NULL) {
        printf("Error in loading the image\n");
        exit(1);
    }
    printf("Width of %dpx, a height of %dpx and %d channels\n", width, height, channels);


    // Convert the input image to gray
    unsigned int img_size = width * height * channels;
    int gray_channels = 1;
    unsigned int gray_img_size = width * height * gray_channels;
    unsigned char *gray_img = malloc(gray_img_size);

    int value = 0;
    for (int i=0; i<height; i++)
    {
        for (int j=0; j<width; j++)
        {
            value = 0;
            for (int c=0; c<3; c++)
            {
                 value += img_color[i*width*channels + j*channels + c];
            }
            gray_img[i*width + j] = (unsigned char) (value/3.0);
        }
    }


    stbi_write_png("nature_gray_2.png", width, height, gray_channels, gray_img, width * gray_channels);

    stbi_image_free(img_color);
    stbi_image_free(gray_img);
}

// vertical flipping
int main_5(void) {
    // read image
    int width, height, channels;
    unsigned char *img = stbi_load("nature_gray.png", &width, &height, &channels, 0);

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
            new_x2 = new_x2 + height - 1;

            out_img[new_x2*width + new_x1] = img[x2*width + x1];
        }
    }


    // save image
    stbi_write_png("nature_gray_vflip.png", width, height, channels, out_img, width*channels);

    stbi_image_free(img);
    stbi_image_free(out_img);
}


// horizontal flipping
int main_6(void) {
    // read image
    int width, height, channels;
    unsigned char *img = stbi_load("nature_gray.png", &width, &height, &channels, 0);

    // copy
    unsigned int img_size = width * height * channels;
    unsigned char* out_img = malloc(img_size);

    printf("Height: %d   and width: %d  \n", height, width);
    int data[2][2] = {{-1, 0},
                      {0, 1}};
    int vector[2];
    for (int x2=0; x2<height; x2++)
    {
        for (int x1=0; x1<width; x1++)
        {
            vector[0] = x1;
            vector[1] = x2;

            int new_x1 = -1*vector[0] + 0*vector[1];
            int new_x2 = 0*vector[0] + 1*vector[1];
            new_x1 = new_x1 + width - 1;

            out_img[new_x2*width + new_x1] = img[x2*width + x1];
        }
    }


    // save image
    stbi_write_png("nature_gray_hflip.png", width, height, channels, out_img, width*channels);

    stbi_image_free(img);
    stbi_image_free(out_img);
}


// horizontal flipping for color image
int main_7(void) {
    // read image
    int width, height, channels;
    unsigned char *img = stbi_load("nature.jpg", &width, &height, &channels, 0);

    // copy
    unsigned int img_size = width * height * channels;
    unsigned char* out_img = malloc(img_size);

    printf("Height: %d   and width: %d  \n", height, width);
    int data[2][2] = {{-1, 0},
                      {0, 1}};
    int vector[2];
    for (int x2=0; x2<height; x2++)
    {
        for (int x1=0; x1<width; x1++)
        {
            vector[0] = x1;
            vector[1] = x2;

            int new_x1 = -1*vector[0] + 0*vector[1];
            int new_x2 = 0*vector[0] + 1*vector[1];
            new_x1 = new_x1 + width - 1;

            int value = 0;
            for (int c=0; c<3; c++)
            {
                 out_img[new_x2*width*channels + new_x1*channels + c] = img[x2*width*channels + x1*channels + c];
            }

        }
    }


    // save image
    stbi_write_png("nature_color_hflip.png", width, height, channels, out_img, width*channels);

    stbi_image_free(img);
    stbi_image_free(out_img);
}

int main_99() {
    int data[2][3][4];

    int count = 0;
    for (int i=0; i<2; i++)
    {
        for (int j=0; j<3; j++)
        {
            for (int k=0; k<4; k++)
            {
                data[i][j][k] = count;
                count++;
            }
        }
    }

    // print
    for (int i=0; i<2; i++)
    {
        for (int j=0; j<3; j++)
        {
            for (int k=0; k<4; k++)
            {
                printf("%d ", data[i][j][k]);
            }
            printf("\n");
        }
        printf("\n\n");
    }
}

int main532() {
    int data[2][3][4];

    int count = 0;
    for (int i=0; i<2; i++)
    {
        for (int j=0; j<3; j++)
        {
            for (int k=0; k<4; k++)
            {
                data[i][j][k] = count;
                count++;
            }
        }
    }

    // print
    int* ptr = data;

    int height = 2;
    int width = 3;
    int channels = 4;
    for (int i=0; i<height; i++)
    {
        for (int j=0; j<width; j++)
        {
            for (int k=0; k<channels; k++)
            {
                printf("%d ", ptr[i*height*channels + j*channels + k]);
            }
            printf("\n");
        }
        printf("\n\n");
    }
}