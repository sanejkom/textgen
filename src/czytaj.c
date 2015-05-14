//#include "tree.h"
#include "wejscie.h"
#include<string.h>
#include<stdlib.h>

tree_t gen_tree( FILE *in, tree_t tree, int n )
{
	char prefiks[100];
	char *bufor[n];
	char *tmp = calloc( 30, sizeof*tmp );
	
	int i;
        for( i = 0; i < n; i++ )
	{
		bufor[i] = malloc( 30 * sizeof( char ) );
		fscanf( in, "%s", bufor[i] );
	}
	
	//*prefiks = *bufor[0];
	strcpy( prefiks, bufor[0] );
	strcat( prefiks, " " );

	for( i = 1; i < n-1; i++ )
	{
		strcat( prefiks, bufor[i] );
		strcat( prefiks, " " );
	}

	for( i = 0; i < n-1; i++ )
		strcpy( bufor[i], bufor[i+1] );

	tree = tree_add( tree, prefiks, bufor[n-1] );
	
	while( fscanf( in, "%s", tmp ) == 1 )
	{
		strcpy( bufor[n-1], tmp );

		strcpy( prefiks, bufor[0] );

		for( i = 1; i < n-1; i++ )
		{
			strcat( prefiks, bufor[i] );
			strcat( prefiks, " " );
		}

		tree = tree_add( tree, prefiks, bufor[n-1] );
	
		for( i = 0; i < n-1; i++ )
			strcpy( bufor[i], bufor[i+1] );

	}
	return tree;
}
