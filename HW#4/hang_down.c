// hang_down.c 

#include "functions.h" 

void hang_down(char key[], nodeptr temp_ptr, int i)
{
	nodeptr new_nodeptr = NULL; 

	while (key[i] != '\0') {
		new_nodeptr			= (nodeptr)malloc(sizeof(nodetype));
		new_nodeptr->ch		= key[i++];
		new_nodeptr->right	= NULL; 
		new_nodeptr->below	= NULL; 

		temp_ptr->below = new_nodeptr; 
		temp_ptr		= new_nodeptr; 
	}	// while () 

	new_nodeptr			= (nodeptr)malloc(sizeof(nodetype)); 
	new_nodeptr->ch		= '\0';	// end of marker sign 
	new_nodeptr->right	= NULL; 
	new_nodeptr->below	= NULL; 

	temp_ptr->below = new_nodeptr; 

	return; 
}