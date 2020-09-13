/*
 ============================================================================
 Name        : 2d_array_3.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#define R 2
#define C 2
void accept_2d(int arr[][C],int r,int c);
void display_2d(int arr[][C],int r,int c);
int add_row(int arr1[][C],int r,int c,int);
int main(void)
{
	int arr1[R][C];
	accept_2d(arr1,R,C);
	display_2d(arr1,R,C);
	printf("\nplease specify the row ,whose row elements to be added\n");
	int a;
	scanf("%d",&a);
	printf("the sum of the elements of row no %d :: %d",a,add_row(arr1,R,C,a-1));

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
int add_row(int arr[][C],int r,int c,int a)
{
	int i,sum=0;
	for(i=0;i<c;++i)
		sum=sum+arr[a][i];
	return sum;
}








