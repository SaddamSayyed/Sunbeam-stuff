/*
 ============================================================================
 Name        : asgn3_1.c
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
	printf("plz enter the character : ");
	scanf("%c",&a);
	printf("how many times you want to print it ? \n");
	scanf("%d",&b);
	while(i<=b)
	{
		printf("%c ",a);
		i++;
	}
	return EXIT_SUCCESS;
}
