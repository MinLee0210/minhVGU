int main(void) {
    int width, height, channels;

    // read image
    unsigned char *img = stbi_load("nafosted_gray.png", &width, &height, &channels, 0);
    if(img == NULL) {
        printf("Error in loading the image\n");
        exit(1);
    }
    printf("Loaded image with a width of %dpx, a height of %dpx and %d channels\n", width, height, channels);

    // copy
    unsigned int img_size = width * height * channels;
    unsigned char* out_img = malloc(img_size);

    for (int i=0; i<height; i++)
    {
        for (int j=0; j<width; j++)
        {
            out_img[i*width + j] = img[i*width + j];
        }
    }


    // save image
    stbi_write_png("nafosted_gray_copy.png", width, height, channels, out_img, width*channels);

    stbi_image_free(img);
    stbi_image_free(out_img);
}
