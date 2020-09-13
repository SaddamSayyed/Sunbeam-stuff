/*
 ============================================================================
 Name        : asgn_3.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#define SIZE 10
#define BOOL int
#define YES 1
#define NO 0
typedef enum menu {EXIT,ADD,DEL,ADD_ALL,DEL_ALL,FIND_MIN,FIND_MAX,SUM}menu;
void accept(int *p)
{
	printf("Please Enter the Elements :\n");
	for(int i=0;i<SIZE;i++)
		scanf("%d",&p[i]);
}
void display(const int *p)
{
	printf("The Elements in the Array are as follows :\n");
	for(int i=0;i<SIZE;i++)
		printf("%d)%d\t",i,p[i]);
}
void delete(int *p)
{
	for(int i=0;i<SIZE;i++)
		p[i]=0;
}
void accept_1(int *p)
{
	display(p);
	printf("\nChoose Index position to add:\n");
	int i;
	scanf("%d",&i);
	int temp =p[i];
	printf("Entere the Element\n");
	scanf("%d",&p[i]);
	printf("\nAfter adding element %d:\n",temp);
	display(p);
}
void delete_1(int *p)
{
	display(p);
	printf("\nchoose Index to delete:\n");
	int i;
	scanf("%d",&i);
	int temp =p[i];
	p[i]=0;
	printf("\nafter deleting Element %d\n",temp);
	display(p);
}

int menuoperations(int *m,const int *p)
{
	printf("\nChoose one of the following options:\n1)ADD AN ELEMENT\n2)DELETE An ELEMENT\n3)ADD ALL"
				"\n4)DEL ALL\n5)FIND MINIMUM\n6)FIND MAXIMUM\n7)SUM\n0)EXIT");
	scanf("%d",m);
	return *m;
}
BOOL is_full(const int *p )
{
	for(int i=0;i<SIZE;i++)
		{
			if(p[i]==0)
				return NO;
		}
	return YES;
}
BOOL is_empty(const int *p )
{
	for(int i=0;i<SIZE;i++)
		{
			if(p[i]!=0)
				return NO;
		}
	return YES;
}
int max(int *p)
{
	int max=p[0];
	for(int i=0;i<SIZE;i++)
	{
		if(max<=p[i])
			max=p[i];
	}
	return max;
}
int min(int *p)
{
	int min=p[0];
	for(int i=0;i<SIZE;i++)
	{
		if(min>=p[i])
			min=p[i];
	}
	return min;
}
int sum(const int *p)
{
	int sum=0;
	for(int i=0;i<SIZE;i++)
		sum=sum+p[i];
	return sum;

}
int main(void)
{
	int a[SIZE];
	int *p=a;
	delete(p);
	int menu;
	while(menuoperations(&menu,p))
	{
		switch(menu)
			{
				case ADD :
					if(is_full(p))
						printf("The array is full,delete one to add one\n");
					else
						accept_1(p);
					break;
				case DEL :
					if(is_empty(p))
						printf("The array is Empty\n");
					else
						delete_1(p);
					break;
				case ADD_ALL :
					accept(p);
					break;
				case DEL_ALL :
					delete(p);
					break;
				case FIND_MIN :
					printf("The Minimum : %d\n",min(p));
					break;
				case FIND_MAX :
					printf("The Maximum : %d\n",max(p));
					break;
				case SUM :
					printf("The SUM : %d\n",sum(p));
					break;
				default :
					printf("Please choose a valid option\n");
			}
	}
	return EXIT_SUCCESS;
}
