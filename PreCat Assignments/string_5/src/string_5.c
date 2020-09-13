/*
 ============================================================================
 Name        : string_5.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int convert_atoi(char *s);
int check_if_valid(char *s);
int main(void)
{
	char s[10];
	printf("Please enter the numeric string that has to be converted to its numeric value\n");
	scanf("%[^\n]s",s);
	int a=check_if_valid(s);
	if(a==0)
	{
		printf("\nthe entered string has non numeric characters\n");
		return EXIT_SUCCESS;
	}
	int n=convert_atoi(s);
	printf("\nthe numeric value of %s :: %d\n",s,n);
	return EXIT_SUCCESS;
}
int check_if_valid(char *s)
{
	for(int i=0;s[i]!=NULL;i++)
	{
		if(!(s[i] >'0'&&s[i]<'9'))
			return 0;
	}
	printf("\nthe lenght of string is :: %d\n",strlen(s));
	return 1;
}
int convert_atoi(char *s)
{
	int n,i,r=0;
	n=strlen(s);
	for(i=0;i<n;++i)
	{
		r=r*10+(s[i]-'0');
	}
	return r;
}
