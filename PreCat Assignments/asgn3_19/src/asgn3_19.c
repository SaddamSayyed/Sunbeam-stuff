/*
 ============================================================================
 Name        : asgn3_19.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int i,j,n,a,b;
	printf("please enter the range \n");
	scanf("%d %d",&a,&b);
		for(i=a;i<=10;i++)
		{
			for(j=a;j<=b;j++)
			{
				n=i*j;
				printf("%d ",n);
			}
			printf("\n");
		}

	return EXIT_SUCCESS;
}
