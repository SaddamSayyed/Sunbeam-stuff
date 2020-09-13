/*
 ============================================================================
 Name        : circular_queue.c
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
	int rear;
	int front;
}queue;
void init(queue *s)
{
	s->rear=-1;
	s->front=-1;
	for(int i=0;i<SIZE;i++)
		s->a[i]=-1;
}
MENU choice()
{
	MENU mchoice;
	printf("\n 0. Exit");
	printf("\n 1. Push element in Queue");
	printf("\n 2. Pop element from Queue");
	printf("\n 3. Peek element from Queue");
	scanf("%d",&mchoice);
	return mchoice;
}
BOOL is_full(queue *s)
{
	if((s->rear==SIZE-1 && s->front==-1 )||(s->front==s->rear && s->rear!=-1))
		return TRUE;
	else
		return FALSE;
}
void push(queue *s)
{
	if(s->rear==SIZE-1)
		s->rear=0;
	else
		s->rear++;
	printf("\nEnter element to be pushed :");
	scanf("%d",&s->a[s->rear]);
	printf("\n rear = %d \tfront =%d",s->rear,s->front);
}
BOOL is_empty(queue *s)
{
	if(s->rear==-1 && s->front==-1)
		return TRUE;
	else
		return FALSE;
}
int pop(queue *s)
{
	int e=s->a[s->front];
	s->a[s->front]=-1;
	s->front++;
	if(s->front==s->rear)
	{
		s->front=-1;
		s->rear=-1;
	}
	return e;
}
int peek(queue *s)
{
	if(s->front==SIZE-1)
		return s->a[SIZE-1];
	else
		return s->a[s->front];
}
int main(void) {
	queue s;
	MENU mchoice;
	init(&s);
	while((mchoice=choice())!=EXIT)
	{
		switch(mchoice)
				{
					case PUSHELEMENT:
							if(is_full(&s))
								printf("\n queue is full...");
							else
								push(&s);
							break;
					case POPELEMENT:
							if(is_empty(&s))
								printf("\n queue is empty..");
							else
								printf("\nElement = %d is popped.",pop(&s));
							break;
					case PEEKELEMENT :
							if(is_empty(&s))
								printf("\n Queue is empty..");
							else
								printf("Element = %d",peek(&s));
							break;
				}
	}
	return EXIT_SUCCESS;
}

