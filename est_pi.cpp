#include <bits/stdc++.h>
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>

#define a 1

float length(float x, float y)
{
    return (double)sqrt(pow(x, 2) + pow(y, 2)); 
}


int main()
{   
    #ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif

    int n = 1000000; 
    float x, y; 
    srand((unsigned)time(NULL)); 

    float l; 
    float i = 0; 
    float j = 0;     
    
    for(int z = 0; z < n; z++)
    {
        float x = (float)rand()/RAND_MAX*2.0 - 1.0;
        float y = (float)rand()/RAND_MAX*2.0 - 1.0;
        l = length(x, y);
        //printf("(%f, %f)  %.5f\n", x, y, l); 


        if(l < a)
        {
            i ++ ; 
            j ++ ; 
        }
        else   
        {
            j++;
        }

    } 
    float P = 4.0 * i/(j);
    printf("%.5f", P);    
    return 0; 
}