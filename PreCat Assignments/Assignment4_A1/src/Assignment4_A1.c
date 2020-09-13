/*
 ============================================================================
 Name        : Assignment4_A1.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : factorial of a number
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
int fact(int a)
{
	int t=a;
	for(int i=1;i<t;i++)
	{
		a=a*i;
	}
	return a;
}
int main(void)
{
	int a,f,b;
	do
	{
		again : printf("choose one of the options :\n1. To find factorial\n2.exit\n");
		scanf("%d",&b);

		switch(b)
		{
			case 1:
					printf("PLease enter the number whose factorial you want ::");
					scanf("%d",&a);
					f=fact(a);
					printf("the factorial of %d = %d\n",a,f);
					break;
			case 2:
					printf("Thanks,bye bye!");
					return 0;
			default:
					printf("Please enter the valid choice.\n");
					goto again;

		}


	}while(b);
		return EXIT_SUCCESS;
}
