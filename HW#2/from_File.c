// from_File.c

#include "functions.h"

void B_tree_R_I_D_from_File(nptr_pck package, char FileName[], char what)
{
	char temp_Company[COMP_NAME_LEN] = { 0 };
	char fnc[5]						 = { 0 };

	FILE *fp = fopen(FileName, "r");

	switch (what) {
	case 'r': strcpy(fnc, "검색"); break;
	case 'i': strcpy(fnc, "입력"); break;
	case 'd': strcpy(fnc, "삭제"); break;
	default:
		printf("설계상의 오류입니다.\n");
		printf("프로그램을 종료합니다.\n");
		exit(1);
	}	// switch ()

	printf("%s 파일로부터 B-tree %s을(를) 시작합니다.\n", FileName, fnc);

	if (!fp) {
		printf("%s 파일 읽기 과정에서 오류가 발생하였습니다.\n", FileName);
		printf("작업을 취소합니다.");
		return;
	}	// if ()
	
	switch (what) {
	case 'r':
		while (1) {
			// FileName 파일상에서 한줄씩 받는다
			if (fgets(temp_Company, COMP_NAME_LEN, fp) == NULL) { break; }
			// fgets() 함수는 '\n'까지 넣으므로 문자열 끝에 붙은 '\n'제거
			strtok(temp_Company, "\n");
			// B-tree에서 검색
			retrieval(*(package->Root), temp_Company);
		}	// while (1)
		break;
	case 'i':
		while (1) {
			// FileName 파일상에서 한줄씩 받는다
			if (fgets(temp_Company, COMP_NAME_LEN, fp) == NULL) { break; }
			// fgets() 함수는 '\n'까지 넣으므로 문자열 끝에 붙은 '\n'제거
			strtok(temp_Company, "\n");
			// B-tree에 저장
			B_tree_Insertion(package, temp_Company, 'f');
		}	// while (1)
		break;
	case 'd':
		while (1) {
			// FileName 파일상에서 한줄씩 받는다
			if (fgets(temp_Company, COMP_NAME_LEN, fp) == NULL) { break; }
			// fgets() 함수는 '\n'까지 넣으므로 문자열 끝에 붙은 '\n'제거
			strtok(temp_Company, "\n");
			// B-tree에서 삭제
			B_tree_Deletion(package, temp_Company);
		}	// while (1)
		break;
	}	// switch ()

	fclose(fp);

	printf("%s 파일로부터 B-tree %s이(가) 완료되었습니다.\n", FileName, fnc);
}