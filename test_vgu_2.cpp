#include <bits/stdc++.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    #ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif

    srand((unsigned)time(NULL));

    int n = 9;
    int a[n][n];  
    for(int i = 0; i < n; i ++ ){
        for(int j = 0; j < n + 5; j ++){
            a[i][j] = (int)rand()%10; 
        }
    }

    for(int i = 0; i < n; i ++){
        for(int j = 0; j < n + 5; j ++){
            printf("%d ", a[i][j]);
        }
        printf("\n"); 
    }

    return 0; 
}