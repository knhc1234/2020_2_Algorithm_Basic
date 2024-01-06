// node_finding.c

#include "functions.h"

int leaf_n_del_node_finding(nodeptr* curr, char CompName[], stk_pck package, char what)
{
	nodeptr temp_ptr = NULL;

	int i = 0;

	do {
		for (i = 0; i < (*curr)->fill_cnt; i++) {
			if (strcmp(CompName, (*curr)->rec[i].name) < 0) { break; }
			else if (strcmp(CompName, (*curr)->rec[i].name) == 0) {

				switch (what) {
				case 'l': return TRUE;
				case 'd': return i;
				default:
					printf("설계상의 오류입니다.\n");
					printf("프로그램을 종료합니다.\n");
					exit(1);
				}	// switch (what)

			}	// else if (CompName)
		}	// for (i)

		temp_ptr = (*curr)->ptr[i];

		if (temp_ptr) {
			stk_push(package, curr);
			(*curr) = temp_ptr;
		}	// if ()

	} while (temp_ptr);

	return FALSE;
}

int successor_node_finding(nodeptr* curr, stk_pck package, int curr_loc)
{
	nodeptr orgn	 = *curr;
	nodeptr temp_ptr = NULL;

	// 오른쪽 포인터
	temp_ptr = (*curr)->ptr[curr_loc + 1];
	
	stk_push(package, curr);
	(*curr) = temp_ptr;

	do {
		temp_ptr = (*curr)->ptr[0];

		if (temp_ptr) {
			stk_push(package, curr);
			(*curr) = temp_ptr;
		}	// if ()

	} while (temp_ptr);

	// s를 d가 있던 위치에 넣기
	strcpy(orgn->rec[curr_loc].name, (*curr)->rec[0].name);
	orgn->rec[curr_loc].leng = (*curr)->rec[0].leng;

	return 0;
}

int finding_sibling(fmy_ptr fmy)
{
	nodeptr* prnt_of_curr = fmy->prnt;
	nodeptr* curr		  = fmy->curr;
	nodeptr* l_s		  = fmy->l_sbl;
	nodeptr* r_s		  = fmy->r_sbl;

	int i = 0;
	for (i = 0; i < (*prnt_of_curr)->fill_cnt + 1; i++) {
		if ((*prnt_of_curr)->ptr[i] == *curr) { break; }
	}	// for (i)

	if (i == 0) {
		*r_s = (*prnt_of_curr)->ptr[i + 1];
		*l_s = NULL;
	}	// if ()
	else if (i == (*prnt_of_curr)->fill_cnt) {
		*l_s = (*prnt_of_curr)->ptr[i - 1];
		*r_s = NULL;
	}	// else if ()
	else {
		// 0 < i <= (*prnt_of_curr)->fill_cnt
		*r_s = (*prnt_of_curr)->ptr[i + 1];
		*l_s = (*prnt_of_curr)->ptr[i - 1];
	}	// else

	return i;
}