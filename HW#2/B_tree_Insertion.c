// B_tree_Insertion.c

#include "functions.h"

int B_tree_Insertion(nptr_pck package, char CompName[], char from)
{
	nodeptr* Root	  = package->Root;
	nodeptr  temp_ptr = package->temp_ptr;
	nodeptr  new_Root = package->new_Root;
	nodeptr  curr	  = *Root;

	stack   stk		 = NULL;
	stack   temp_stk = NULL;
	stk_pck stk_SET  = (stk_pck)malloc(sizeof(stk_pck_rec));
	
	big_node bnode;
	
	bool found = FALSE;

	int split_count = 0;

	int i = 0;
	int k = 0;

	stk_SET->stk		  = &stk;
	stk_SET->temp_stk = &temp_stk;

	// B-tree가 비어있는 특수한 상황
	if (*Root == NULL) {
		*Root = (nodeptr)malloc(sizeof(node));

		for (int j = 0; j < PTR_NUM; j++) {
			(*Root)->ptr[j] = NULL;
		}	// for (j)

		strcpy((*Root)->rec[0].name, CompName);		// 루트에 이름 삽입
		(*Root)->rec[0].leng = strlen(CompName);	// 루트에 이름 길이 삽입
		(*Root)->fill_cnt = 1;						// 루트 fill_cnt를 1로 설정
		return split_count;
	}	// if

	// B-tree에 존재 여부 확인 
	found = leaf_n_del_node_finding(&curr, CompName, stk_SET, 'l');

	if (found == TRUE) {
		if (from == 'u') {
			printf("%s 레코드가 B-tree에 이미 존재합니다.\n", CompName);
		}	//	if ()
		return FALSE;
	}	// if ()

	temp_ptr = NULL;

	while (1) {
		if (curr->fill_cnt < REC_NUM) {
			// curr node is not full
			for (i = 0; i < curr->fill_cnt; i++) {
				if (strcmp(CompName, curr->rec[i].name) < 0) { break; }
			}	// for (i)

			for (int j = curr->fill_cnt; j > i; j--) {	// 기존의 name보다 작은 name이 새로 들어가는 경우 기존의 name을 작은 name이 들어갈 위치보다 1칸 뒤로 이동시키는 코드
				curr->ptr[j + 1]  = curr->ptr[j];
				strcpy(curr->rec[j].name, curr->rec[j-1].name);
				curr->rec[j].leng = curr->rec[j-1].leng;
			}	// for (j)

			strcpy(curr->rec[i].name, CompName);	// 새로운 name을 넣음
			curr->rec[i].leng = strlen(CompName);
			curr->ptr[i + 1]  = temp_ptr;
			curr->fill_cnt++;
			return split_count;
		}	// if ()

		else {
			// curr node is full. thus it must be split into two nodes.
			if (from == 'u') { split_count++; }

			for (i = 0; i < REC_NUM; i++) {
				if (strcmp(CompName, curr->rec[i].name) < 0) { break; }
			}	// for (i)

			bnode.ptr[0] = curr->ptr[0];	
			for (k = 0; k < i; k++) {	// i가 새로 들어갈 이름의 위치
				strcpy(bnode.rec[k].name, curr->rec[k].name);
				bnode.rec[k].leng = curr->rec[k].leng;
				bnode.ptr[k + 1] = curr->ptr[k + 1];	
			}	// for (k)

			strcpy(bnode.rec[k].name, CompName);
			bnode.rec[k].leng = strlen(CompName);
			bnode.ptr[k + 1]  = temp_ptr;	// (오른쪽 일부분)
			k++;

			while (i < REC_NUM) {
				strcpy(bnode.rec[k].name, curr->rec[i].name);
				bnode.rec[k].leng = curr->rec[i].leng;
				bnode.ptr[k + 1]  = curr->ptr[i + 1];	
				k++;
				i++;
			}	// while (i)

			// move first half of bnode to curr and second half to newly allocated node
			for (i = 0; i < CAPACITY_ORDER; i++) {	// 좌노드 만들기
				curr->ptr[i]		  = bnode.ptr[i];
				strcpy(curr->rec[i].name, bnode.rec[i].name);
				curr->rec[i].leng = bnode.rec[i].leng;
			}	// for (i)
				curr->ptr[i]		  = bnode.ptr[i];	
			// [CAPACITY_ORDER]번째 이상 정리
			for (int l = CAPACITY_ORDER; l < REC_NUM; l++) {	
				strcpy(curr->rec[l].name, "");
				curr->rec[l].leng = 0;
				curr->ptr[l + 1]  = NULL;
			}	// for (l)

				curr->fill_cnt	  = CAPACITY_ORDER;

			temp_ptr = (nodeptr)malloc(sizeof(node));	// 우노드 만들기
			for (i = 0; i < CAPACITY_ORDER; i++) {
				temp_ptr->ptr[i]		  = bnode.ptr[i + 3];
				strcpy(temp_ptr->rec[i].name, bnode.rec[i + 3].name);
				temp_ptr->rec[i].leng = bnode.rec[i + 3].leng;
			}	// for (i)
				temp_ptr->ptr[i]		  = bnode.ptr[i + 3];	

			for (int m = CAPACITY_ORDER + 1; m < PTR_NUM; m++) {
				temp_ptr->ptr[m]		  = NULL;
			}	// for (m)

				temp_ptr->fill_cnt	  = CAPACITY_ORDER;

			strcpy(CompName, bnode.rec[CAPACITY_ORDER].name);	// CompName에 빅노드의 가운데 이름을 저장

			if (stk) { stk_pop(&stk, &curr); }
			else {
				// curr은 root와 같다.
				// 새로운 root node를 만든다.
				new_Root		 = (nodeptr)malloc(sizeof(node));
				new_Root->ptr[0] = curr;		// 좌노드를 삽입
				new_Root->ptr[1] = temp_ptr;	// 우노드를 삽입

				for (int j = 2; j < PTR_NUM; j++) {
				new_Root->ptr[j] = NULL;
				}	// for (j)

				strcpy(new_Root->rec[0].name, CompName);
				new_Root->rec[0].leng = strlen(CompName);
				new_Root->fill_cnt	  = 1;
				*Root = (new_Root);	// 루트를 new_Root로 변경

				return split_count;
			}	// else

		}	// else
	} // while (1)
}