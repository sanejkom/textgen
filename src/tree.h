#ifndef _TREE_H_
#define _TREE_H_

typedef struct node
{
    char *prefiks;
    struct str_tab *sufiks;
    struct dyn_tab *liczba_suf;
    int wyst;
    struct node *left;
    struct node *right;
} *tree_t;

struct dyn_tab
{
	int *t;
	int size;
	int n;
};

struct str_tab
{
	char **t;
	int size;
	int n;
};

struct dyn_tab * dyn_tab_init( int initial_size );

void dyn_tab_add( struct dyn_tab * t, int x );

#endif // _TREE_H_
