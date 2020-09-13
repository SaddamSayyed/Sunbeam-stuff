/*
 ============================================================================
 Name        : bubble_sort.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#define SIZE 5
void swap(int *a,int i,int m)
{
	int temp;
	temp=a[i];
	a[i]=a[m];
	a[m]=temp;
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
	for(int i=0;i<SIZE-1;i++)
		{
			//int flag=0;
			for(int j=0;j<SIZE-1-i;j++)
			{
				if(a[j+1]<a[j])
				{					//to sort in descending order a[j+1]>a[j]
					int temp=a[j];
					a[j]=a[j+1];
					a[j+1]=temp;
					//flag=1;
				}
			}
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
