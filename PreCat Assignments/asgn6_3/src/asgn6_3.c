/*
 ============================================================================
 Name        : asgn6_3.c
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
	char str[20]=("!!!Hello World!!!"); /* prints !!!Hello World!!! */
	char c='l';
	char r[20];
	int j,i=0;
	for(j=0;j<20;j++)
	{
		if(str[j]!=c)
		{
			r[i]=str[j];++i;
		}
	}
	puts(str);
	puts(r);
	return EXIT_SUCCESS;
}
