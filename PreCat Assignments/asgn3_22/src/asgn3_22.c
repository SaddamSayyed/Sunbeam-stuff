/*
 ============================================================================
 Name        : asgn3_22.c
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
	int i,j;
	/*for(i=1;i<=5;i++)//first pattern
	{
		for(j=1;j<=i;j++)
		{
			printf("* ");

		}
		printf("\n");
	}*/
	/*for(i=5;i>=0;--i) //second pattern
		{
			for(j=i;j>0;j--)
			{
				printf("* ");

			}
			printf("\n");
		}*/
	/*for(i=1;i<=5;i++) //third pattern
			{
				for(j=1;j<=i;j++)
				{
					printf("%d ",j);

				}
				printf("\n");
			}*/
	for(i=5;i>0;i--) //forth pattern
	{
		for(j=i;j>0;j--)
		{
			printf("%d ",j);

		}
		printf("\n");
	}
	return EXIT_SUCCESS;
}
