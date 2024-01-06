// type_record.h

#ifndef TYPE_RECORD_H
#define TYPE_RECORD_H

#include "GC.h" 

typedef struct node *nodeptr; 
typedef struct node {
	char ch;		// character in this node 
	nodeptr right;	// a horizontal pointer 
	nodeptr below;	// a vertical pointer 
} nodetype;

typedef struct nptr_pack* nptr_pck;
typedef struct nptr_pack {
	nodeptr* Root; 
	nodeptr curr; 
	nodeptr prev; 
} nptr_;

#endif	// TYPE_RECORD_H