/*
 ============================================================================
 Name        : asgn_2.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
void str_copy(char *d,char *s);
void str_cat(char *d,char *s);
int str_len(char *s);
void str_rev(char *d);
int str_cmp(const char *d,const char *s);
int main(void)
{
	char s[20]="sunbeaz";
	char d[20]="sunbeaM";
	printf("s : %s\n",s);
	printf("d : %s\n",d);
	int n = str_cmp(d,s);
	if(n>0)
		printf("\nStrings are Identical\n");
	else if(n<0)
		printf("\nStrings are not Identical\n");
	else
		printf("\nStrings are identical\n");
	printf("\t\tReturned Value is %d",n);
	//str_copy(d,s);
	//str_cat(s,d);
	//str_rev(d);
	//printf("\nafter rev\ns : %s\n",s);
	//printf("d : %s\n",d);
	n=strcmp(d,s);
	if(n==0)
			printf("\nlibrary function:\nStrings are Identical\nreturned value : %d",n);
		else
			printf("\nlibrary function:\nStrings are not Identical\nreturned value : %d",n);
	return EXIT_SUCCESS;
}
int str_cmp(const char *d,const char *s)
{
		while(*d)
		{
			if(*d!=*s)
			{
				break;
			}
			d++;s++;

		}
	return *(unsigned char*)d-*(unsigned char*)s;
}
void str_rev(char *d)
{
	int ld=str_len(d);
	char a[20];
	for(int i=0,j=ld-1;j>=0;j--)
		{
			a[i]=d[j];
			i++;
		}
	for(int i=0;i<ld;i++)
			d[i]=a[i];
}
void str_cat(char *d,char *s)
{
	int ld = str_len(d);
	int ls = str_len(s);
	for(int i=ld,j=0;j<ls;i++,j++)
	{
		d[i]=s[j];
	}
}
int str_len(char *s)
{
	char a;
	int i=0;
	do
	{
		a=s[i];
		i++;
	}while(a!=NULL);
	return(i-1);
}
void str_copy(char *d,char *s)
{
	int ls,ld,i;
	ls=str_len(s);
	ld=str_len(d);
	for(int i=0;i<ls;i++)
		d[i]=s[i];
	if(ld>ls)
	{
		for(i=ls;i<ld;i++)
			d[i]=NULL;
	}

}
