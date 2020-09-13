/*
 ============================================================================
 Name        : asgn3_20.c
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
	int i,p;
	for(i=1;i<=100;i++)
	{
		p=check_prime(i);
		if(p==1)
			printf("%d ,",i);
	}
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
