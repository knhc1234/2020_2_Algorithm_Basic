// redistribution.c

#include "functions.h"

void redistribution(nodeptr* prnt_of_curr, int bwn)
{
	tbig_node bnode;

	nodeptr poc	  = *prnt_of_curr;
	nodeptr left  = poc->ptr[bwn];
	nodeptr right = poc->ptr[bwn + 1];

	int all_rec_num = (left->fill_cnt + right->fill_cnt + 1);
	int cen_loc		= all_rec_num / 2;
	int left_num	= cen_loc;
	int right_num	= all_rec_num - left_num - 1;

	int i = 0;
	int j = 0;
	int k = left_num;
	int l = right_num;

	for (i = 0; i < left->fill_cnt; i++) {
		strcpy(bnode.rec[i].name, left->rec[i].name);
		bnode.rec[i].leng = left->rec[i].leng;
		bnode.ptr[i]	  = left->ptr[i];
	}	// for (i)
	    bnode.ptr[i]	  = left->ptr[i];

	strcpy(bnode.rec[i].name, poc->rec[bwn].name);
	bnode.rec[i].leng = poc->rec[bwn].leng;

	for (j = 0, i = i + 1; j < right->fill_cnt; j++, i++) {
		strcpy(bnode.rec[i].name, right->rec[j].name);
		bnode.rec[i].leng = right->rec[j].leng;
		bnode.ptr[i]	  = right->ptr[j];
	}	// for (j)
		bnode.ptr[i]	  = right->ptr[j];

	strcpy(poc->rec[bwn].name, bnode.rec[cen_loc].name);
	poc->rec[bwn].leng = bnode.rec[bwn].leng;

	// left -> rec : 0 ~ (cen_loc - 1), ptr : 0 ~ (cen_loc)
	for (i = 0; i < cen_loc; i++) {
		strcpy(left->rec[i].name, bnode.rec[i].name);
		left->rec[i].leng = bnode.rec[i].leng;
		left->ptr[i]		  = bnode.ptr[i];
	}	// for (i)
		left->ptr[i]		  = bnode.ptr[i];

		left->fill_cnt	  = left_num;

	for (int m = left_num + 1; m < PTR_NUM; m++) {
		left->ptr[m]		  = NULL;
	}	// for (m)

	// right-> rec : (cen_loc + 1) ~ (all_rec_num - 1),
	//		   ptr : (cen_loc + 1) ~ (all_rec_num)
	for (i = cen_loc + 1, j = 0; j < right_num; j++, i++) {
		strcpy(right->rec[j].name, bnode.rec[i].name);
		right->rec[j].leng = bnode.rec[i].leng;
		right->ptr[j]	   = bnode.ptr[i];
	}	// for (i, j)
		right->ptr[j]	   = bnode.ptr[i];

		right->fill_cnt	   = right_num;

	for (int m = right_num + 1; m < PTR_NUM; m++) {
		right->ptr[m] = NULL;
	}	// for (m)
}