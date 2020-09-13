/*
 ============================================================================
 Name        : sorting_dynamic_array.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
void swap(int *a,int i,int min)
{
	int temp;
	temp=a[i];
	a[i]=a[min];
	a[min]=temp;
}

void accept_elements(int *p,int n)
{
	for(int i=0;i<n;i++)
		{
			scanf("%d",(p+i));
		}
}
void print_elements(int *p,int n)
{
	for(int i=0;i<n;i++)
		{
			printf("%d\t",*(p+i));
		}
}
void sort(int *a,int n)
{
	for(int i=0;i<n;i++)
		{
			int min=i;
			for(int j=i+1;j<n;j++)
			{
				if(a[j]<a[min])//to sort in descending order a[j]>a[min]
					min=j;
			}
			if(min!=i)
				swap(a,i,min);
			printf("\npass %d:",i+1);
			print_elements(a,n);
		}
}
int main(void)
{

	int *p;
	int n,i;
	printf("plz enter the no of elements\n");
	scanf("%d",&n);
	p=(int *)malloc(n*sizeof(int));
	if(p==NULL)
	{
		printf("Memory not allocated\n");
		exit(0);
	}
	else
	{
		printf("memory allocation successful\nenter the elements");
		accept_elements(p,n);
		printf("the array elements brfore sorting are :\n");
		print_elements(p,n);
		sort(p,n);
		printf("\nthe array elements after sorting are :\n");
		print_elements(p,n);
		return EXIT_SUCCESS;
	}
}
