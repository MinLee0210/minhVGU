#include <stdio.h>
#include <string.h>

int main(){
    char data_line[] = "5.2, 4. 5"; 

    char * token = strtok(data_line, ","); 

    while(token != NULL){
        printf("%s\n", token); 
        token = strtok(NULL, ","); 
    } 
    return 0;
}