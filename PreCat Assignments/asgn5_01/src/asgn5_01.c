/*
 ============================================================================
 Name        : asgn5_01.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
//float *avg,*total;
float average (int *p,int n);

int main(void)
{
	float avg;
	short int i,n;
	int eng[n],math[n],phy[n],chem[n],bio[n];
	printf("Please enter the number of students: \n");
	scanf("%d",&n);
	printf("please enter the marks of students in the subject 'ENGLISH'\n");
	for(i=0;i<=n-1;i++)
	{
		scanf("%d",&eng[i]);

	}
	avg=average(&eng,n);
	printf("the avg marks in ENGLISH are = %.2f\n",avg);
	printf("please enter the marks of students in the subject 'MATHEMATICS'\n");
		for(i=0;i<=n-1;i++)
		{
			scanf("%d",&math[i]);

		}
		avg=average(&math,n);
			printf("the avg marks in MATHEMATICS are = %.2f\n",avg);
	printf("please enter the marks of students in the subject 'PHYSICS'\n");
		for(i=0;i<=n-1;i++)
		{
			scanf("%d",&phy[i]);

		}
		avg=average(&phy,n);
			printf("the avg marks in PHYSICS are = %.2f\n",avg);
	printf("please enter the marks of students in the subject 'CHEMISTRY'\n");
		for(i=0;i<=n-1;i++)
		{
			scanf("%d",&chem[i]);
		}
		avg=average(&chem,n);
			printf("the avg marks in CHEMISTRY are = %.2f\n",avg);
	printf("please enter the marks of students in the subject 'BIOLOGY'\n");
		for(i=0;i<=n-1;i++)
		{
			scanf("%d",&bio[i]);

		}
		avg=average(&bio,n);
					printf("the avg marks in biology are = %.2f\n",avg);
	/*for(i=0;i<=n-1;i++)
	{
			printf("%d\n",eng[i]);

	}*/
	return EXIT_SUCCESS;
}

float average (int *p,int n)
{
	short int i;
	float avg;
	int total=0;
	for(i=0;i<=n-1;i++)
	{
		total=total+ *p;
		p++;

	}
	avg=(total/n) ;
	return avg;
}













