/*
 ============================================================================
 Name        : files_2.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void accept_data(FILE *source)
{
	source =fopen("source.txt","w");
	char data[20];
	int counter=0;
	if(source==NULL)
		printf("Unable to Open the file.\n");
	else
		{
			printf("file is opened in read mode.\nPlz enter the string to be copied into destination file\n");
			scanf("%[^\n]s",data);
			for(counter=0;counter<strlen(data);counter++)
				{
					fputc(data[counter],source);
				}
			fclose(source);
		}
}
void display_data(FILE *destination)
{
	destination =fopen("destination.txt","r");
	char data[20];
	int counter=0;
	if(destination==NULL)
		printf("Unable to Open the file.\n");
	else
		{
			printf("\nThe Data in Destination file is :\n");
			while((data[counter]=fgetc(destination))!=EOF)
				{
					printf("%c",data[counter]);
					counter++;
				}
		}
	fclose(destination);
}
void copy_data(FILE *source,FILE *destination)
{
	source =fopen("source.txt","r");
	char data[20];
	int counter=0;
	if(source==NULL)
		printf("Unable to Open the file.\n");
	else
		{
			while((data[counter]=fgetc(source))!=EOF)
			{
				printf("%c",data[counter]);
				counter++;
			}
			printf("\nAbove Data is copied\n");
		}
	fclose(source);

	destination =fopen("destination.txt","w");
	if(source==NULL)
		printf("Unable to Open the file.\n");
	else
		{
		for(counter=0;counter<strlen(data);counter++)
			{
				fputc(data[counter],destination);
			}
		}
	fclose(destination);
}
int main(void)
{
	FILE* source,*destination;
	accept_data(source);
	copy_data(source,destination);
	display_data(destination);
	return EXIT_SUCCESS;
}
