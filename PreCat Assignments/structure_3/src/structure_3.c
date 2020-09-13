/*
 ============================================================================
 Name        : structure_3.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */
#include <stdio.h>
#include <stdlib.h>
struct student
{
	int r;
	char name[20];
	int marks;
};
void accept_info(struct student *s);
void display_info(struct student *s);
int main(void)
{
	struct student s[2];
	for(int i=0;i<2;i++)
		accept_info(&s[i]);
	for(int i=0;i<2;i++)
		display_info(&s[i]);
	return EXIT_SUCCESS;
}
void accept_info(struct student *s)
{
	printf("plz enter the student info as\n1)roll number\n2)Name\n3)Marks\n");
		scanf("%d %s %d",&s->r,s->name,&s->marks);
}
void display_info(struct student *s)
{
		printf("\nthe student info is as follows:\n1)roll number: %d\n2)Name: %s\n3)Marks: %d",s->r,s->name,s->marks);
}
