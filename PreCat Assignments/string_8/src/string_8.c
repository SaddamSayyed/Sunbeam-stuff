/*
 ============================================================================
 Name        : string_8.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
int check_if_valid(char *s);
int main(void)
{
	int s[10];
	int i=0;
	printf("please enter the numeric characters to be printed as words\n");
	scanf("%[^\n]s",s);
	int a=check_if_valid(s);
	if(a==0)
	{
		printf("\nthe entered string has non numeric characters\n");
		return EXIT_SUCCESS;
	}
	inwords(s,i);

	return EXIT_SUCCESS;
}
void inwords(char s[],i)
{
	int r=s[i]%10;

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
