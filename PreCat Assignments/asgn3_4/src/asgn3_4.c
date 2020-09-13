/*
 ============================================================================
 Name        : asgn3_4.c
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
	int a,f=1,i;
	printf("please enter the number :");
	scanf("%d",&a);
	i=a;
	while(i<=a)
	{
		if(i==0)
			break;
		f=i*a;
		printf("%d ",i);
		if(i!=1)
		printf("*");
		i--;
	}
	printf(" = %d",f);
	return EXIT_SUCCESS;
}
