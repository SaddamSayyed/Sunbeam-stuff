/*
 ============================================================================
 Name        : 2d_array_2.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#define R 3
#define C 3
void accept_2d(int arr[][C],int r,int c);
void display_2d(int arr[][C],int r,int c);
void add(int arr1[][C],int arr2[][C],int result[][C],int r,int c);
void sub(int arr1[][C],int arr2[][C],int result[][C],int r,int c);

int main(void)
{
	int arr1[R][C];
	accept_2d(arr1,R,C);
	display_2d(arr1,R,C);
	int arr2[R][C],result[R][C];
	accept_2d(arr2,R,C);
	display_2d(arr2,R,C);
	add(arr1,arr2,result,R,C);
	printf("\n the addition :");
	display_2d(result,R,C);
	sub(arr1,arr2,result,R,C);
	printf("\n the addition :");
	display_2d(result,R,C);

	return EXIT_SUCCESS;
}
void accept_2d(int arr[][C],int r,int c)
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
void display_2d(int (*arr)[C],int r,int c)
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
void add(int arr1[][C],int arr2[][C],int result[][C],int r,int c)
{
	int i,j;
	for(i=0;i<r;i++)
		{
			for(j=0;j<c;j++)
			{
				result[i][j]=arr1[i][j]+arr2[i][j];
			}
		}

}
void sub(int arr1[][C],int arr2[][C],int result[][C],int r,int c)
{
	int i,j;
	for(i=0;i<r;i++)
		{
			for(j=0;j<c;j++)
			{
				result[i][j]=arr1[i][j]-arr2[i][j];
			}
		}

}
