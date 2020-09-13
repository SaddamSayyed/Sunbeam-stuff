#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/************************************************************************/

/*
 * An inventory management system needs to manage data of the items into binary file.
 * Each item have
		id,
		name,
		price and
		quantity.
 * Write a menu-driven program to implement
		add,
		find,
		display all,
		edit and
		delete operations from the items file.
 * Order id (int) should be generated automatically and must be unique.
*/

/************************************************************************/
typedef struct item
{
    int id;
    char name[50];
    float price;
    int quantity;
}ITEM;

typedef struct node
{
    ITEM data;
    struct node *next;
}NODE;

NODE *head = NULL;

enum menu{ADD_DATA = 1, FIND_DATA, DISPLAY_ALL, EDIT_DATA, DELETE_ITEM};

char str[];

int Unique_ID = 0;

ITEM arr[6]= {	{1, "ABCD", 100.00, 1},
				{2, "DEFG", 101.00, 2},
				{3, "HIJK", 102.00, 3},
				{4, "LMNO", 103.25, 4},
				{5, "PQRS", 104.23, 5},
				{6, "TUVW", 105.36, 6}
};
/************************************************************************/
void add_item_data();
void read_item_data();
void display_data(const ITEM *temp);
void create_Linked_List(const ITEM * dat);

ITEM ent_Item_dat();
NODE * Create_Node(const ITEM * dat);
/*************************************************************************/

/*===================================================================*/
void write_dat_File()
{
	FILE *fp;
	int i;
	fp = fopen("My_Bin_File.txt","wb");
//add_Node();
	if(fp == NULL)
	{
		printf("\n File Not Open\n");
	}
	else
	{
		printf("\n File Created Successfully\n");
	}

	for(i = 0 ;i<6; i++)
	{
		fwrite(&arr[i], sizeof(ITEM), 1 , fp);
	}
	fclose(fp);
}

/*===================================================================*/
void add_item_data()
{
    FILE *fp;
    ITEM dat;
    fp = fopen("My_Bin_File.txt","ab");

    if(fp == NULL)
    {
        printf("\n File Opening Error \n");
    }
    dat = ent_Item_dat();

    fwrite(&dat,sizeof(ITEM),1,fp);

    if(fwrite != 0)
       {
            printf("contents to file written successfully !\n");
       }
    else
        {
            printf("error writing file !\n");
        }

    fclose(fp);
}

/*===================================================================*/
void read_item_data()
{
    FILE *fp;
    ITEM dat;
    fp = fopen("My_Bin_File.txt","rb");
    if(fp == NULL)
    {
        printf("\n File Opening Error \n");
    }

   while(fread(&dat,sizeof(ITEM),1,fp))
   {
       create_Linked_List(&dat);
       Unique_ID = dat.id;
   }

       fclose(fp);
}
/*=======================================================*/

ITEM ent_Item_dat(const int id)
{
	ITEM new_dat;
//	Unique_ID++;
	new_dat.id = id;
	printf("\nManagement Data Information:\n");

	printf("\n\t Enter Item Name:\t");
	scanf("%*c%[^\n]c", new_dat.name);

	printf("\n\t Enter Item Price:\t");
	scanf("%f", &new_dat.price);

	printf("\n\t Enter Item Quantity:\t");
	scanf("%d", &new_dat.quantity);

	return new_dat;
}

/*=======================================================*/
void Display_Linked_List()
{
    NODE *trav;
    trav = head;

    printf("Inside Display Function");
    while(trav != NULL)
    {
        display_data(&trav->data);
         trav = trav->next;
    }
}

/*=======================================================*/
void display_data(const ITEM *temp)
{
    printf("\n----------------------------------------------------------------------------\n");
    printf("\nInventory Management Data\n");
    printf("\n\t Data ID           : %d ",temp->id);
    printf("\n\t Data Name         : %s ",temp->name);
    printf("\n\t Data price        : %.2f/- ",temp->price);
    printf("\n\t Data Quantdatity  : %d ",temp->quantity);
    printf("\n----------------------------------------------------------------------------\n");
}

/*=======================================================*/
NODE * Create_Node(const ITEM * dat)
{
    NODE * new_Node;
    new_Node = (NODE*)malloc(sizeof(NODE));
    new_Node->next = NULL;
    new_Node->data = *dat;

    return new_Node;
}

/*=======================================================*/
void create_Linked_List(const ITEM * dat)
{
    NODE * trav, *new;
    new = Create_Node(dat);
    if(head == NULL)
    {
        head = new;
    }
    else
    {
            trav = head;
            while(trav->next != NULL)
            {
                trav = trav->next;
            }
            trav->next = new;
    }
}

/*=======================================================*/
void add_Node()
{
    ITEM  temp;
    Unique_ID++;
    temp = ent_Item_dat(Unique_ID);
    create_Linked_List(&temp);

}

/*=======================================================*/
void find_item()
{
    NODE *trav;
    int uid;
    printf("Enter Unique ID to Find Item:\t");
    scanf("%d",&uid);

    trav = head;

    while(trav != NULL)
    {
        if(trav->data.id == uid)
        {
            display_data(&trav->data);
            break;
        }
        trav = trav->next;
    }
}

/*=======================================================*/
void edit_data()
{
    int uid;
    NODE *trav;

    printf("Enter Unique ID to Edit Info\n");
    scanf("%d",&uid);

    trav = head;

    while(trav != NULL)
    {
        if(trav->data.id == uid)
        {
            trav->data = ent_Item_dat(uid);
            break;
        }
        trav = trav->next;
    }

}

/*=======================================================*/
void delete_item()
{
    int pos;
    NODE *trav,*temp;
	int p;
    printf("Enter Unique ID to Delete Info\n");
    scanf("%d",&pos);

    trav = head;
    p=1;
    while(p < pos-1)
    {
        trav=trav->next;
        p++;
    }//traverse till node next to which node is to be deleted
    temp=trav->next;
    trav->next=temp->next;
    free(temp);
    temp=NULL;

}
/******************************************************************************************/
int main()
{
    int choice;
    ITEM demo;
    write_dat_File();
    read_item_data();
    while(1)
    {
        printf("\n 1. Add Item :\t");
        printf("\n 2. Find Item :\t");
        printf("\n 3. Display Item All :\t");
        printf("\n 4. Edit Item :\t");
        printf("\n 5. Delete Item :\t");
        printf("\n Enter Your choice:\t");
        scanf("%d",&choice);
        switch(choice)
        {
            case ADD_DATA   :  add_Node();
                               break;

            case FIND_DATA  :   find_item();
                                break;

            case DISPLAY_ALL:   Display_Linked_List();
                                break;

            case EDIT_DATA  :   edit_data();
                                break;

            case DELETE_ITEM:   delete_item();
                                break;

            default         :   printf("\nInvalid Data Entered\n");
                                break;
        }

        printf("\n===================================================================\n");
    }

    return 0;
}
