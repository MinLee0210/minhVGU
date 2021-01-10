#include <stdio.h>
#include <string.h>

int inverse(int a, int b){
        a = a % b; 
    for (int x = 1; x < b; x++) 
        if ((a * x) % b == 1) 
            a = x; 
            return a;
}

int main(){

    char e; 
    char plain_text[10],  encrypt_text[10],  decrypt_text[10]; 
    int a, b; 
    
    printf("Please input the plaintext: "); 
    scanf("%s", &plain_text); 

    printf("\nPlease choose e for encrypt or d for decrypt:");
    scanf("%s", &e);  

    printf("\nPlease input coefficients: \n");
    scanf("%d%d", &a, &b);  

    printf("\n"); 

    if(e == 'e'){
        //encrypt enc[i] = a*(int)plain[i] + b
        for(int i = 0; i < strlen(plain_text); i ++){
            encrypt_text[i] = (a*(int)(plain_text[i] - 97) + b )%26 + 97; 
            printf("%c", encrypt_text[i]);
         }
    }else if (e == 'd'){
        //decypt dec[i] = inverse(a)*((int)plain[i] -b)
        for(int i = 0; i < strlen(encrypt_text); i ++){
            decrypt_text[i] = inverse(a, 26)*((int)(plain_text[i] - 97) - b )%26 + 97; 
            printf("%c", decrypt_text[i]);
        }  
    }else{
        printf("\nPlease enter your choice!!"); 
    }
    return 0; 
}
