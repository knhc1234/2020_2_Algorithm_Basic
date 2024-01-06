// type_record.h

#ifndef TYPE_RECORD_H
#define TYPE_RECORD_H

#include "GC.h"

typedef struct _rec {
	char name[COMP_NAME_LEN - 1];	// key value
	int  leng;
} type_rec;

typedef struct anode* nodeptr;
typedef struct anode {
	nodeptr  ptr[PTR_NUM];
	type_rec rec[REC_NUM];
	int		 fill_cnt;
} node;

typedef struct big_node {
	nodeptr  ptr[PTR_NUM + 1];
	type_rec rec[REC_NUM + 1];
} big_node;

typedef struct tbig_node {
	nodeptr  ptr[(3 * CAPACITY_ORDER) + 1];
	type_rec rec[(3 * CAPACITY_ORDER)];
} tbig_node;

typedef struct astack* stack;
typedef struct astack {
	nodeptr ptr;
	stack   parent;
} stk_rec;

typedef struct stk_pack* stk_pck;
typedef struct stk_pack {
	stack* stk;
	stack* temp_stk;
} stk_pck_rec;

typedef struct nptr_pack* nptr_pck;
typedef struct nptr_pack {
	nodeptr* Root;
	nodeptr  temp_ptr;
	nodeptr  new_Root;
} nptr_;

typedef struct del_inf* del_pck;
typedef struct del_inf {
	int* rdst_cnt;
	int* mrg_cnt;
} del_rec;

typedef struct family* fmy_ptr;
typedef struct family {
	nodeptr* prnt;
	nodeptr* curr;
	nodeptr* l_sbl;
	nodeptr* r_sbl;
} fmy_rec;

#endif	// TYPE_RECORD_H