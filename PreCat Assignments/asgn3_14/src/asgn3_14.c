/*
 ============================================================================
 Name        : asgn3_14.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
int check_prime(int);

int main(void)
{
	int a,i;
	printf("please enter the number to be checked as prime or not : \n");
	scanf("%d",&a);
	i=check_prime(a);
	if(i==1)
		printf("given number is prime");
	else
		printf("given number is not prime");
	return EXIT_SUCCESS;
}

int check_prime(int a)
{
	int i,p=1;
	if(a==2)
		return 1;
	for(i=2;i<a;++i)
		{
			if(a%i==0)
				p=0;
		}
	return p;
}
