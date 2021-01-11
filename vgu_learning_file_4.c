#include <stdio.h>
#include <stdlib.h>

void copy_content (char* source_file, char* des_file)
{
    char ch; 
    FILE *source, *target; 

    source = fopen(source_file, "r"); 
    if(source == NULL)
    {
        printf("Press any key to exit ... \n"); 
        exit(EXIT_FAILURE); 
    }

    target = fopen(des_file, "w"); 
    if(target == NULL)
    {
        fclose(source); 
        printf("Press any key to exit ... \n"); 
        exit(EXIT_FAILURE);        
    }

    while( (ch = fgetc(source)) != EOF)
        fputc(ch, target); 

    printf("Filed copy succesfully.\n"); 

    fclose(source); 
    fclose(target); 

}

int main()
{
    copy_content("input.txt", "output.txt"); 
    return 0; 
}