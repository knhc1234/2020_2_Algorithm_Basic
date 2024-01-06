// retrieval.c

#include "functions.h"

void retrieval(nodeptr curr, char CompName[])
{
	nodeptr temp_ptr = NULL;

	int level = 1;

	int i = 0;

	do {
		for (i = 0; i < curr->fill_cnt; i++) {
			if (strcmp(CompName, curr->rec[i].name) < 0) {
				break;
			}	// if (CompName)
			else if (strcmp(CompName, curr->rec[i].name) == 0) {
				printf("\t%s 레코드는\n", CompName);
				printf("\t레벨%d에 위치하며 이 노드의 %d번째 레코드에 존재합니다.\n", level, i+1);
				return;
			}	// else if (CompName)

		}	// for (i)

		temp_ptr = curr->ptr[i];

		if (temp_ptr) { curr = temp_ptr; level++; }

	} while (temp_ptr);

	printf("%s 레코드가 존재하지 않습니다.\n", CompName);
}