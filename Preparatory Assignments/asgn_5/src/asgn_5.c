/*
 ============================================================================
 Name        : asgn_5.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

typedef struct date
{
	int dd;
	int mm;
	int yy;
}DATE;
typedef struct employee
{
	int id;
	char name[20];
	char add[10];
	int sal;
	DATE DOB;
	DATE DOJ;

}EMP;
void accept_info(EMP *p);
void display_info(const EMP *p);
int find_age(const EMP *p);
int find_exp(const EMP *p);
//int probation(const EMP *p);
DATE d={18,02,2020};
int main(void)
{
	EMP e;
	EMP *p=&e;
	accept_info(p);
	display_info(p);
	printf("\nAge : %d",find_age(p));
	printf("\nexp : %d Months",find_exp(p));
	return EXIT_SUCCESS;
}
/*int probation(const EMP *p,DATE d)
{
	if(p->DOJ.mm == 7||11||12)
	{
		if(p->DOJ.dd)
				d->dd=p->DOJ.dd;
		if(p->DOJ.mm==7)
			d->mm=10;
		else if(p->DOJ.mm==11)
			{
				d->mm=2;
				d->yy=p->DOJ.yy+1;
			}
		else if(p->DOJ.mm==12)
			{
				d->mm=3;
				d->yy=p->DOJ.yy+1;
			}

	}
	else if(p->DOJ.mm ==1||2)
	{
		d.dd=p->DOJ.dd;
		d.mm=p->DOJ.mm+3;
		d.yy=p->DOJ.yy;
	}
	else
		if(p->DOJ.mm ==10)
		{
			d->mm=1;
			d->yy=p->DOJ.yy+1;
		}
		else
		{
			d.dd=p->DOJ.dd;
			d.mm=p->DOJ.mm+3;
			d.yy=p->DOJ.yy;

		}


}*/
int find_age(const EMP *p)
{
	return(d.yy-p->DOB.yy);
}
int find_exp(const EMP *p)
{
	if(d.yy==p->DOJ.yy)
	{
		return(d.mm-p->DOJ.mm);
	}
	else
	{
		return (d.mm-1+(12-p->DOJ.mm)+(12*(d.yy-p->DOJ.yy-1)));
	}
}
void accept_info(EMP *p)
{
			printf("\nPlease enter EMP info\n1)EMP Id");
			scanf("%d",&p->id);
			scanf("%*c");
			printf("\n2)EMP Name:");
			fgets(p->name,20,stdin);
			printf("\n3)EMP Add:");
			fgets(p->add,20,stdin);
			printf("\n4)Salary:");
			scanf("%d",&p->sal);
			printf("\n5)Date Of Birth as dd/mm/yy:");
			scanf("%d %d %d",&p->DOB.dd,&p->DOB.mm,&p->DOB.yy);
			printf("\n5)Date Of Joining as dd/mm/yy:");
			scanf("%d %d %d",&p->DOJ.dd,&p->DOJ.mm,&p->DOJ.yy);
}
void display_info(const EMP *p)
{
	printf("\nEMP ID\t\tName\t\tAddress\t\tSallary\t\tBirth Date\t\tJoining Date\n");
	printf("\n%6d\t\t%10s\t\t%10s\t\t%6d\t\t%d/%d/%d\t\t%d/%d/%d\t\t"
			,p->id,p->name,p->add,p->sal,p->DOB.dd,p->DOB.mm,p->DOB.
			yy,p->DOJ.dd,p->DOJ.mm,p->DOJ.yy);
}
