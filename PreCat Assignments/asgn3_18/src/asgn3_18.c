/*
 ============================================================================
 Name        : asgn3_18.c
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
	int i,j,n;
	for(i=1;i<=10;i++)
	{
		for(j=1;j<=10;j++)
		{
			n=i*j;
			printf("%d ",n);
		}
		printf("\n");
	}
	return EXIT_SUCCESS;
}
