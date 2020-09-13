/*
 ============================================================================
 Name        : binary_conversion.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
void binary(int a)
{
	int q;
		q=a%2;
		a=a/2;
	if(a!=0)
		binary(a);
	printf("%d",q);
}
int main(void)
{
	int a;
	printf("Enter the number to to converted in binary");
	scanf("%d",&a);
	binary(a);
	return EXIT_SUCCESS;
}
