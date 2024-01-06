// merging.c

#include "functions.h"

void merging(nptr_pck package, nodeptr* prnt_of_curr, int bwn)
{
	nodeptr poc		 = *prnt_of_curr;
	nodeptr left	 = poc->ptr[bwn];
	nodeptr right	 = poc->ptr[bwn + 1];
	nodeptr temp_ptr = package->temp_ptr;

	int i = 0;
	int j = 0;

	temp_ptr		   = NULL;
	temp_ptr		   = (nodeptr)malloc(sizeof(node));
	temp_ptr->fill_cnt = REC_NUM;

	for (i = 0; i < left->fill_cnt; i++) {
		strcpy(temp_ptr->rec[i].name, left->rec[i].name);
		temp_ptr->rec[i].leng = left->rec[i].leng;
		temp_ptr->ptr[i]		  = left->ptr[i];
	}	// for (i)
		temp_ptr->ptr[i]		  = left->ptr[i];

	strcpy(temp_ptr->rec[i].name, poc->rec[bwn].name);
	temp_ptr->rec[i].leng = poc->rec[bwn].leng;

	for (j = 0, i = i + 1; j < right->fill_cnt; j++, i++) {
		strcpy(temp_ptr->rec[i].name, right->rec[j].name);
		temp_ptr->rec[i].leng = right->rec[j].leng;
		temp_ptr->ptr[i]		  = right->ptr[j];
	}	// for (j)
		temp_ptr->ptr[i]		  = right->ptr[j];

	free(left);
	free(right);
	
		poc->ptr[bwn]	 = temp_ptr;

	for (int k = bwn; k < poc->fill_cnt; k++) {
		strcpy(poc->rec[k].name, poc->rec[k + 1].name);
		poc->rec[k].leng = poc->rec[k + 1].leng;
		// free?
		poc->ptr[k + 1]  = poc->ptr[k + 2];
	}	// for (k)

		poc->fill_cnt--;

	for (int l = poc->fill_cnt + 1; l < PTR_NUM; l++) {
		poc->ptr[l] = NULL;
	}	// for (l)
}