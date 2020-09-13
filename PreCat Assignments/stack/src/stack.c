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
typedef int ELEMENT;
typedef int BOOL;
typedef struct
{
	ELEMENT e[SIZE];
	int top;
}STACK;
typedef enum {EXIT,PUSHELEMENT,PEEKELEMENT,POPELEMENT}
MENU;
void init_stack(STACK *s)
{
	s->top=-1;
}
void menu_choice(int *m)
{
		printf("please select one of the following options to perform\n");
		printf("0 : EXIT\n");
		printf("1 : PUSHELEMENT \n");
		printf("2 : PEEKELEMENT \n");
		printf("3 : POPELEMENT \n");
		scanf("%d",m);

}
BOOL is_full(STACK *s)
{
	if((s->top)==SIZE-1)
		return TRUE;
	else
		return FALSE;
}
void accept_element(ELEMENT *e)
{
	printf("\nyeah, now you can push. so what are you waiting for,ENTER..");
	scanf("%c",e);

}
void push_element(STACK *s, ELEMENT e)
{
	s->e[s->top];
}
void peek_element(STACK *s)
{
	return s->e[s->top];
}
void pop_element(STACK *s)
{
	s->top--;
}
int main(void)
{
	STACK s1;
	init_stack(&s1);
	int choice;
	ELEMENT e;
	menu_choice(&choice);

	while(choice!=EXIT)
	{
			switch(choice)
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
												printf("\n Stack is empty..");//show warning message
											}
										else//if stack is not empty
											{
												e= peek_element(&s1);//retrieve top most element
												printf("Element = %d",e);
											}
											break;
						case POPELEMENT :
											if(is_empty(&s1)==TRUE)
											{
												printf("\nDude, stack is empty,what can i pop ? try somethimg else");
											}
											else
											{
												e=peek_element(&s1);
												pop_element(&s1);
											}
											break;

					}
	}


		return EXIT_SUCCESS;
}
