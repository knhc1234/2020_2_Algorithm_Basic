// from_File.c 

#include "functions.h" 

void Trie_I_from_File(nptr_pck package, char FileName[])
{
	char word[WORD_LEN] = { 0 }; 

	FILE* fp = fopen(FileName, "r"); 

	if (!fp) {
		printf("%s 파일 읽기 과정에서 오류가 발생하였습니다.\n", FileName);
		printf("작업을 취소합니다.");
		return;
	}	// if () 

	while (1) {
		// FileName 파일상에서 한줄씩 받는다
		if (fgets(word, WORD_LEN, fp) == NULL) { break; }
		// fgets() 함수는 '\n'까지 넣으므로 문자열 끝에 붙은 '\n'제거
		strtok(word, "\n");
		// Trie에 저장
		insert_trie(package, word);
	}	// while (1) 

	fclose(fp);

	printf("%s 파일로부터 Trie Insertion이(가) 완료되었습니다.\n", FileName); 

	return;
} 

void compare_to_the_Original(char Original[], char Print_FileName[])
{
	int flag = 1; 

	char word1[WORD_LEN] = { 0 }; 
	char word2[WORD_LEN] = { 0 }; 

	FILE* fp1 = fopen(Original, "r"); 
	FILE* fp2 = fopen(Print_FileName, "r"); 

	if (!fp1) {
		printf("\t%s 파일 읽기 과정에서 오류가 발생하였습니다.\n", Original);
		printf("\t작업을 취소합니다.");
		return;
	}	// if () 

	if (!fp2) {
		printf("\t%s 파일 읽기 과정에서 오류가 발생하였습니다.\n", Print_FileName);
		printf("\t작업을 취소합니다.");
		return;
	}	// if () 

	while (1) {
		if (fgets(word1, WORD_LEN, fp1) != NULL && fgets(word2, WORD_LEN, fp2) != NULL) {
			strtok(word1, "\n");
			strtok(word2, "\n");

			if (strcmp(word1, word2) == 0) {
				flag = 0;
			}	// if () 
			else {
				flag = 1;
				break;
			}	// else 
		}	// if () 
		else {
			if (fgets(word2, WORD_LEN, fp2) != NULL) {
				flag = 1;
			}	// if () 
			break;
		}	// else  

	}	// while (1) 

	fclose(fp1);
	fclose(fp2);

	if (flag == 0) {
		printf("\t%s 파일과 일치합니다.\n", Original); 
	}	// if () 
	else {
		printf("\t%s 파일과 일치하지 않습니다.\n", Original);
	}	// else 

	return; 
}