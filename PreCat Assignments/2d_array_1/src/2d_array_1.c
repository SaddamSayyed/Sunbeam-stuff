/*
 ============================================================================
 Name        : 2d_array_1.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
void accept_2d(int arr[][3],int r,int c);
void display_2d(int arr[][3],int r,int c);
int main(void)
{
	int arr[2][3];
	accept_2d(arr,2,3);
	display_2d(arr,2,3);
	return EXIT_SUCCESS;
}
void accept_2d(int arr[][3],int r,int c)
{
	int i,j;
	for(i=0;i<r;i++)
	{
		printf("\nrow %d\n ",i+1);
		for(j=0;j<c;j++)
		{
			scanf("%d",&arr[i][j]);
		}
	}

}
void display_2d(int (*arr)[3],int r,int c)
{
	int i,j;
	for(i=0;i<r;i++)
		{
			printf("\nrow %d\n ",i+1);
			for(j=0;j<c;j++)
			{
				printf("%6d",arr[i][j]);
			}
		}
}
