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
	char str1[20]="school";
	int count=0;
	int i=0;
	do
	{
		if(str1[i]=='o')
		{
			count++; 
			shift(str1,i);

		}
	}while(str1[i]!=NULL);
	printf("\n the string after the removal of the character %c is %s",'o',str1);
	return EXIT_SUCCESS;
}
void shift(char *p,int i)
{
	do
	{
		*(p)=*(p+1);
	}while(*(p+1)!=NULL);
}
