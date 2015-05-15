#ifndef _TREE_H_
#define _TREE_H_

typedef struct node
{
	char *prefiks;
	//struct str_tab *sufiks;
	//struct dyn_tab *liczba_suf;
	char **sufiks;
	char liczba_suf[20];
	int wyst;
	struct node *left;
	struct node *right;
} *tree_t, node_t;

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

struct dyn_tab * dyn_tab_init( int init_size );

struct dyn_tab * dyn_tab_resize( struct dyn_tab *t );

void dyn_tab_add( struct dyn_tab * t, int x );

struct str_tab * str_tab_resize( struct str_tab *t );

struct str_tab * str_tab_init( int init_size );

tree_t tree_add( tree_t t, char *pref, char *suf );

void sufiks_add( tree_t n, char *suf );

tree_t tree_search( tree_t t, char *szuk );

#endif // _TREE_H_
