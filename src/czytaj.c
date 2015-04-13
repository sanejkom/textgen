#include "tree.h"
#include<stdio.h>
#include<string.h>

int gen_tree( FILE *in, int n )
{
	char prefiks[100];
	char bufor[n][30];
	tree_t tree = NULL;
	
	int i;
        for( i = 1; i < n-1; i++ )
		fscanf( in, "%s", bufor[i] );
	/*
	*prefiks = *bufor[0];

	for( i = 1; i < n-1; i++ )
		strcat( prefiks, bufor[i] );

	for( i = 0; i < n-1; i++ )
		bufor[i] = bufor[i+1];

	tree_add( tree, prefiks, bufor[n-1] );
	*/
	while( fscanf( in, "%s", bufor[n-1] ) == 1 )
	{
		*prefiks = *bufor[0];

		for( i = 0; i < n-1; i++ )
			strcat( prefiks, bufor[i] );

		tree_add( tree, prefiks, bufor[n-1] );
	
		for( i = 0; i < n-1; i++ )
			*bufor[i] = *bufor[i+1];

	}

}
