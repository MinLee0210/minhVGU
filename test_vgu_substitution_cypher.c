#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

/*
    a[]: is the alphabet.
    b[]: hold index to shuffle the substitution array, this array make sure that there is no duplicate 
        in the random array. 
    c[]: is the substitution alphabet.
*/
int shuffle_index(int b[], int n){
    for(int i = 0; i < n; i ++){
        int temp = b[i]; 
        int randIndex = rand()%n; 
        //swap values inside the array randomly
        b[i] = b[randIndex]; 
        b[randIndex] = temp; 
    }
}

int main()
{
    char plaintext[125], enc_text[125], dec_text[125];  
    char a[26], c[26], e;  
    int b[26]; 

    printf("Please input the plaintext: "); 
    scanf("%s", &plaintext); 

    printf("\nPlease choose e for encrypt or d for decrypt:");
    scanf("%s", &e);

    printf("\n");
    //making the alphabet
    for(int i = 0; i < 26; i ++){
        a[i] = 97 + i;  
        b[i] = i; 
    }
    //shuffle the index
    shuffle_index(b, 26); 
    //making the substitution alphabet
    for(int i = 0; i < 26; i++){
       c[i] = 97 + b[i];  
    }

    if(e == 'e'){
        for(int i  = 0; i < strlen(plaintext); i ++){
            for(int j = 0; j < 26; j ++){
                if(plaintext[i] == a[j])    enc_text[i] = c[j];                 
            } 
            printf("%c", enc_text[i]);
        }
    }else if(e == 'd')
    {
        for(int i  = 0; i < strlen(plaintext); i ++){
            for(int j = 0; j < 26; j ++){
                if(plaintext[i] == c[j])    dec_text[i] = a[j];                 
            } 
            printf("%c", dec_text[i]);
        }
    }else{
        printf("\nPlease try again!!");
    }
    return 0; 
}