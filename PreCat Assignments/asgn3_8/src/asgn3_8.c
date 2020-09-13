/*
 ============================================================================
 Name        : asgn3_8.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
int check_prime(int);

void prime(int);

int main(void)
{
	int a,i,r;
		printf("please enter the number:\n");
		scanf("%d",&a);
		printf("180 = ");
		for(i=1;a%i==0;++i)
		{
			r=check_prime(i);
			if(r==1)
				printf("%d * ",i);
		}

	return EXIT_SUCCESS;
}

int check_prime(int a)
{
	int c;
	if(a==2)
		return 1;
	for(c=2;c<a;c++)
	{
		if(a%c==0)
			return 0;
		else
			return 1;
	}
}
