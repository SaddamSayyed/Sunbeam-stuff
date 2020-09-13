/*
 ============================================================================
 Name        : asgn3_2.c
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
	int a,b,i=1;
	printf("plz enter the number : ");
	scanf("%d",&a);
	while(i<=10)
	{
		printf(" %d * %d = %d \n",a,i,a*i);
		i++;
	}
	return EXIT_SUCCESS;
}
