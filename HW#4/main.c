// main.c

#include "functions.h"

int main()
{ 
	nptr_pck np_SET = (nptr_pck)malloc(sizeof(nptr_));

	nodeptr Root = NULL;

	char menu[str_MAX] = { 0 }; 

	int name_len = 0;			// s 메뉴 입력에서 이름 길이 
	char* temp_name = NULL;		// s 메뉴 입력에서 이름 추출용 

	np_SET->Root = &Root; 
	np_SET->curr = NULL; 
	np_SET->prev = NULL; 

	Trie_I_from_File(np_SET, FILE_NAME); 

	printf("\n"); 

	// e(종료) 입력 때까지 반복
	// 비교, 출력 작업
	while (1) {
		printf("명령은? ");
		// 메뉴 menu 문자열에 받기
		fgets(menu, str_MAX, stdin);
		// menu 문자열에서 '\n' 제거
		strtok(menu, "\n");
		// 입력 버퍼 비우기
		fflush(stdin);

		switch (menu[0]) { 
		case 'c': 
			compare_to_the_Original(FILE_NAME, PRINT_FILE_NAME);
			break;
		case 'p': 
			print_to_File(Root, PRINT_FILE_NAME); 
			break; 
		case 's': 
			// 메뉴 입력에서 이름 추출
			name_len = strlen(menu) - 1;
			temp_name = malloc((name_len) * sizeof(char));
			name_extracting(menu, temp_name, name_len);
			spelling_correction(Root, temp_name);
			break; 
		case 'e':
			printf("\t프로그램을 종료합니다.\n");
			return 0;
		default:
			printf("\t그런 명령은 존재하지 않습니다.\n");
			break;
		}	// switch ()

	}	// while (1)

	return 1;
}