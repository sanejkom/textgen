#include<cstdio>
#include<wejscie.h>

int main( int argc, char **argv )
{
    tree_init();
    FILE *in = argc > 1 ? fopen( argv[1], "r" ) : stdin;
	if( in == NULL ) {
		fprintf( stderr, "%s: Nie mogê czytaæ %s\n", argv[0], argv[1] );
		return 1;
	}
    tree_add( in );

	fclose( in );

    return 0;
}
