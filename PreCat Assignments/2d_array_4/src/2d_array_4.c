/*
 ============================================================================
 Name        : 2d_array_4.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#define R 5
#define C 20
void accept_2d(char arr[][C],int r,int c);
void display_2d(char arr[][C],int r,int c);
int main(void)
{
	char arr1[R][C];
	accept_2d(arr1,R,C);
	display_2d(arr1,R,C);

	return EXIT_SUCCESS;
}
void accept_2d(char arr[][C],int r,int c)
{
	int i;
	printf("enter the name of 5 students\n");
	for(i=0;i<r;i++)
	{
		fgets(arr[i],20,stdin);
	}

}
void display_2d(char (*arr)[C],int r,int c)
{
	int i;
	printf("\nThe names of the students are ::\n");
	for(i=0;i<r;i++)
		{
			printf("%10s\n",arr[i]);
		}
}
