/*
 ============================================================================
 Name        : asgn3_3.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
int digit_add (int);
int reverse(int);
void palindrome (int,int);
void armstrong(int);
int main(void)
{
	int x,sum=0,x1,rev;
	printf("Please enter the number\n");
	scanf("%d",&x);
	x1=x;
	//x2=x1;
	sum =digit_add(x1);
	printf(" = %d\n",sum);
	rev = reverse(x1);
	printf("the given number in reverse is : %d",rev);
	palindrome(rev,x);
	armstrong(x);
	return EXIT_SUCCESS;
}

int digit_add (int x)
{
	int r,sum=0;
	while(x!=0)
		{
			r=x%10;
			sum=sum+r;
			x=x/10;
			printf("%d ",r);
			if(x!=0)
				printf("+ ");

		}
	return sum;
}

int reverse(int x)
{
	int r,rev=0;
while(x!=0)
		{
			r=x%10;
			x=x/10;
			rev=rev*10+r;

		}
	return rev;
}

void palindrome (int a,int b)
{
	if(a==b)
		printf("\nthe given number is a palindrome\n");
	if(a!=b)
		printf("\nthe given number is not a palindrome\n");
}

void armstrong(int x)
{
	int r,c=0,sum=0,x1=x;
		while(x!=0)
			{
				r=x%10;
				c=r*r*r;
				sum=sum+c;
				x=x/10;
				printf("(%d * %d * %d)  ",r,r,r);
				if(x!=0)
					printf("+ ");

			}
		printf("= %d",sum);
		if(sum==x1)
			printf("\n hense the given number is an armstrong number.\n");
		else
			printf("\n hense the given number is not an armstrong number.\n");

}
