/*
 ============================================================================
 Name        : asgn_6.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define SIZE 3
#define BOOL int
#define TRUE 1
#define FALSE 0
typedef enum {EXIT,ADD,DELETE,DISPLAY}MENU;
typedef struct
{
	char name[20];
	int roll_no;
	int std;
	char sub[6][20];
	int marks[6];
}S;
int rear,front;
void init()
{
	rear=front=-1;
}
MENU mchoice()
{
	MENU m;
	printf("\nChoose one of the options\n 1.Add\n 2.Delete\n 3.Display\n 0.Exit");
	scanf("%d",&m);
	scanf("%*c");
	return m;
}
BOOL is_empty()
{
	if( (front==-1 && rear==-1) )
		return TRUE;
	else
		return FALSE;
}
BOOL is_full()
{
	if( (rear==SIZE-1 && front== -1) || (rear==front && rear!=-1))
		return TRUE;
	else
		return FALSE;
}
void add(S *s)
{
	if(rear==SIZE-1)
		rear=0;
	else
		rear++;
	printf("Please enter info\n 1.Name :");
	fgets(s[rear].name,20,stdin);
	printf("\n 2.Roll Number :");
	scanf("%d",&s[rear].roll_no);
	printf("\n 3.Standard :");
	scanf("%d",&s[rear].std);
	scanf("%*c");
	printf("\nPlease enter Subjects and Marks :\n");
	for(int i=0;i<3;i++)
	{
		char temp[10];
		printf("\nSubject %d : ",i+1);
		fgets(temp,10,stdin);
		strcpy(s[rear].sub[i],temp);
		printf("\n%d.%s :",i+1,s[rear].sub[i]);
		scanf("%d",&s[rear].marks[i]);
		scanf("%*c");

	}
	printf("\n The Information is Added.");
}
void delete(S *s)
{
	if(front==SIZE-1)
		front=0;
	else
		front++;
	if(front==rear)
		front=rear=-1;
	printf("\n The Information is deleted.");
}
void display(S *s)
{

	printf("\n THe Student's Information is as Follows:\n 1.Name : %s 2.Roll number : %d\n 3.Standard : %d\n",s[front+1].name,s[front+1].roll_no,s[front+1].std);
	printf("Subject\t\tMarks\n");
	for(int i=0;i<3;i++)
	{
		printf("%s",s[front+1].sub[i]);//puts(s[front+1].sub[i]);
		printf("\t\t%d\n",s[front+1].marks[i]);
	}
}
int main()
{
	S s[SIZE];
	init();
	MENU choice;
	do
	{
		choice=mchoice();
		switch(choice)
		{
			case ADD:
					if(is_full())
						printf("\n The queue is Full");
					else
						add(s);
					break;
			case DELETE:
					if(is_empty())
						printf("\n The queue is empty");
					else
						delete(s);
					break;
			case DISPLAY:
					if(is_empty())
						printf("\n The queue is empty");
					else
						display(s);


		}
	}while(choice!=EXIT);

	return EXIT_SUCCESS;
}
