// initialization.c

#include "functions.h"

void table_initialization(ptr_record Rec) 
{ 
	printf("���̺� �ʱ�ȭ �۾��� �����մϴ�.\n");
	// monincome, link�� DUMMY_RECORD 
	for (int i = 0; i < Tbl_Size; i++) {
		Rec[i].monincome = Rec[i].link = DUMMY_RECORD; 
		strcpy(Rec[i].name, "");
	}	// for () 
	printf("���̺� �ʱ�ȭ �۾��� �Ϸ�Ǿ����ϴ�.\n\n"); 
}