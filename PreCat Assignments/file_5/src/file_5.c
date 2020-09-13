/*
 ============================================================================
 Name        : file_5.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
typedef struct student
{
	int roll_no;
	char name[20];
	int marks;
}STUDENT;
void accept_data(STUDENT *s)
{
	printf("Please enter students data ::\n1)Roll no:");
	scanf("%d%*c",&s->roll_no);
	printf("2)Name :");
	fgets(s->name,20,stdin);
	printf("3)marks");
	scanf("%d",&s->marks);
}

void print_data(STUDENT *s)
{
	printf("%d\n%s\n%d\n",s->roll_no,s->name,s->marks);
}
void write_file(FILE *f,STUDENT *s)
{
	f=fopen("student.txt","w");
	if(f==NULL)
		printf("\nUnable to open the file");
	else
	{
		fprintf(f,"%d\n",s->roll_no);
		fprintf(f,"%s",s->name);
		fprintf(f,"%d",s->marks);
	}
	fclose(f);
}
void read_file(FILE *f)
{
	STUDENT s;
	f=fopen("student.txt","r");
	if(f==NULL)
	{
		printf("unable to open the file");
	}
	else
	{
		fscanf(f,"%d%s%d",&s.roll_no,s.name,&s.marks);
		print_data(&s);
	}
	fclose(f);
}
int main(void)
{
	FILE *f;
	STUDENT s1;
	STUDENT *p= &s1;
	accept_data(p);
	print_data(p);
	write_file(f,p);
	read_file(f);
	return EXIT_SUCCESS;
}
