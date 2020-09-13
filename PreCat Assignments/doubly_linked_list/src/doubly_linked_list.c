/*
 ============================================================================
 Name        : doubly_linked_list.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */


#include <stdio.h>
#include <stdlib.h>
typedef struct book
{
	int bkid;
	char bkname[20];
	int price;
}BOOK;
typedef struct node
{
	struct node *prev;
	struct book data;
	struct node *next;
}NODE;

typedef struct
{
	NODE *head;
	NODE *tail;
}LIST;
typedef enum{EXIT,CREAT_BOOKLIST,ISSUE_BOOK,RETURN_BOOK,SORT,DISPLAY_BOOK}MENUOPERATIONS;
void init_list(LIST *list)
{
	list->head=NULL;
	list->tail=NULL;
}
int size(LIST *list)
{
	NODE *trav ;
	trav->prev=NULL;
	trav->next=list->head;
	int cnt=0;
	while(trav->next!=NULL)
	{
		cnt++;
		trav=trav->next;
	}
	return cnt;
}
NODE * create_node()
{
	NODE *temp;
	temp = (NODE *)malloc(sizeof(NODE));
	temp->next=NULL;
	temp->prev=NULL;
	return temp;
}
void add_element_at_first(LIST *list,BOOK *data)
{
	NODE *newnode;
	//1. request memory for newnode dynamically
	newnode = create_node();
	//2. assign its data
	newnode->data = *data ;
	//3. attach node in existing collection
	if(list->head == NULL)//3.1 if list is empty
	{
		list->head = newnode;
		list->tail =newnode;
	}
	else//3.2 if list is ready
	{
		newnode->next = list->head;
		list->head->prev =newnode;
		list->head = newnode;
	}
}
void add_element_at_last(LIST *list,BOOK *data)
{
	NODE *newnode;
	newnode=create_node();
	newnode->data = *data;
	if(list->head==NULL)
	{
		list->head=newnode;
		list->tail=newnode;
	}
	else
	{
		newnode->prev=list->tail;
		list->tail->next=newnode;
		list->tail=newnode;
	}
}

void download_data()
{
	LIST booklist;
	init_list(&booklist);
	FILE *fp;
	BOOK b;
	fp = fopen("book.dat","r");
	if(fp==NULL)
	{
		printf("\n File access Denied");
		return ;
	}
	if(fp!=NULL)
	{

		while((fread(&b,sizeof(BOOK),1,fp))!=0)
		{
			add_element_at_last(&booklist,&b);
		}

		fclose(fp);
	}
	traverse_list(&booklist);
}
void display_book(const BOOK *b)
{
	printf("\n%d %s %d",b->bkid,b->bkname,b->price);
}
void traverse_list(LIST *list)
{
	NODE *trav=list->head;
	if(trav==NULL)
		return ;
	else
	{
		printf("\n Forward Direction \n");
		while(trav!=NULL)
		{
			display_book(&trav->data);
			trav=trav->next;
		}
		printf("\n Backward Direction \n");
		trav=list->tail;
		while(trav!=NULL)
		{
			display_book(&trav->data);
			trav=trav->prev;
		}
	}
}
void add_element_at_given_pos(LIST *list,BOOK *data,int pos)
{
	NODE *newnode,*trav;
	int p;
	if(pos==1)
		add_element_at_first(list,data);
	else if(pos==(size(list)+1))
		add_element_at_last(list, data);
	else
		{
			newnode=create_node();
			newnode->data=*data;
			trav=list->head;
			p=1;
			while(p < pos-1)
			{
				trav=trav->next;
				p++;
			}
			newnode->prev=trav;
			newnode->next=trav->next;
			trav->next->prev=newnode;
			trav->next=newnode;
		}
}
	void del_element_from_given_pos(LIST *list,int pos)
{
	NODE *trav,*temp;
	int p;
	if(pos==1)
		del_element_from_first(list);
	else if(pos==size(list))
		del_element_from_last(list);
	else
	{
		trav=list->head;
		p=1;
		while(p < pos-1)
		{
			trav=trav->next;
			p++;
		}
		temp=trav->next;
		temp->next->prev=trav;
		trav->next=temp->next;
		free(temp);
		temp=NULL;
	}
}
void del_element_from_last(LIST *list)
{
	NODE *temp;
	temp=list->tail;
	if(list->head==list->tail)
	{
		list->head=NULL;
		list->tail=NULL;
	}
	else
		list->tail->prev->next=NULL;
		free(temp);
		temp=NULL;
}

void del_element_from_first(LIST *list)
{
	NODE *temp;
	temp=list->head;
	if(list->head==list->tail)
	{
		list->head=NULL;
		list->tail=NULL;
	}
	else
		{
			temp->next->prev=NULL;//list->head->prev->next=NULL;
			list->head= temp->next;
		}
		free(temp);
		temp=NULL;
}
void search_book(LIST *list,BOOK *b, int *pos)
{

}
MENUOPERATIONS menu_operations()
{
	MENUOPERATIONS mchoice;
	printf("\n please choose one of the following operations:\n");
	printf("1.Creat booklist\n2. Issue Book\n3.Return book\n4.Sort\n5.Display book");
	scanf("%d",&mchoice);
	return mchoice;
}

int main(void)
{
		int mchoice;
		download_data();
		while(menu_operations(&mchoice)!=EXIT)
		{
			switch(mchoice)
			{
				case CREAT_BOOKLIST :
									break;
				case ISSUE_BOOK :
									break;
				case RETURN_BOOK :
									break;
				case SORT :
									break;
				case DISPLAY_BOOK :
									break;
			}
		}
		return EXIT_SUCCESS;
}

