/*
 ============================================================================
 Name        : asgn6_4.c
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
	char str[]={"xaybzcd"}; /* prints !!!Hello World!!! */
	char str2[]={"abcd"};
	char r[10];
	int j,i,k=0,count=0;
	printf("str=%d\n",strlen(str));
	printf("str2=%d\n",strlen(str2));
	for(j=0;j<strlen(str);j++)
	{
		for(i=0;i<strlen(str2)-1;i++)
		{
			if(str[j]==str2[i])
			{
				count++;
			}
		}
		if (count==0)
			{
				r[k]=str[j];
				k++;
			}


	}
	puts(str);
	puts(r);
	puts(str2);
	return EXIT_SUCCESS;
}
