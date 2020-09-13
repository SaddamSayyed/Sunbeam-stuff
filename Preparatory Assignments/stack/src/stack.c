/*
 ============================================================================
 Name        : stack.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#define SIZE 5
#define TRUE 1
#define FALSE 0
typedef int BOOL;
typedef enum {EXIT,PUSHELEMENT,POPELEMENT,PEEKELEMENT}MENU;
typedef struct
{
	int a[SIZE];
	int top;
}stack;
void init(stack *s)
{
	s->top=-1;
}
MENU choice()
{
	MENU mchoice;
	printf("\n 0. Exit");
	printf("\n 1. Push element on stack");
	printf("\n 2. Pop element from stack");
	printf("\n 3. Peek element from stack");
	scanf("%d",&mchoice);
	return mchoice;
}
BOOL is_full(stack *s)
{
	if(s->top==SIZE-1)
		return TRUE;
	else
		return FALSE;
}
void push(stack *s)
{
	s->top++;
	printf("\nEnter element to be pushed :");
	scanf("%d",&s->a[s->top]);
}
BOOL is_empty(stack *s)
{
	if(s->top==-1)
		return TRUE;
	else
		return FALSE;
}
int peek(stack *s)
{
	return s->a[s->top];
}
void pop(stack *s)
{
	s->top--;
}
int main(void) {
	stack s;
	MENU mchoice;
	init(&s);
	while((mchoice=choice())!=EXIT)
	{
		switch(mchoice)
				{
					case PUSHELEMENT:
							if(is_full(&s))
								printf("\n Stack is full...");
							else
								push(&s);
							break;
					case POPELEMENT:
							if(is_empty(&s))
								printf("\n Stack is empty..");
							else
							{
								printf("\nElement = %d is popped.",peek(&s));
								pop(&s);
							}
							break;
					case PEEKELEMENT :
							if(is_empty(&s))
								printf("\n Stack is empty..");
							else
								printf("Element = %d",peek(&s));
							break;
				}
	}
	return EXIT_SUCCESS;
}
