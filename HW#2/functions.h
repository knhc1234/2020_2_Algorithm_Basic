// functions.h

#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include "Headers.h"

// from_File.c
void B_tree_R_I_D_from_File(nptr_pck package, char FileName[], char what);

// retrieval.c
void retrieval(nodeptr curr, char CompName[]);

// B_tree_Insertion.c
int  B_tree_Insertion(nptr_pck package, char CompName[], char from);

// B_tree_Deletion.c
void B_tree_Deletion(nptr_pck package, char CompName[]);

// del_arranging.c
void leaf_del_arranging(nodeptr* curr, int loc);

// balancing_after_del.c
void balancing_after_del(nptr_pck package, nodeptr* curr, stk_pck st_package, del_pck d_pck);

// redistribution.c
void redistribution(nodeptr* prnt_of_curr, int bwn);

// merging.c
void merging(nptr_pck package, nodeptr* prnt_of_curr, int bwn);

// finding.c
int  leaf_n_del_node_finding(nodeptr* curr, char CompName[], stk_pck package, char what);
int  successor_node_finding (nodeptr* curr, stk_pck package, int curr_loc);
int  finding_sibling		(fmy_ptr fmy);

// print.c
void SP_console(nodeptr Root);
void SP_to_File(nodeptr curr);
void SP_console_to_File(nodeptr curr, FILE* fp);
void fill_cnt_check(nodeptr curr);
void ptr_cnt_check(nodeptr curr);

// stk.c
void stk_push (stk_pck package, nodeptr* push);
void stk_pop  (stack* stk, nodeptr* pop);
void stk_print(stack stk);

// name_extracting.c
void name_extracting(char menu[], char name[], int name_len);

#endif	// FUNCTIONS_H