/*
 ============================================================================
 Name        : asgn3_10.c
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
	int a,i,t=1;
	printf("please enter the number : \n");
	scanf("%d",&a);
	for(i=1;i<=10;i++)
	{
		t=i*a;
		printf("%d \n",t);
	}
	return EXIT_SUCCESS;
}
