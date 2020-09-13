/*
 ============================================================================
 Name        : asgn5_4.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

void input_arr(double a[], int n);
//void display_arr(double a[], int n);
void find_max(double a[],int n);
void find_min(double a[],int n);
int main(void)
{
	int n=5;
	double a[n];
	input_arr(a,n);
	//display_arr(a,n);
	find_max(a,n);
	find_min(a,n);
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
/*void display_arr(double a[], int n)
{
	int i;
	for(i=0;i<n;i++)
		printf("\n%.2lf",a[i]);
	printf("\n");
}*/
void find_max(double a[],int n)
{
	int i;
	double max=a[0];
	for(i=0;i<n;i++)
	{
		if(max<a[i+1])
			max=a[i+1];
	}
	printf(" %lf is the largest of array elements\n",max);
}
void find_min(double a[],int n)
{
	int i;
	double min;
	min=a[0];
	for(i=0;i<n-1;i++)
	{
		if(min>=a[i+1])
			min=a[i+1];

	}
	printf(" %lf is the smallest of array elements\n",min);
}
