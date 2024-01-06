// del_arrangin.c

#include "functions.h"

void leaf_del_arranging(nodeptr* curr, int loc)
{
	nodeptr arrn = *curr;

	int i = 0;

	for (i = loc; i < arrn->fill_cnt; i++) {
		if (i + 1 == arrn->fill_cnt) {
			strcpy(arrn->rec[i].name, "");
			arrn->rec[i].leng = 0;
		}	// if ()
		else {
			strcpy(arrn->rec[i].name, arrn->rec[i + 1].name);
			arrn->rec[i].leng = arrn->rec[i + 1].leng;
		}	// else
		
	}	// for (i)

	for (int j = 0; j < PTR_NUM; j++) {
		arrn->ptr[j] = NULL;
	}	// for (j)
	
	arrn->fill_cnt--;
}