// print.c 

#include "functions.h"

void recursive_print_to_File(nodeptr curr, FILE* fp, char pre[], int pre_index)
{
	char word[WORD_LEN] = { 0 }; 

	if (!curr) { return; }

	if (curr->ch == '\0') { 
		strcpy(word, pre);
		word[pre_index] = '\0';
		fprintf(fp, "%s\n", word); 

		if (curr->below == NULL && curr->right == NULL) {
			return; 
		}	// if () 

	}	// if () 

	if (curr->below != NULL) {
		strcpy(word, pre); 
		word[pre_index] = curr->ch; 
		recursive_print_to_File(curr->below, fp, word, pre_index + 1); 
	}	// if (curr->below) 

	if (curr->right != NULL) {
		recursive_print_to_File(curr->right, fp, pre, pre_index);
	}	// if (curr->right) 

	return; 
}

void print_to_File(nodeptr curr, char Print_FileName[])
{
	char word[WORD_LEN] = { 0 };

	FILE* fp = fopen(Print_FileName, "w");

	if (!fp) {
		printf("%s 파일 읽기 과정에서 오류가 발생하였습니다.\n", Print_FileName);
		printf("작업을 취소합니다.");
		return;
	}	// if (fp) 

	printf("\t%s 파일로 Trie 데이터를 출력합니다.\n", Print_FileName);

	recursive_print_to_File(curr, fp, word, 0);

	fclose(fp);	

	printf("\t%s 파일로 Trie 데이터 출력이 완료되었습니다.\n", Print_FileName);

	return; 
}