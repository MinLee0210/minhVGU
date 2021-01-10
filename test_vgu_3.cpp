#include<bits/stdc++.h>
#include<stdio.h>
#include<time.h>

#define N 6

int main(){

    #ifndef ONLIINE_JUGDE
    freopen("output.txt", "w", stdout); 
    #endif

    int a;
    int n = 2; 
    int m = 3;

    int b[n][m], c[m][n]; 
    int d[n][n] = {0}; 
    int e[m][m] = {0}; 

    int data[N];

    srand((unsigned)time(NULL)); 

    for(int i = 0; i < N; i++){;
        data[i] = rand()%10;
        printf("%d ", data[i]); 
    } 

    int k = 0; 
//value's b[][] get from data
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            b[i][j] = data[k];
            k++; 

        } 
    }
//value's c[][] get from b[][]
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            c[i][j] = b[j][i];
            k++; 
        } 
    }

    printf("\n\n"); 
//matrix 1
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            printf("%d ", b[i][j]); 
        } 
        printf("\n"); 
    }

    printf("\n"); 
//matrix 2
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            printf("%d ", c[i][j]); 
        } 
        printf("\n"); 
    }

    printf("\n"); 
    
    return 0; 
}