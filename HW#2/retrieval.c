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
				printf("\t%s ���ڵ��\n", CompName);
				printf("\t����%d�� ��ġ�ϸ� �� ����� %d��° ���ڵ忡 �����մϴ�.\n", level, i+1);
				return;
			}	// else if (CompName)

		}	// for (i)

		temp_ptr = curr->ptr[i];

		if (temp_ptr) { curr = temp_ptr; level++; }

	} while (temp_ptr);

	printf("%s ���ڵ尡 �������� �ʽ��ϴ�.\n", CompName);
}