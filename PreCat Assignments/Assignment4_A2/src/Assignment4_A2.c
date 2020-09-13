/*
 ============================================================================
 Name        : Assignment4_b2.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : calculate power
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
long int power(int a,int n)
{
	int i;
	long int ans=1;
	for(i=1;i<=n;i++)
	{
		ans=ans*a;
	}
		return ans;
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
