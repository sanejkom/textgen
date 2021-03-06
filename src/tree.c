#include "tree.h"
#include<stdlib.h>
#include<string.h>

struct dyn_tab * dyn_tab_init( int init_size )
{
	struct dyn_tab * ns = malloc( sizeof *ns );
	if( ns == NULL )
        return NULL;
	ns->t = malloc( init_size * sizeof * ns->t );
	if( ns->t == NULL )
	{
        	free( ns );
        	return NULL;
	}
	ns->size = init_size;
	ns->n = 0;
	return ns;
}

struct dyn_tab * dyn_tab_resize( struct dyn_tab *t )
{
	int *np = realloc( t->t, 2*t->size*sizeof *t->t );
	//if( np == NULL )
	//	return NULL;
	t->size *= 2;
	t->t = np;
	return t;
}

struct str_tab * str_tab_resize( struct str_tab *t )
{
	char **np = realloc( t->t, 2*t->size*sizeof **t->t );
	//if( np == NULL )
	//	return NULL;
	t->size *= 2;
	t->t = np;
	return t;
}

void dyn_tab_add( struct dyn_tab * sp, int x )
{
	if( sp->size <= sp->n )
		dyn_tab_resize( sp );
	sp->t[sp->n] = x;
	sp->n++;
}

struct str_tab * str_tab_init( int init_size )
{
	struct str_tab * ns = malloc( sizeof *ns );
	//if( ns == NULL )
        //	return NULL;
	ns->t = malloc( init_size * sizeof * ns->t );
	//if( ns->t == NULL )
	//{
        //	free( ns );
        //	return NULL;
	//}
	ns->size = init_size;
	ns->n = 0;
	return ns;
}

tree_t tree_add( tree_t t, char *pref, char *suf )
{
	if( t == NULL )
	{
		node_t *n = malloc( sizeof *n );
		n->prefiks = malloc( (strlen(pref) + 1) * sizeof( char ) );
		//n->sufiks = str_tab_init( 10 );
		n->sufiks = malloc( 20 * 20 * sizeof *n->sufiks );
		//n->liczba_suf = dyn_tab_init( 10 );
		n->wyst = 0;
		int i;
		for( i = 0; i < 20; i++ )
		{
			n->liczba_suf[i] = 0;
			//n->sufiks[i] = malloc( 20 * sizeof( char ) );
			n->sufiks[i] = NULL;
		}
		strcpy( n->prefiks, pref );
		n->left = n->right = NULL;
		sufiks_add( n, suf );
		return n;
	}
	else if( strcmp( t->prefiks, pref ) > 0 )
	{
		t->left = tree_add( t->left, pref, suf );
		return t;
	}
	else if( strcmp( t->prefiks, pref ) < 0 )
	{
		t->right = tree_add( t->right, pref, suf );
		return t;
	}
	else
	{
		sufiks_add( t, suf );
		return t;
	}
}

/*void sufiks_add( tree_t n, char *suf )
{
	int i = 0;
	while( strcmp( n->sufiks->t[i], suf) != 0 && i < n->wyst )
		i++;
	if( i < n->wyst )
		(n->liczba_suf->t[i])++;
	else
	{
		if( n->sufiks->size <= n->sufiks->n )
			if( n->sufiks = str_tab_resize( n->sufiks ) != NULL )
				return;
	n->sufiks->t[n->sufiks->n] = malloc( (strlen(suf) + 1) * sizeof( char ) );
	strcpy( n->sufiks->t[n->sufiks->n], suf);
	n->sufiks->n++;
	dyn_tab_add( n->liczba_suf, 1);
    }
}*/

void sufiks_add( tree_t n, char *suf )
{
        int i = 0;
        while( ( strcmp( n->sufiks[i], suf ) != 0 ) && ( i < n->wyst ) )
                i++;
        if( i < n->wyst )
                (n->liczba_suf[i])++;
        else
        {
                int j = 0;
		while( n->liczba_suf[j] == 0 )
			j++;
		//n->sufiks[j] = malloc( (strlen(suf) + 1) * sizeof( char ) );
		strcpy( n->sufiks[i], suf);
		n->liczba_suf[i] = 1;
		(n->wyst)++;
        }
}

tree_t tree_search( tree_t t, char *szuk )
{
	if( strcmp( t->prefiks, szuk ) < 0 )
		tree_search( t->right, szuk );

	else if( strcmp( t->prefiks, szuk ) > 0 )
		tree_search( t->left, szuk );

	return t;
}
