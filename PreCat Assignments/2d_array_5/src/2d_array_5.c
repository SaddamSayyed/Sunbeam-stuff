/*
 ============================================================================
 Name        : 2d_array_5.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
char *accept()
{
	char *a=(char *)malloc(5*sizeof(char));
	scanf("%s",a);
	return a;
}
void print(char *a,int n)
{
	for(int i=0;i<n;i++)
	{
		printf("%s",a[i]);
	}
}
//void display_2d(char *arr[],int);
int main(void)
{
	char *arr[5];
	printf("Please enter the no of students\n");
	for(int i=0;i<5;i++)
	{
		arr[i]=accept();
	}
	printf("\n%s",arr[0]);
	print(*arr,5);

	return EXIT_SUCCESS;
}
/*void accept_2d(char *arr[],int n)
{
	int i;
	printf("enter the name of 5 students\n");
	for(i=0;i<n;i++)
	{
		scanf("%s",arr[i]);//fgets(arr[i],20,stdin);
	}

}
void display_2d(char *arr[],int n)
{
	int i;
	printf("\nThe names of the students are ::\n");
	for(i=0;i<n;i++)
		{
			printf("%10s\n",arr[i]);
		}
}*/
