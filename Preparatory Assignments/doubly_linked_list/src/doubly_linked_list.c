/*
 ============================================================================
 Name        : doubly_linked_list.c
 Author      : Saddam Sayyed
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
typedef enum{EXIT,ADDFIRST,ADDLAST,ADDATPOS,DELFIRST,DELLAST,DELFROMPOS,TRAVERSE}MENU;
typedef struct node
{
	int data;
	struct node *next;
	struct node *prev;
}NODE;
void accept_data(int *data)
{
	printf("\n Specify Data to add:");
	scanf("%d",data);
}
NODE *head=NULL;
MENU menu_choice()
{
	MENU mchoice;
	printf("\n 0. Exit");
	printf("\n 1. Add Element at First");
	printf("\n 2. Add Element at last");
	printf("\n 3. Add Element at given position");
	printf("\n 4. Delete Element from First");
	printf("\n 5. Delete Element from last");
	printf("\n 6. Delete Element from given position");
	printf("\n 7. Traverse ");
	scanf("%d",&mchoice);
	return mchoice;
}
NODE *create_node(int data)
{
	NODE *newnode=(NODE *)malloc(sizeof(NODE));
	newnode->next=NULL;
	newnode->prev=NULL;
	newnode->data=data;
	return newnode;
}
void add_at_first(int data)
{
		NODE *newnode=create_node(data);
		if(head==NULL)
			head=newnode;
		else
		{
			newnode->next=head;
			newnode->prev=head;
			head=newnode;
			newnode->next->prev=newnode;

		}
}
void add_at_last(int data)
{
	NODE *newnode=create_node(data);
			if(head==NULL)
				head=newnode;
			else
			{
				NODE *trav=head;
				while(trav->next!=NULL)
				{
					trav=trav->next;
				}
				newnode->prev=trav;
				newnode->next=NULL;
				trav->next=newnode;

			}
}
int size()
{
	NODE *trav=head;
	int count=0;
	while(trav!=NULL)
	{
		count++;
		trav=trav->next;
	}
	return count;
}
void add_at_pos(int data,int pos)
{
	NODE *trav=head,*temp;
	int p=1;
	if(pos==1)
		add_at_first(data);
	else if(pos==size()+1)
		add_at_last(data);
	else
	{
		NODE *newnode=create_node(data);
		newnode->data=data;
		while(p<pos)
		{
			trav=trav->next;
			p++;
		}
		newnode->next=trav;
		newnode->prev=trav->prev;
		free(trav);
		trav=NULL;
	}
}
void del_from_first()
{
	if(head==NULL)
	{
		printf("\nThe list is Empty");
		return;
	}
	NODE *temp = head;
	head->next->prev=NULL;
	head=head->next;
	free(temp);
	temp=NULL;
}
void del_from_last()
{
	if(head==NULL)
	{
		printf("\nThe list is Empty");
		return;
	}
	NODE *temp = head;
	while(temp->next!=NULL)
		temp=temp->next;
	temp->prev->next=NULL;
	free(temp);
	temp=NULL;
}
void del_at_pos(int pos)
{
	if(head==NULL)
	{
		printf("\nThe list is Empty");
		return;
	}
	else if(pos==1)
		del_from_first();
	else if(pos==size())
		del_from_last();
	int p=1;
	NODE *trav = head,*temp;
	while(p!=pos)
	{
		trav=trav->next;
		p++;
	}
	temp=trav->next;
	trav->prev->next=temp;
	temp->prev=trav->prev;
	free(trav);
	trav=NULL;
}
void traverse_list_forward()
{

	if(head==NULL)
		return ;
	NODE *trav=head;
	while(trav!=NULL)
	{
		printf("%d\t",trav->data);
		trav=trav->next;
	}
}
void traverse_list_backward(NODE *trav)
{

	if(trav==NULL)
		return;
	traverse_list_backward(trav->next);
	printf("%d\t",trav->data);
}
void free_list()
{
	while(head!=NULL)
		{
			del_from_first();
		}
}
int main(void)
{
	MENU mchoice;
	int data,pos;
	do
		{
			switch(mchoice)
			{
				case ADDFIRST:
							accept_data(&data);
							add_at_first(data);
							break;
				case ADDLAST:
							accept_data(&data);
							add_at_last(data);
							break;
				case ADDATPOS:
							printf("\n Specify position for newnode");
							scanf("%d",&pos);
							if(pos<=0 || pos > (size()+1))
								printf("\n Invalid position");
							else
							{
								accept_data(&data);
								add_at_pos(data,pos);
							}
							break;
				case DELFIRST:
							del_from_first();
							break;
				case DELLAST:
							del_from_last();
							break;
				case DELFROMPOS:
							printf("\n Specify position of Node");
							scanf("%d",&pos);
							if(pos<=0 || pos > size())
								printf("\n Invalid position");
							else
							{
								del_at_pos(pos);
							}
							break;
				case TRAVERSE:
							printf("\n Traverse in Forward Direction \n");
							traverse_list_forward();
							printf("\n Traverse in Backward Direction \n");
							traverse_list_backward(head);
							break;
			}
		}while((mchoice=menu_choice())!=EXIT);
		free_list();

	return EXIT_SUCCESS;
}
