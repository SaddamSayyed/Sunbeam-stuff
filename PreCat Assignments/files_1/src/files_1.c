/*
 ============================================================================
 Name        : files_1.c
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
	FILE* f;
	int counter=0;
	char data[20];
	f=fopen("abc.txt","r");
	if(f==NULL)
	{
		printf("Unable to Open the file.\n");
	}
	else
	{
		printf("file is opened in read mode.\n");
		while((data[counter]=fgetc(f))!=EOF)
		{
			printf("%c",data[counter]);
			counter++;
		}
		fclose(f);
	}
	return EXIT_SUCCESS;
}
