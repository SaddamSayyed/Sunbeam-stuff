/*
 ============================================================================
 Name        : struct_6.c
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
	int std;
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
		scanf("%d %d %s %d",&s->std,&s->r,s->name,&s->marks);
}
void display_info(struct student *s)
{
		printf("\nthe student info is as follows:\n1)standard: %d2)roll number: %d\n3)Name: %s\n4)Marks: %d",s->std,s->r,s->name,s->marks);
}
