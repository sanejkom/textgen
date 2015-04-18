#include "tree.h"
#include "wejscie.h"
#include<string.h>

tree_t gen_tree( FILE *in, tree_t tree, int n )
{
	char prefiks[100];
	char bufor[n][30];
	
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
		strcpy( prefiks, bufor[0] );

		for( i = 0; i < n-1; i++ )
			strcat( prefiks, bufor[i] );

		tree_add( tree, prefiks, bufor[n-1] );
	
		for( i = 0; i < n-1; i++ )
			strcpy( bufor[i], bufor[i+1] );

	}
	return tree;
}
