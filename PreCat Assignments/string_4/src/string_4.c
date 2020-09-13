/*
 ============================================================================
 Name        : string_4.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
void shift(char str[],int i);
int main(void)
{
	char s1[30]="s*unbe(am hin?jew!adi,@ pu&ne.";
	char s2[20]="*(?!@&";
	int n1,n2;
	n1=strlen(s1);
	n2=strlen(s2);
	printf("string lenght s1 = %d\nstring lenght s2 = %d\n",n1,n2);
	char temp;
	int j,i,count=0;
	for(j=0;j<n2;j++)
	{
		temp=s2[j];
		for(i=0;i<n1;i++)
		{
			if(s1[i]==temp)
			{
				count++;
				printf("after iteration no %d :",count);
				shift(s1,i);
				i=-1;
			}

		}
	}
	printf("\nthe strings after the operation are :\nS1 = %s\nS2 = %s",s1,s2);
	return EXIT_SUCCESS;
}
void shift(char str[],int i)
{
	while((str[i]!=NULL))
	{
		str[i]=str[i+1];
		i++;
	}
	printf("%s\n",str);
}
