/*
 ============================================================================
 Name        : asgn6_a1.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include<string.h>
int main()
{
	char str1[20] = "this is stricmp";
	char str2[20] = "THIS IS STRICMP";
	int n;
	char i = stricmp(str1, str2);
	if( n == 0)
	printf("The strings str1 and str2 are same ");
	else if(n == -1)
	printf("The string str1 is lesser than str2");
	else
	printf("The string str1 is greater than str2");
	return 0;
}
