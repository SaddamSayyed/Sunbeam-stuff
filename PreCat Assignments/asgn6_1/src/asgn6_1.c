/*
 ============================================================================
 Name        : asgn6_1.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/*size_t s_len (const char *s);
void s_cpy (char *dest, char *src);
void s_upend (char *dest, char *src);*/
int main(void)
{
/*	puts(a);
	puts(b);
	printf("\n %s\n",b);*/
	/*printf("length of a = %d\t and b = %d\n",strlen(a),strlen(b));
	printf("used my function\nlength of a = %d\t and b = %d\n",s_len(a),s_len(b));*/
	//strcpy(c,a);
	//puts(c);
	//s_cpy(c,b);
	//printf("used my function\n");
	//puts(c);
	//strcat(a,a);
	//s_upend(a,b);
	/*i=strcmp(a,b);
	if(i==0)
		printf("the strings are equal\n");
	else
		printf("the strings are not equal\n");
	printf("\n i=%d ch= %c\n",i,i);*/

		char str1[20] = "this is stricmp";
		char str2[20] = "THIS IS STRICMP";
		int n;
		n = stricmp(str1, str2);
		if( n == 0)
			printf("The strings str1 and str2 are same ");
		else if(n == -1)
			printf("The string str1 is lesser than str2");
		else
			printf("The string str1 is greater than str2");

		return EXIT_SUCCESS;
}
/*
int s_cmp(char *s1,char *s2)
{
	int i;
	for(i=0;*s1!='\0'||*s2!=0;++s1,++s2)
	{
		if(*s1==*s2)
			i=0;
		else if(*s1<*s2)
			i=-1;
		else if(*s1>*s2)
			i=1;
	}
	return i;
}
size_t s_len (const char *s)
{
	int i;
	for(i=0;*s!='\0';i++)
	{
		s++;
	}
	return i;
}
void s_cpy (char *dest, char *src)
{
	int i;
	for(i=0;*src!='\0';i++)
	{
		*dest=*src;
		src++;dest++;
	}
}
void s_upend (char *dest, char *src)
{
	int i;

	for(i=strlen(dest);*src!='\0';i++,++src)
	{
		dest[i]=*src;
	}
}
*/
