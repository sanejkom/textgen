#include "tree.h"
#include "gen.h"
#include<time.h>
#include<string.h>
#include<stdlib.h>
#include<stdio.h>

void gen_text( tree_t head, int s, int a, int n )
{
	tree_t leaf = NULL;
	char *tail = malloc( 50 * sizeof( char ) );
	char *suf = malloc( 20 * sizeof( char ) );
	int slowa = 0;
	int akap = 1;
	char *tmp[n-1];
	FILE *out = fopen( "wynik.txt", "rw" );

	strcpy( tail, head->prefiks );
	fprintf( out, "\t%s ", tail );
	int i;
	int j;
	int x;
	for( i = 0; i < n-1; i++ )
	{
		tmp[i] = malloc( 20 * sizeof( char ) );
		//fscanf( out, "%s", tmp[i] );
	}
	tmp[0] = "wagi ";
	tmp[1] = "do ";
	tmp[2] = "wyroku. ";
	slowa += n-1;

	while( slowa < s )
	{
		if( slowa % ( s/a ) == 0 && akap < a )
		{
			fprintf( out, "\n\t" );
			akap++;
		}

		leaf = tree_search( head, tail );

		j = 0;
		srand(time(NULL));
		x = 1 + ( rand() / RAND_MAX ) * (leaf->wyst - 1);
		while( x > 0 )
		{
			//x -= leaf->liczba_suf->t[j];
			x -= leaf->liczba_suf[j];
			if( x <= 0 )
				//strcpy( suf, leaf->sufiks->t[j] );
				strcpy( suf, leaf->sufiks[j] );
			j++;
		}

		for( i = 0; i < n-2; i++ )
			strcpy( tmp[i], tmp[i+1] );

		strcpy( tmp[n-1], suf );
		strcpy( tail, tmp[0] );
		for( i = 1; i < n-1; i++ )
		{
			strcat( tail, tmp[i] );
			strcat( tail, " " );
		}

		fprintf( out, "%s ", suf );
		slowa++;
	}
}
