// print.c

#include "functions.h"

void SP_console(nodeptr curr)
{
	int i = 0;

	if (!curr) { return; }

	for (i = 0; i < curr->fill_cnt; i++) {
		SP_console(curr->ptr[i]);
		printf("이름: %s, 길이: %d\n", curr->rec[i].name, curr->rec[i].leng);
	}	// for (i)
	SP_console(curr->ptr[i]);
}

void SP_console_to_File(nodeptr curr, FILE* fp)
{
	int i = 0;

	if (!curr) { return; }

	for (i = 0; i < curr->fill_cnt; i++) {
		SP_console_to_File(curr->ptr[i], fp);
		fprintf(fp, "이름: %s, 길이: %d\n", curr->rec[i].name, curr->rec[i].leng);
	}	// for (i)
	SP_console_to_File(curr->ptr[i], fp);
}

void SP_to_File(nodeptr curr)
{
	FILE *fp = fopen(PRINT_FILE_NAME, "w");

	if (!fp) {
		printf("%s 파일 읽기 과정에서 오류가 발생하였습니다.\n", PRINT_FILE_NAME);
		printf("작업을 취소합니다.");
		return;
	}

	printf("\t%s 파일로 B-tree 데이터 Sequential printing합니다.\n", PRINT_FILE_NAME);

	SP_console_to_File(curr, fp);

	fclose(fp);

	printf("\t%s 파일로 B-tree 데이터 Sequential printing이 완료되었습니다.\n", PRINT_FILE_NAME);
}

void fill_cnt_check(nodeptr curr)
{
	int i = 0;

	if (!curr) { return; }

	for (i = 0; i < curr->fill_cnt; i++) {
		fill_cnt_check(curr->ptr[i]);
		if (curr->fill_cnt < CAPACITY_ORDER) {
			printf("fill_cnt < CAPACITY_ORDER : %p\n", curr);
		}	// if (fill_cnt)
	}	// for (i)
	fill_cnt_check(curr->ptr[i]);
}

void ptr_cnt_check(nodeptr curr)
{
	int i = 0;

	if (!curr) { return; }

	for (i = 0; i < curr->fill_cnt; i++) {
		ptr_cnt_check(curr->ptr[i]);
		if (curr->ptr[0] != NULL && curr->ptr[curr->fill_cnt] == NULL) {
			printf("ptr[fill_cnt] doesn't exist : %p\n", curr);
		}	// if (ptr)
	}	// for (i)
	ptr_cnt_check(curr->ptr[i]);
}