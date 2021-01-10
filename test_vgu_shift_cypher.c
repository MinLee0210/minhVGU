#include <stdio.h>
#include <string.h>

//SHIFT CIPHER

int main()
{  
    char e; 
    char plain_text[10],  encrypt_text[10],  decrypt_text[10]; 
    int k; 
    
    printf("Please input the plaintext: "); 
    scanf("%s", &plain_text); 

    printf("\nPlease choose e for encrypt or d for decrypt:");
    scanf("%s", &e);  

    printf("\nPlease input a key: ");
    scanf("%d", &k);  

    printf("\n"); 

    if(e == 'e'){
        for(int i = 0; i < strlen(plain_text); i ++){
            encrypt_text[i] = (int)(plain_text[i] + k - 97)%26 + 97; 
            printf("%c", encrypt_text[i]);
         }
    }else if (e == 'd'){
        for(int i = 0; i < strlen(encrypt_text); i ++){
            decrypt_text[i] = (int)(encrypt_text[i] - k - 97)%26 + 97; 
            printf("%c", decrypt_text[i]);
        }  
    }else{
        printf("\nPlease enter your choice!!"); 
    }
    return 0; 
}

 