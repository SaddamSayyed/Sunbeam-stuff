/*
 ============================================================================
 Name        : asgn5_2.c
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
int main(void)
{
	double a[5];
	input_arr(a,5);
	display_arr(a,5);
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
