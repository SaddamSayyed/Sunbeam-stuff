/*
 ============================================================================
 Name        : string_3.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : removal of a character from string
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
void shift(char *p,int i);
int main(void)
{
	char str1[20];
	printf("plz enter the string(up to 20 characters)\n");
	fgets(str1,20,stdin);
	int count=0;
	int i=0;
	char temp;
	printf("please enter the character to be removed from the given string");
	scanf("%c",&temp);
	while(str1[i]!=NULL)
	{
		if(str1[i]==temp)
		{
			count++;
			shift(str1,i);
			i=i-count;
		}
		i++;
	}
	printf("\n the string after the removal of the character %c is %s",temp,str1);
	printf("\n the occurrence of character %c has been %d times",temp,count);
	return EXIT_SUCCESS;
}
void shift(char str[],int i)
{
	while((str[i]!=NULL))
	{
		str[i]=str[i+1];
		i++;
	}
}
