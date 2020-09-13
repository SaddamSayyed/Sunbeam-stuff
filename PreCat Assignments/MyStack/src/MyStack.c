/*
 ============================================================================
 Name        : MyStack.c
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
typedef enum {EXIT,PUSHELEMENT,PEEKELEMENT,POPELEMENT}MENU;
void init_stack(STACK *p)
{
	p->top=-1;
}
int menu_choice()
{
		MENU m;
		printf("please select one of the following options to perform\n");
		printf("0 : EXIT\n");
		printf("1 : PUSHELEMENT \n");
		printf("2 : PEEKELEMENT \n");
		printf("3 : POPELEMENT \n");
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
	printf("now go on dude, enter the element\n");
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
int main(void)
{
	STACK s1;
	init_stack(&s1);
	int choice;
	ELEMENT e;
	MENU mchoice;
	while((mchoice = menu_choice())!=EXIT)
	{
		switch(mchoice)
							{
								case PUSHELEMENT :
												if(is_full(&s1)==TRUE)
															printf("come on man stack is full......\n");
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
														printf("Element = %d\n",e);
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
														printf("Element popped is  = %d\n",e);
														pop_element(&s1);
													}
													break;

								}
	}
	return EXIT_SUCCESS;
}
