// find_node_trie.c 

#include "functions.h" 

int find_node_trie(nptr_pck package, char key[], int* val_i) 
{
	int i = 0; 

	package->curr = *(package->Root);
	package->prev = NULL; 

	if (package->curr == NULL) {
		return -1; 
	}	// if (root) 

	do {
		// search vertically by the next while stmt. 
		while (key[i] != '\0' && package->curr->ch == key[i]) {
			package->prev = package->curr;
			i++;
			package->curr = package->curr->below;
		}	// while () 

		// see if search completed with success. 
		if (package->curr->ch == '\0' && key[i] == '\0') {
			return i;
		}	// if () 

		// search horizontally by skipping over letters before it. 
		while (package->curr != NULL && package->curr->ch < key[i]) {
			package->prev = package->curr;
			package->curr = package->curr->right;
		}	// while () 

		// see if search has failed. 
		if (package->curr == NULL || package->curr->ch > key[i]) {
			*val_i = i;
			return -1;
		}	// if () 

	} while (1); 

	return 2; 
}