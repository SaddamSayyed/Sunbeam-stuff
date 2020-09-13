/*
 ============================================================================
 Name        : asgn1_1.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int main(void)
{
	printf("The ranges of different data types is as follows :\n");
	printf("\n--------------------------------------------------------------------------------------------\n");
	printf("Data Type\tSize\tFormat Specifier\tRange\n");
	printf("----------------------------------------------------------------------------------------------\n");
	printf("char  \t\t%d\t\t%%c\t\t%d to %d",sizeof(char),SCHAR_MIN,SCHAR_MAX);
	printf("\n--------------------------------------------------------------------------------------------\n");
	printf("unsigned char  \t%d\t\t%%c\t\t 0 to %d",sizeof(unsigned char),UCHAR_MAX);
	printf("\n--------------------------------------------------------------------------------------------\n");
	printf("int  \t\t%d\t\t%%d\t\t%d to %d",sizeof(int),INT_MIN,INT_MAX);
	printf("\n--------------------------------------------------------------------------------------------\n");
	printf("unsigned int  \t%d\t\t%%u\t\t 0 to %lu",sizeof(unsigned int),UINT_MAX);
	printf("\n--------------------------------------------------------------------------------------------\n");
	printf("short int  \t%d\t\t%%hd\t\t%d to %d",sizeof(short int),SHRT_MIN,SHRT_MAX);
	printf("\n--------------------------------------------------------------------------------------------\n");
	printf("unsigned short   %d\t\t%%hu\t\t 0 to %lu",sizeof(unsigned short int),USHRT_MAX);
	printf("\n--------------------------------------------------------------------------------------------\n");
	printf("long int  \t%d\t\t%%ld\t\t%ld to %ld",sizeof(long int),LONG_MIN,LONG_MAX);
	printf("\n--------------------------------------------------------------------------------------------\n");
	printf("unsigned long   %d\t\t%%lu\t\t 0 to %lu",sizeof(unsigned long int),ULONG_MAX);
	printf("\n--------------------------------------------------------------------------------------------\n");
	return EXIT_SUCCESS;
}
