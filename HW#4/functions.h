// functions.h

#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include "Headers.h"

// from_File.c 
void Trie_I_from_File(nptr_pck package, char FileName[]); 
void compare_to_the_Original(char Original[], char Print_FileName[]); 

// insert_trie.c 
void insert_trie(nptr_pck package, char key[]);

// find_node_trie.c 
int find_node_trie(nptr_pck package, char key[], int* val_i);

// hang_down.c 
void hang_down(char key[], nodeptr temp_ptr, int i); 

// print.c 
void recursive_print_to_File(nodeptr curr, FILE* fp, char pre[], int pre_index); 
void print_to_File(nodeptr curr, char Print_FileName[]);

// name_extracting.c
void name_extracting(char menu[], char name[], int name_len);

// spelling_correction.c 
void spelling_correction(nodeptr curr, char key[]);

#endif	// FUNCTIONS_H