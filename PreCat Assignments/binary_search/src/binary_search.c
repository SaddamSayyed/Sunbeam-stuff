/*
 ============================================================================
 Name        : binary_search.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#define SIZE 10
int search(int *a,int l,int r,int data);
int main(void)
{	int a[]={5,9,17,23,25,45,59,63,71,89};
	int data,i=0;
	printf("Enter the number to be found\n");
	scanf("%d",&data);
	i=search(a,0,SIZE-1,data);//i=search(a.SIZE,data) for non recursive function
	if(i==-1)
		printf("Data not found in the array\n");
	else
		printf("%d is at the index position %d in the array\n",data,i);
	return EXIT_SUCCESS;
}
/*int search(int *a,int n,int data)
{
	int mid,l,r;
	l=0,r=n-1;
	mid=(r+l)/2;
	while(l<=r)
	{
		mid=(r+l)/2;
		if(data==a[mid])
			return mid;
		else if(data>a[mid])
			l=mid+1;
		else
			r=mid-1;
	}
	return -1;
}*/
int search(int *a,int l,int r,int data)//using recursion
{
	if(l>r)
		return -1;
	int mid= (r+l)/2;
	if(data==a[mid])
		return mid;
	else if(data>a[mid])
		search(a,mid+1,r,data);
	else
		search(a,l,mid-1,data);
}

