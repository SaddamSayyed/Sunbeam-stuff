#include <stdio.h>
#include <stdlib.h>
int main() 
{ 
    int n, i,j, flag = 0, *a = NULL;
    printf("\nPlease enter size of the array : ");
    int size = 0 ; scanf("%d",&size);
    a = (int *) malloc( size * sizeof( int ) ) ; 
    printf("Enter %d positive integers : ", size);  
    for( i = 0 ; i < size ; i ++ )
        scanf("%d", &a[i]);
    for( j = 0 ; j < size ; j ++ )
    {
        for (i = 2; i <= a[j] / 2; ++i) 
        { // condition for non-prime 
            if (a[j] % i == 0) 
            { 
                flag = 1; break; 
            } 
        }
        if (a[j] == 1) 
        { 
            printf("1 is neither prime nor composite.\n"); 
        }
        else 
        { 
            if (flag == 0) 
                printf("%d is a prime number.\n", a[j]);
            else 
                printf("%d is not a prime number.\n", a[j]); 
        } 
        flag = 0 ;
    }
    
    return 0; 
}