// main.c

#include "functions.h"

int main()
{ 
	nptr_pck np_SET = (nptr_pck)malloc(sizeof(nptr_));

	nodeptr Root = NULL;

	char menu[str_MAX] = { 0 }; 

	int name_len = 0;			// s �޴� �Է¿��� �̸� ���� 
	char* temp_name = NULL;		// s �޴� �Է¿��� �̸� ����� 

	np_SET->Root = &Root; 
	np_SET->curr = NULL; 
	np_SET->prev = NULL; 

	Trie_I_from_File(np_SET, FILE_NAME); 

	printf("\n"); 

	// e(����) �Է� ������ �ݺ�
	// ��, ��� �۾�
	while (1) {
		printf("�����? ");
		// �޴� menu ���ڿ��� �ޱ�
		fgets(menu, str_MAX, stdin);
		// menu ���ڿ����� '\n' ����
		strtok(menu, "\n");
		// �Է� ���� ����
		fflush(stdin);

		switch (menu[0]) { 
		case 'c': 
			compare_to_the_Original(FILE_NAME, PRINT_FILE_NAME);
			break;
		case 'p': 
			print_to_File(Root, PRINT_FILE_NAME); 
			break; 
		case 's': 
			// �޴� �Է¿��� �̸� ����
			name_len = strlen(menu) - 1;
			temp_name = malloc((name_len) * sizeof(char));
			name_extracting(menu, temp_name, name_len);
			spelling_correction(Root, temp_name);
			break; 
		case 'e':
			printf("\t���α׷��� �����մϴ�.\n");
			return 0;
		default:
			printf("\t�׷� ����� �������� �ʽ��ϴ�.\n");
			break;
		}	// switch ()

	}	// while (1)

	return 1;
}