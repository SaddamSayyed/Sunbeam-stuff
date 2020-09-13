/*
 ============================================================================
 Name        : GCD_using_recursion.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
int gcd(int n1,int n2)
{
	int i=1, small;
	if(n1==n2)
		return n1;
	if(n1<n2)
	{
		small=n1;
		if(n2%n1==0)
			return n1;

	}
	else
	{
		small=n2;
		if(n1%n2==0)
			return n2;
	}
	for(i=small-1;i>0;i--)
	{
		if(n2%i==0 && n1%i==0)
			return i;

	}
}
/*int gcd_recursion(int n1,int n2)
{
	if(n2!=0)
		return gcd_recursion(n2,n1%n2);
	else
		return n1;

}*/
int main(void)
{
	int n1,n2;
	printf("Please enter N1 and N2\n");
	scanf("%d %d",&n1,&n2);
	printf("the GCD of given numbers is %d",gcd(n1,n2));
	//printf("Using Recursion");
	//printf("the GCD of given numbers is %d",gcd_recursion(n1,n2));

	return EXIT_SUCCESS;
}
