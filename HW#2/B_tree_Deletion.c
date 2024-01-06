// B_tree_Deletion.c

#include "functions.h"

void B_tree_Deletion(nptr_pck package, char CompName[])
{
	nodeptr* Root = package->Root;
	nodeptr  curr = *Root;

	stack   stk		 = NULL;
	stack   temp_stk = NULL;
	stk_pck stk_SET  = (stk_pck)malloc(sizeof(stk_pck_rec));

	int rdst_cnt = 0;
	int mrg_cnt  = 0;

	del_pck del_SET = (del_pck)malloc(sizeof(del_rec));

	int del_node_loc = -1;

	int i = 0;
	
	stk_SET->stk		  = &stk;
	stk_SET->temp_stk = &temp_stk;

	del_SET->rdst_cnt = &rdst_cnt;
	del_SET->mrg_cnt  = &mrg_cnt;

	if (!curr) {
		printf("\tB-tree�� ����ֽ��ϴ�.\n");
		return;
	}

	del_node_loc = leaf_n_del_node_finding(&curr, CompName, stk_SET, 'd');

	if (del_node_loc == FALSE) {
		printf("\t%s ���ڵ尡 �������� �ʽ��ϴ�.\n", CompName);
		return;
	}	// if ()

	// Comes here when the key is found. It is in curr's node.
	// curr node is not a leaf node
	if (curr->ptr[0] != NULL) {
		// We need to find successor of out_key
		del_node_loc = successor_node_finding(&curr, stk_SET, del_node_loc);

		// s�� d�� �ִ� ��ġ�� ���� ���̹Ƿ�,
		// s�� ����� �����ؾ���
		leaf_del_arranging(&curr, del_node_loc);
	}	// if ()
	else {
		//curr node is a leaf node
		leaf_del_arranging(&curr, del_node_loc);
	}	// else

	balancing_after_del(package, &curr, stk_SET, del_SET);

	free(stk_SET);
	free(del_SET);

	printf("\t%s ���ڵ� ������ �Ϸ��Ͽ����ϴ�.\n", CompName);
	printf("\t���� �������� redistribution %d��, merging %d�� �Ͼ���ϴ�.\n", rdst_cnt, mrg_cnt);
	
}