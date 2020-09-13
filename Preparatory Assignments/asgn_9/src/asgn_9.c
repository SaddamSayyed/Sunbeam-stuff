/*
 ============================================================================
 Name        : asgn_9.c
 Author      : 
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
}NODE;
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
void accept_data(int *data)
{
	printf("\n Specify Data to add:");
	scanf("%d",data); 
}
NODE *create_node()
{
	NODE *temp;
	temp=(NODE *)malloc(sizeof(NODE));
	temp->next=NULL;
	return(temp);
}
void add_at_first(int data)
{
	NODE *newnode;
	newnode = create_node();
	newnode->data=data;
	if(head==NULL)
		head=newnode;
	else
	{
		newnode->next=head;
		head=newnode;
	}
}
void add_at_last(int data)
{
	NODE *newnode,*trav;
	newnode = create_node();
	newnode->data=data;
	if(head==NULL)
		head=newnode;
	else
	{
		trav=head;
		while(trav->next!=NULL)
		{
			trav=trav->next;
		}
		trav->next=newnode;
	}
}
int size()
{
	NODE *trav=head;
	int cnt=0;
	while(trav!=NULL)
	{
		cnt++;
		trav=trav->next;
	}
	return cnt;
}
void add_at_pos(int data,int pos)
{
	NODE *newnode,*trav;
	int p=1;
	if(pos==1)
		add_at_first(data);
	else if(pos==size()+1)
		add_at_last(data);
	else
	{
		newnode = create_node();
		newnode->data=data;
		trav=head;
		while(p<pos-1)
		{
			trav=trav->next;
			p++;
		}
		newnode->next=trav->next;
		trav->next=newnode;
	}


}
void traverse_list_forward()
{
	NODE *trav=head;
	if(head==NULL)
		return ;
	while(trav!=NULL)
	{
		printf("%d\t",trav->data);
		trav=trav->next;
	}
}
void traverse_list_backward(NODE *trav)
{
	if(trav==NULL)
			return ;
		traverse_list_backward(trav->next);
		printf("%d\t",trav->data);
}
void del_from_first()
{
	if(head==NULL)
	{
		printf("\nThe list is Empty");
		return;
	}
	NODE *temp = head;
	head=head->next;
	free(temp);
	temp=NULL;
}
void del_from_last()
{
	NODE *trav=head,*prev=NULL;
	while(trav->next!=NULL)
	{
		prev=trav;
		trav=trav->next;
	}
	if(prev==NULL)
		head=NULL;
	else
		prev->next=NULL;
	free(trav);
	trav=NULL;
}
void del_from_given_pos(int pos)
{
	NODE *trav,*temp;
	int p;
	if(pos==1)
		del_from_first();
	else if(pos == size())
		del_from_last();
	else
	{
		trav=head;
		p=1;
		while(p < pos-1)
		{
			trav=trav->next;
			p++;
		}
		temp=trav->next;
		trav->next=temp->next;
		free(temp);
		temp=NULL;
	}
}
free_list()
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
								del_from_given_pos(pos);
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
