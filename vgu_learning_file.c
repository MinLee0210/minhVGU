#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    FILE *from, *to; 
    char line; 

    from = fopen("input.txt", "r"); 

    to = fopen("output.txt", "w"); 

    line = fgetc(from); 
    while(line != EOF){
        fputc(line, to); 
        line = fgetc(from); 
    }

    fclose(from); 
    fclose(to); 

    return 0; 
}