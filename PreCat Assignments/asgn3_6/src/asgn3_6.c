/*
 ============================================================================
 Name        : asgn3_6.c
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
	int a,i=1,r;
	printf("please enter the number:");
	scanf("%d",&a);
	printf("the factors of the given number are : ");
	while(i<a)
	{
		r = a%i;

		if(r==0)
		printf("%d ",i);
		i++;
	}

		return EXIT_SUCCESS;
}
