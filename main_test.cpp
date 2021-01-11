#include <bits/stdc++.h>
#include <stdio.h>
#include <string.h>

int main()
{  

    #ifndef ONLINE_JUDGE
    freopen("output.txt", "w", stdout);
    #endif

    char c[] = "hphtwwxppelextoytrse"; 
    char b[strlen(c)]; 
    for(int i = 0; i < strlen(c); i ++){
        b[i] = char(int(c[i] - 11 -65 )%26 + 65); 
        printf("%c", b[i]); 
    }
    //hh
    return 0; 
}