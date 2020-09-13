/*
 ============================================================================
 Name        : files_3.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void read_file(FILE *f)
{
	f=fopen("abc.txt","r");
	if(f==NULL)
		{
			printf("\nUnable to open the file\n");
		}
	else
		{
			char string[30];
			fscanf(f,"%[^\n]",string);
			puts(string);
		}
	fclose(f);
}
int main(void)
{
	FILE *f1,*f2;
	read_file(f1);
	//copy_file(f1,f2);
	return EXIT_SUCCESS;
}
