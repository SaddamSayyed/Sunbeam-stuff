/*
 ============================================================================
 Name        : linear_queue.c
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
typedef enum {EXIT,PUSHELEMENT,POPELEMENT}MENU;
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
	scanf("%d",&mchoice);
	return mchoice;
}
BOOL is_full(queue *s)
{
	if(s->rear==SIZE-1)
		return TRUE;
	else
		return FALSE;
}
void push(queue *s)
{
	s->rear++;
	printf("\nEnter element to be pushed :");
	scanf("%d",&s->a[s->rear]);
}
BOOL is_empty(queue *s)
{
	if(s->rear==s->front)
		return TRUE;
	else
		return FALSE;
}
int pop(queue *s)
{
	int e=s->a[s->front];
	s->a[s->front]=-1;
	s->front++;
	return e;
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
				}
	}
	return EXIT_SUCCESS;
}
