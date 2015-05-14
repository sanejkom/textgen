#include<stdio.h>
#include<getopt.h>
#include<stdlib.h>
#include"wejscie.h"
#include"tree.h"
#include"gen.h"

int main( int argc, char **argv )
{
	int opt;
	FILE *in = NULL;
	int slowa = 200;
	int akapity = 3;
	int ngram = 2;
	char *program = argv[0];
	FILE *posin = NULL;
	FILE *posout = NULL;
	//tree_t head = malloc( sizeof( head ) );
	tree_t head = NULL;

	while(( opt = getopt( argc, argv, "f:s:a:n:p:g:" )) != -1 )
		switch( opt )
		{
			case 'f':
				in = fopen( optarg, "r" );
				break;
			case 's':
				slowa = atoi( optarg );
				break;
			case 'a':
				akapity = atoi( optarg );
				break;
			case 'n':
				ngram = atoi( optarg );
				break;
			/*case 'p':
				posin = optarg;
				break;
			case 'g':
				posout = optarg;*/
			default:
				fprintf( stderr, "%s:uzycie", program );
		}

	//tree_init();
	//FILE *in = argc > 1 ? fopen( argv[1], "r" ) : stdin;
	if( in != NULL )
		head = gen_tree( in, head, ngram );
	
	//if( posout != NULL )
		//gen_data( posout );
	
	//if( posin != NULL )
		//gen_tree_data( posin );

	

	gen_text( head, slowa, akapity, ngram );

	//gen_stat();

	if( in != NULL )
		fclose( in );

	if( posin != NULL )
		fclose( posin );

	if( posout != NULL )
		fclose( posout );
	return 0;
}
