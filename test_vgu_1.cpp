#include <bits/stdc++.h>
#include <stdio.h>

int main()
{
    #ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif
    
    const int n = 3; 
    const int m = 3; 
    const int k = 3; 

    int data[m][n] = {{1, 2, 3}, 
                      {4, 5, 6},
                      {7, 8, 9}}; 
    int doto[n][k] = {{3, 5, 7},
                      {4, 6, 8}, 
                      {5, 7, 9}};  
    int a[n][k] = {0};
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++) { 
            for(int z = 0; z < k; z++){
                a[i][j] += data[i][z]*doto[z][j]; 
            }         
        }
    for(int i = 0; i < n; i++){
        for(int k =0; k < n; k++){
            printf("%d ", a[i][k]);
        }
        printf("\n"); 
    }
    }
    return 0; 
}