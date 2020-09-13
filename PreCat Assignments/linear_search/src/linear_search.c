/*
 ============================================================================
 Name        : linear_search.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#define SIZE 10
int search(int *a,int n,int data);
int main(void)
{	int a[]={5,9,17,23,25,45,59,63,71,89};
	int data,i;
	printf("Enter the number to be found\n");
	scanf("%d",&data);
	i=search(a,SIZE,data);
	if(i==-1)
		printf("Data not found in the array\n");
	else
		printf("%d is at the index position %d int the array\n",data,i);
	return EXIT_SUCCESS;
}
int search(int *a,int n,int data)
{
	int i;
	for(i=0;i<n;i++)
	{
		if(a[i]== data)
		{
			return i;
		}
	}
	if(i==n)
		return -1;
}
