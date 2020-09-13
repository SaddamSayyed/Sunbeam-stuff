/*
 ============================================================================
 Name        : asgn_7.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef enum{EXIT,ADDFIRST,ADDLAST,ADD_AT_POS,DEL_FIRST,DEL_LAST,DEL_AT_POS,
				DEL_ALL,FINDBY_ID,FINDBY_NAME,DISPLAY}MENU;
typedef struct accounts
{
	int id;
	char type[10];
	float bal;
	struct acount_holder
	{
		char name[20];
		char addrs[20];
		char cont[10];
	};
	struct acount_holder acc_holder;
	struct accounts *next;
	struct accounts *prev;

}BANKACC;
BANKACC *head=NULL;
MENU menu_choice()
{
	MENU mchoice;
	printf("\n 0. Exit");
	printf("\n 1. Add Account at First");
	printf("\n 2. Add Account at last");
	printf("\n 3. Add Account at given position");
	printf("\n 4. Delete Account from First");
	printf("\n 5. Delete Account from last");
	printf("\n 6. Delete Account from given position");
	printf("\n 7. Delete All Accounts");
	printf("\n 8. Find Account By Id");
	printf("\n 10. Find Account By Name");
	printf("\n 11. Display Accoutnts");
	scanf("%d",&mchoice);
	return mchoice;
}
BANKACC *create_node()
{
	BANKACC *newnode = (BANKACC*)malloc(sizeof(BANKACC));
	printf("\nEnter Id : ");
	scanf("%d",&(newnode->id));
	scanf("%*c");
	printf("\nEnter Account Type(Saving/Current) :");
	scanf("%s",newnode->type);
	scanf("%*c");
	printf("\nEnter Balance : ");
	scanf("%f",&(newnode->bal));
	printf("\nEnter Account Holder Details : ");
	printf("\n Name : ");
	scanf("%*c");
	scanf("%[^\n]s",newnode->acc_holder.name);
	printf("\n Address : ");
	scanf("%*c");
	scanf("%[^\n]s",newnode->acc_holder.addrs);
	printf("\n Contact Details : ");
	scanf("%*c");
	scanf("%s",newnode->acc_holder.cont);
	newnode->next=NULL;
	newnode->prev=NULL;
	return newnode;

}
void add_at_first()
{
	BANKACC *newnode =create_node();
	if(head==NULL)
		head=newnode;
	else
	{
		newnode->next=head;
		newnode->prev=NULL;
		head=newnode;
	}
}
void add_at_last()
{
	BANKACC *newnode =create_node();
	if(head==NULL)
		head=newnode;
	else
	{
		BANKACC *trav=head;
		while(trav->next!=NULL)
			trav=trav->next;
		newnode->next=NULL;
		newnode->prev=trav;
		trav->next=newnode;
	}
}
int size()
{
	BANKACC *trav=head;
	int count=0;
	while(trav!=NULL)
	{
		count++;
		trav=trav->next;
	}
	return count;
}
void add_at_pos()
{
	printf("\nPLease specify Position : ");
	int pos;
	scanf("%d",&pos);
	scanf("%*c");
	int p=1;
	if(p==1)
		add_at_first();
	else if(p==size()+1)
		add_at_last();
	else
	{
		BANKACC *newnode=create_node(),*trav=head;
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
	BANKACC *temp = head;
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
	BANKACC *temp = head;
	while(temp->next!=NULL)
		temp=temp->next;
	temp->prev->next=NULL;
	free(temp);
	temp=NULL;
}
void del_at_pos()
{
	printf("\nPLease specify Position : ");
	int pos;
	scanf("%d",&pos);
	scanf("%*c");
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
	BANKACC *trav = head,*temp;
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
void display_all()
{
	BANKACC *trav=head;
	while(trav!=NULL)
	{
		printf("\n Id : %d",trav->id);
		printf("\n Account Type : %s",trav->type);
		printf("\n Account Balance : %f",trav->bal);
		printf("\n Bank Account Holder Details : ");
		printf("\n  Name : %s",trav->acc_holder.name);
		printf("\n  Address : %s",trav->acc_holder.addrs);
		printf("\n  Contact Details : %s",trav->acc_holder.cont);
		printf("\n---------------------------------------------\n");
		trav = trav->next;
	}
}
void traverse_list_forward()
{

	if(head==NULL)
		return ;
	BANKACC *trav=head;
	while(trav!=NULL)
	{
		display_all();
		trav=trav->next;
	}
}
void traverse_list_backward(BANKACC *trav)
{

	if(trav==NULL)
		return;
	traverse_list_backward(trav->next);
	display_all();

}
void free_list()
{
	while(head!=NULL)
	{
		del_from_first();
	}
}
void find_by_id()
{
	int id;
	printf("\n Please enter ID :");
	scanf("%d",&id);
	scanf("%*c");
	BANKACC *trav=head;
	while(trav!=NULL)
	{
		if(trav->id==id)
		{
			printf("\n Id : %d",trav->id);
			printf("\n Account Type : %s",trav->type);
			printf("\n Account Balance : %f",trav->bal);
			printf("\n Bank Account Holder Details : ");
			printf("\n  Name : %s",trav->acc_holder.name);
			printf("\n  Address : %s",trav->acc_holder.addrs);
			printf("\n  Contact Details : %s",trav->acc_holder.cont);
			printf("\n---------------------------------------------\n");
			return;
		}
		else
			trav=trav->next;
	}
	printf("\nNO MATCH FOUND\n");
}
void find_by_name()
{
	char name[20];
	printf("\n Please enter Name :");
	scanf("%[^\n]s",name);
	//scanf("%*c");
	BANKACC *trav=head;
	while(trav!=NULL)
	{
		if(strcmp(trav->acc_holder.name,name)==0)
		{
			printf("\n Id : %d",trav->id);
			printf("\n Account Type : %s",trav->type);
			printf("\n Account Balance : %f",trav->bal);
			printf("\n Bank Account Holder Details : ");
			printf("\n  Name : %s",trav->acc_holder.name);
			printf("\n  Address : %s",trav->acc_holder.addrs);
			printf("\n  Contact Details : %s",trav->acc_holder.cont);
			printf("\n---------------------------------------------\n");
			return;
		}
		else
			trav=trav->next;
	}
	printf("\nNO MATCH FOUND\n");
}
int main(void)
{
	MENU mchoice;
	while((mchoice=menu_choice())!=EXIT)
	{
		switch(mchoice)
		{
			case ADDFIRST:
				add_at_first();
				break;
			case ADDLAST:
				add_at_last();
				break;
			case ADD_AT_POS:
				add_at_pos();
				break;
			case DEL_FIRST:
				del_from_first();
				break;
			case DEL_LAST:
				del_from_last();
				break;
			case DEL_AT_POS:
				del_at_pos();
				break;
			case DEL_ALL:
				free_list();
				break;
			case FINDBY_ID:
				find_by_id();
				break;
			case FINDBY_NAME:
				find_by_name();
				break;
			case DISPLAY:
				display_all();
				break;
		}
	}
	free_list();

	return EXIT_SUCCESS;
}
