/*
 ============================================================================
 Name        : asgn_1.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc,char *argv[])
{
	char *cPtr= strtok(argv[1],",");
	while(cPtr!=NULL)
	{
		printf("%s ",cPtr);
		cPtr=strtok(NULL,",");
	}
	return EXIT_SUCCESS;
}
