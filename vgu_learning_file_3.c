#include<stdio.h>
#include<string.h>

int main()
{
    FILE *file; 
    char line[100]; 

    file = fopen("input.txt", "r"); 

    if(file == NULL){
        printf("ERROR!!!"); 
        exit(1); 
    }

    fscanf(file, "%[^\n]\n", line); 

    float area, price; 

    while(EOF != fscanf(file, "%[^\n]\n", line)){
        char *area_str = strtok(line, ","); 
        char *price_str = strtok(NULL, ","); 

        sscanf(area_str, "%f", &area); 
        sscanf(price_str, "%f", &price);

        printf("area %f  -   price %f \n", area, price); 
    }

    fclose(file); 

    return 0; 
}