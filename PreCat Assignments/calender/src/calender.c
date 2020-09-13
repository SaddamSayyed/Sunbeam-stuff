/*
 ============================================================================
 Name        : calender.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
int odd_days_of_month(int);
int odd_days_of_year(int);
int check_leap_year(int);
int main(void)
{
	int d,m,y,odd=0;
	printf("Please enter the date ( day,month and year respectively)\n");
	scanf("%d %d %d",&d,&m,&y);
	odd=odd_days_of_year(y-1);
	//printf("\nodd days of year = %d",odd);
	odd=odd+odd_days_of_month(m-1);
	//printf("\nodd days of month = %d",odd);

	odd=odd+(d-1)+check_leap_year(y);
	odd=odd%7;
	//printf("\nover all odd days = %d\n",odd);
	switch(odd)
	{
	case 1:
				printf(" on the entered date, day is MONDAY.");
					break;
	case 2:
				printf(" on the entered date, day is TUESDAY.");
					break;
	case 3:
				printf(" on the entered date, day is WEDNESDAY.");
					break;
	case 4:
				printf(" on the entered date, day is THURSDAY.");
					break;
	case 5:
				printf(" on the entered date, day is FRIDAY.");
					break;
	case 6:
				printf(" on the entered date, day is SATURDAY.");
					break;
	case 0:
				printf(" on the entered date, day is SUNDAY.");
					break;
	}
	return EXIT_SUCCESS;
}

int odd_days_of_year(int y)
{
	int n,odd;
	n=y/4;
	odd=n*366;
	odd=odd+(y-n)*365;
	odd=odd%7;
	return odd;

}
int odd_days_of_month(int n)
{
	int x=n;
		int days=0;
		for(;x<=n && x!=0;--x)
		{
			if(x==1 || x==3 || x==5 ||x==7 || x==8 || x==10 ||x==12)
				days=days+31;

			if(x==4 || x==9 || x==11 ||x==6)
				days=days+30;

			if(x==2)
				days=days+28;
		}
		days=days%7;
	return days;

}

int check_leap_year(int y)
{
	if((y%4==0 && y%100!=0)|| y%400==0)
	{
		//printf("\ncurrent year is leap year\n");
			return 1;
	}
	else
	{
		//printf("\ncurrent year is not a leap year\n");
		return 0;
	}

}
