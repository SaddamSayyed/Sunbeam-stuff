/*
 ============================================================================
 Name        : assignment4_B2.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : calculate power using recursion
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
long int power(long int a,int n)
{
	if(n>1)
		return a*power(a,n-1);
	else
		return a;
}
int main(void)
{
	int a; int b;
	short int i;
	do
	{
		again : printf("choose one of the options :\n1.To find power\n2.exit\n");
		scanf("%hi",&i);

		switch(i)
		{
			case 1:
					printf("PLease enter the base ::");
					scanf("%d",&a);
					printf("Please enter the power ::");
					scanf("%d",&b);
					printf("the answer is %ld\n",power(a,b));
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
