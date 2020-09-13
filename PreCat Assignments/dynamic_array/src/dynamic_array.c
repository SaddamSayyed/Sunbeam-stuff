/*
 ============================================================================
 Name        : dynamic_array.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int *p;
	int n,i;
	printf("plz enter the no of elements\n");
	scanf("%d",&n);
	p=(int *)malloc(n*sizeof(int));
	if(p==NULL)
	{
		printf("Memory not allocated\n");
		exit(0);
	}
	else
	{
		printf("memory allocation successful\nenter the elements");
		for(i=0;i<n;i++)
		{
			scanf("%d",&p[i]);
		}
		for(i=0;i<n;i++)
				{
					printf("%d\t",p[i]);
				}
		free(p);
	}

	return EXIT_SUCCESS;
}
