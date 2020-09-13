/*
 ============================================================================
 Name        : asgn3_9.c
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
	int a,b,i=1,gcd;
	printf("enter the two numbers: \n");
	scanf("%d %d",&a,&b);
	while(i<=a && i<=b)
	{
		if(a%i==0 && b%i==0)
			gcd=i;
		++i;
	}
	printf("GCD : %d",gcd);


	return EXIT_SUCCESS;
}
