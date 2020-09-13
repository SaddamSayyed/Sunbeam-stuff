/*
 ============================================================================
 Name        : selection_sort.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#define SIZE 10
void swap(int *a,int i,int min)
{
	int temp;
	temp=a[i];
	a[i]=a[min];
	a[min]=temp;
}

void accept_elements(int *p)
{
	for(int i=0;i<SIZE;i++)
		{
			scanf("%d",&p[i]);
		}
}
void print_elements(int *p)
{
	for(int i=0;i<SIZE;i++)
		{
			printf("%d\t",p[i]);
		}
}
void sort(int *a)
{
	for(int i=0;i<SIZE;i++)
		{
			int min=i;
			for(int j=i+1;j<SIZE;j++)
			{
				if(a[j]<a[min])//to sort in descending order a[j]>a[min]
					min=j;
			}
			if(min!=i)
				swap(a,i,min);
			printf("\npass %d:",i+1);
			print_elements(a);
		}
}
int main(void)
{
	int a[SIZE];
	int *p=a;
	printf("Please enter the array elements :\n");
	accept_elements(p);
	printf("the array elements brfore sorting are :\n");
	print_elements(p);
	sort(p);
	printf("\nthe array elements after sorting are :\n");
	print_elements(p);
	return EXIT_SUCCESS;
}
