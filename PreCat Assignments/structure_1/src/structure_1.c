/*
 ============================================================================
 Name        : structure_1.c
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
	struct student s1;
	accept_info(&s1);
	display_info(&s1);
	return EXIT_SUCCESS;
}
void accept_info(struct student *s)
{
	printf("plz enter the student info as\n1)roll number\n2)Name\n3)Marks\n");
	scanf("%d %s %d",&s->r,s->name,&s->marks);
}
void display_info(struct student *s)
{
		printf("the student info is as follows:\n1)roll number: %6d\n2)Name: %6s\n3)Marks: %6d",s->r,s->name,s->marks);
}
