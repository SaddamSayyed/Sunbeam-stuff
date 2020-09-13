/*
 ============================================================================
 Name        : asgn5_6.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */
#include <stdio.h>
#include <stdlib.h>
void input_arr(double a[], int n);
int find_dup(double a[],int n);
void display_arr(double a[], int n);
int main(void)
{
	int n;
	printf("enter the no of elements in the array\n");
	scanf("%d",&n);
	double a[n];
	input_arr(a,n);
	display_arr(a,n);
	n=find_dup(a,n);
	display_arr(a,n);
	return 0;
	return EXIT_SUCCESS;
}
void input_arr(double a[], int n)
{
	int i;
	printf("please enter the array elements : \n");
	for(i=0;i<n;i++)
		scanf("%lf", &a[i]);
}
void display_arr(double *a, int n)
{
	int i;
	for(i=0;i<n;i++)
		{
		printf("%lf\t",a[i]);
		}
	printf("\n");
}
int find_dup(double a[],int n)
{
	short int i,j,k=0,c=0;
	double b[n];
	for(i=0;i<n;i++)
	{
		for(j=0;j<k;j++)
		{
			if(a[i]==b[j])
				break;

		}
		if(j==k)
		{
			b[k]=a[i];
			k++;
		}

	}
	printf("duplicates = %d and no of unique elements into the array are: %d\n",n-k,k);
	for(i=0;i<k;i++)
	{
		a[i]=b[i];
	}
	return k;
}
