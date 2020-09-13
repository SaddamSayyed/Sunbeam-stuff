/*
 ============================================================================
 Name        : Assignment4_B1.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : calculate factorial using recursion
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
long int fact(int a)
{
	if(a>=1)//terminating condition
		return a*fact(a-1);//function calling itself
	else
		return 1;
}
int main(void)
{
	int a; short int b; long int f;
	do
	{
		again : printf("choose one of the options :\n1. To find factorial\n2.exit\n");
		scanf("%hi",&b);

		switch(b)
		{
			case 1:
					printf("PLease enter the number whose factorial you want ::");
					scanf("%d",&a);
					printf("the factorial of %d = %ld",a,f=fact(a));
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
