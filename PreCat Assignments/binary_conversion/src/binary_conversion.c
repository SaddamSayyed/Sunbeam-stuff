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
	int q,i=0;
	int arr[20];
	do
	{
		q=a%2;
		a=a/2;
		arr[i]=q;
		i++;
	}while(a!=0);
	--i;
	while(i>=0)
	{
		printf("%d",arr[i]);
		i--;
	}
}
int main(void)
{
	int a;
	printf("Enter the number to to converted in binary");
	scanf("%d",&a);
	binary(a);
	return EXIT_SUCCESS;
}
