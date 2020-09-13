/*
 ============================================================================
 Name        : asgn5_3.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

void input_arr(double a[], int n);
void display_arr(double a[], int n);
void reverse_arr(double a[],int n);
int main(void)
{
	int n=10;
	double a[n];
	input_arr(a,n);
	reverse_arr(a,n);
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
void display_arr(double a[], int n)
{
	int i;
	for(i=0;i<n;i++)
		printf("\n%.2lf",a[i]);
	printf("\n");
}
void reverse_arr(double a[],int n)
{
	int i;
	for(i=0;i<n/2;i++)
	{
		double t= a[i];
		a[i]=a[n-1-i];
		a[n-1-i]=t;
	}
}
