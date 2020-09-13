/*
 ============================================================================
 Name        : asgn3_13.c
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
	int n,s;
	printf("please enter n :");
	scanf("%d",&n);
	fibonacci(n);
	return EXIT_SUCCESS;
}

void fibonacci(int n)
{
	int i,s,s1=0,s2=1;
	for(i=1;i<=n;++i)
	{
		s=s1+s2;
		if(i==1)
		{
			printf("1 , ");
			continue;
		}
		printf("%d ",s);
		if(i!=n)
		printf(", ");
		s1=s2;
		s2=s;

	}
}
