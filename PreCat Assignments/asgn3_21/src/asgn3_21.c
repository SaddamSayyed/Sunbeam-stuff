/*
 ============================================================================
 Name        : asgn3_21.c
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
	int a,b,j=1,i;
	printf("please enter the number from which the further 5 prime numbers are to be printed\n");
	scanf("%d",&a);
	for(i=a;j<=5;i++)
	{
		b=check_prime(i);
		if(b==1 && j<=5)
		{
			printf("%d ,",i);
			++j;
		}
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
