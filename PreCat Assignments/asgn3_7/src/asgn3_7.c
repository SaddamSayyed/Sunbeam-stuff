/*
 ============================================================================
 Name        : asgn3_7.c
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
	int a,a2,i;
	printf("enter the number : ");
	scanf("%d",&a);
	a2=1;
	while(a2<=a)
	{
		i=1;
		while(i<=a)
		{
			if(i*a2==a)
			{
				printf("\n%d * %d = %d",i,a2,a);

			}
				++i;

		}

		++a2;
	}
	return EXIT_SUCCESS;
}
