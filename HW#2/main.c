// main.c

#include "functions.h"

int main()
{
	nodeptr  Root	= NULL;
	nptr_pck np_SET = (nptr_pck)malloc(sizeof(nptr_));

	char menu[str_MAX]				   = { 0 };
	char temp_name[COMP_NAME_LEN]	   = { 0 };
	char temp_cmpy_name[COMP_NAME_LEN] = { 0 };
	int  name_len					   = 0;
	
	int split_cnt = 0;

	np_SET->Root							= &Root;
	np_SET->temp_ptr = np_SET->new_Root = NULL;

	B_tree_R_I_D_from_File(np_SET, FIRST_FILE_NAME,  'i');
	B_tree_R_I_D_from_File(np_SET, SECOND_FILE_NAME, 'i');

	printf("\n");

	// exit(종료) 입력 때까지 반복
	// 검색, (일괄)삭제, 성능측정 작업
	while (1) {
		printf("명령은? ");
		// 메뉴 menu 문자열에 받기
		fgets(menu, str_MAX, stdin);
		// menu 문자열에서 '\n' 제거
		strtok(menu, "\n");
		// 입력 버퍼 비우기
		fflush(stdin);

		switch (menu[0]) {
		case 'r':
			// 메뉴 입력에서 이름 추출
			name_len = strlen(menu) - 1;
			name_extracting(menu, temp_name, name_len);
			retrieval(Root, temp_name);
			break;
		case 'i':
			name_len  = strlen(menu) - 1;
			name_extracting(menu, temp_name, name_len);
			strcpy(temp_cmpy_name, temp_name);
			split_cnt = B_tree_Insertion(np_SET, temp_name, 'u');
			if (split_cnt != FALSE) {
				printf("\t%s 레코드 삽입이 완료되었습니다.\n", temp_cmpy_name);
				printf("\t삽입과정에서 split이 %d번 일어났습니다.\n", split_cnt);
			}	// if ()
			break;
		case 'd':
			// 메뉴 입력에서 이름 추출
			name_len = strlen(menu) - 1;
			name_extracting(menu, temp_name, name_len);
			B_tree_Deletion(np_SET, temp_name);
			break;
		case 's':
			if (strcmp(menu, "sp") == 0) {
				SP_to_File(Root);
				break;
			}	// if ()
		case 'e':
			if (strcmp(menu, "exit") == 0) {
				printf("\t프로그램을 종료합니다.\n");
				return 0;
			}	// if ()
		default:
			printf("\t그런 명령은 존재하지 않습니다.\n");
			break;
		}	// switch ()

	}	// while (1)

	return 1;
}