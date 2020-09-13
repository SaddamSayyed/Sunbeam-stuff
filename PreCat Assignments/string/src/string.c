/*
 ============================================================================
 Name        : string.c
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
	char str1[20] = "sting 1 and ";//this is stricmp
	char str2[20] = "string 2";int n;
	/*int n;
	n = strcmp(str1, str2);*/
	n = strcpy(str2,str1);
	/*if( n == 0)
	printf("The strings str1 and str2 are same ");
	else if(n == -1)
	printf("The string str1 is lesser than str2");
	else
	printf("The string str1 is greater than str2");
	printf("\n n=%d\n",n);*/printf("\n n=%d\n",n);
	puts(str1);
	puts(str2);
	return 0;
}
