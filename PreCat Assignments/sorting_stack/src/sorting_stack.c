/*
 ============================================================================
 Name        : sorting_stack.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
typedef int ELEMENT;
typedef int BOOL;
#define SIZE 5
#define FALSE 0
#define TRUE 1
typedef struct
{
	ELEMENT e[SIZE];
	int top;
}STACK;
typedef enum {EXIT,PUSHELEMENT,PEEKELEMENT,POPELEMENT,SORT,PRINT}MENU;
void init_stack(STACK *p)
{
	p->top=-1;
}
int menu_choice()
{
		MENU m;
		printf("\nPlease select one of the following options to perform\n");
		printf("0 : EXIT\n");
		printf("1 : PUSHELEMENT \n");
		printf("2 : PEEKELEMENT \n");
		printf("3 : POPELEMENT \n");
		printf("4 : SORT \n");
		printf("5 : PRINT \n");
		scanf("%d",&m);
		return m;
}
BOOL is_full(STACK *p)
{
	if((p->top)==SIZE-1)
		return TRUE;
	else
		return FALSE;
}
BOOL is_empty(STACK *p)
{
	if(p->top==-1)
		return TRUE;
	else
		return FALSE;
}
void accept_element(ELEMENT *p)
{
	printf("\nnow go on dude, enter the element\n");
	scanf("%d",p);
}
void push_element(STACK *p,ELEMENT e)
{
	p->top++;
	p->e[p->top]=e;
}
ELEMENT peek_element(STACK *p)
{
	return p->e[p->top];
}
void pop_element(STACK *p)
{
	--p->top;
}
void swap(STACK *p,int i,int min)
{
	int temp;
	temp=p->e[i];
	p->e[i]=p->e[min];
	p->e[min]=temp;
}
void sort(STACK *p)
{
	for(int i=0;i<p->top;i++)
		{
			int min=i;
			for(int j=i+1;j<p->top;j++)
			{
				if(p->e[j]<p->e[min])//to sort in descending order a[j]>a[min]
					min=j;
			}
			if(min!=i)
				swap(p,i,min);
			printf("\npass %d:",i+1);
			print_elements(p,p->top);
		}
}
void print_elements(STACK *p)
{
	for(int i=0;i<=p->top;i++)
		{
			printf("%d\t",p->e[i]);
		}
}
int main(void)
{
	STACK s1;
	init_stack(&s1);
	ELEMENT e;
	MENU mchoice;
	while((mchoice = menu_choice())!=EXIT)
	{
		switch(mchoice)
							{
								case PUSHELEMENT :
												if(is_full(&s1)==TRUE)
															printf("\ncome on man stack is full......");
												else
														{
															accept_element(&e);
															push_element(&s1,e);
														}

													break;
								case PEEKELEMENT :
												if(is_empty(&s1))
													{
														printf("\n bro, Stack is empty..");//show warning message
													}
												else//if stack is not empty
													{
														e= peek_element(&s1);//retrieve top most element
														printf("\nElement = %d",e);
													}
													break;
								case POPELEMENT :
													if(is_empty(&s1)==TRUE)
													{
														printf("\nDude, stack is empty,what can i pop ? try somethimg else\n");
													}
													else
													{
														e=peek_element(&s1);
														printf("\nElement popped is  = %d",e);
														pop_element(&s1);
													}
													break;
								case SORT :
												if(is_empty(&s1)==TRUE)
													{
														printf("\nDude, stack is empty,what can i SORT ? try somethimg else\n");
													}
													else
													{
														sort(&s1);
													}
														break;
								case PRINT :

													if(is_empty(&s1)==TRUE)
													{
														printf("\nDude, stack is empty,what can i PRINT ? try somethimg else\n");
													}
													else
													{
														print_elements(&s1);
													}
														break;

								}
	}
	return EXIT_SUCCESS;
}
