// insert_trie.c 

#include "functions.h" 

void insert_trie(nptr_pck package, char key[])
{
	nodeptr* Root		= package->Root; 

	nodeptr curr		= NULL;
	nodeptr prev		= NULL;

	nodeptr temp_ptr	= NULL;

	int val_i = 0;

	int i = 0; 

	i = find_node_trie(package, key, &val_i);

	curr = package->curr;
	prev = package->prev;

	if (i != -1) { return; }

	// nothing in the trie, insert the first one. 
	if ((*Root) == NULL) {
		*Root			= (nodeptr)malloc(sizeof(nodetype)); 
		(*Root)->ch		= key[0];
		(*Root)->right	= NULL; 
		(*Root)->below	= NULL; 

		hang_down(key, *Root, 1);

		return;
	}	// if (i)

	temp_ptr		= (nodeptr)malloc(sizeof(nodetype));
	temp_ptr->ch	= key[val_i];
	temp_ptr->below = NULL;
	temp_ptr->right = curr; 

	if (prev == NULL) { 
		temp_ptr->right = (*Root); 
		*Root			= temp_ptr; 

		hang_down(key, *Root, i + 1);

		return;
	}	// if (prev) 

	else if (prev->below == curr && curr != NULL) {
		prev->below = temp_ptr;
	}	// else if (prev->below) 

	else if (prev->right == curr) {
		prev->right = temp_ptr;
	}	// else if () 

	else {
		free(temp_ptr); 
		printf("Logic error in insert_trie.\n"); 

		return;
	}	// else 

	hang_down(key, temp_ptr, val_i + 1);

	return; 
}