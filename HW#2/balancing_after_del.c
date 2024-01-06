// balancing_after_del.c

#include "functions.h"

void balancing_after_del(nptr_pck package, nodeptr* curr, stk_pck st_package, del_pck d_pck)
{
	nodeptr* Root		  = package->Root;
	nodeptr  temp_ptr	  = package->temp_ptr;
	nodeptr  new_Root	  = package->new_Root;
	nodeptr  prnt_of_curr = NULL;
	nodeptr  r_sibling	  = NULL;
	nodeptr  l_sibling	  = NULL;

	stack* stk = st_package->stk;

	fmy_ptr fmy = (fmy_ptr)malloc(sizeof(fmy_rec));
	
	int i = 0;

	int curr_loc  = 0;
	int *rdst_cnt = d_pck->rdst_cnt;
	int *mrg_cnt  = d_pck->mrg_cnt;

	fmy->prnt  = &prnt_of_curr;
	fmy->curr  = curr;
	fmy->l_sbl = &l_sibling;
	fmy->r_sbl = &r_sibling;

	while (1) {

		if (*curr == *Root) {
			if ((*curr)->fill_cnt == 0) {
				(*Root) = (*Root)->ptr[0];
				// free previous root node
			}	// if ()
			return;
		} // if ()

		// curr != Root
		if ((*curr)->fill_cnt >= CAPACITY_ORDER) { return; }

		stk_pop(stk, &prnt_of_curr);

		curr_loc = finding_sibling(fmy);
		
		// redistribution
		if (r_sibling != NULL && r_sibling->fill_cnt > CAPACITY_ORDER) {
			// (i)th record between curr & r_sibling
			redistribution(&prnt_of_curr, curr_loc);
			(*rdst_cnt)++;
			return;
		} else if (l_sibling != NULL && l_sibling->fill_cnt > CAPACITY_ORDER) {
			// (i-1)th record between l_sibling & curr
			redistribution(&prnt_of_curr, curr_loc - 1);
			(*rdst_cnt)++;
			return;
		} else {

			// merging
			if (r_sibling != NULL) {
				// (i)th record between curr & r_sibling
				merging(package, &prnt_of_curr, curr_loc);
				(*mrg_cnt)++;
			} else {
				// (i-1)th record between l_sibling & curr
				merging(package, &prnt_of_curr, curr_loc - 1);
				(*mrg_cnt)++;
			}	// else

			*curr = prnt_of_curr;

		}	// else

	}	// while (1)

	
}