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

	// exit(����) �Է� ������ �ݺ�
	// �˻�, (�ϰ�)����, �������� �۾�
	while (1) {
		printf("�����? ");
		// �޴� menu ���ڿ��� �ޱ�
		fgets(menu, str_MAX, stdin);
		// menu ���ڿ����� '\n' ����
		strtok(menu, "\n");
		// �Է� ���� ����
		fflush(stdin);

		switch (menu[0]) {
		case 'r':
			// �޴� �Է¿��� �̸� ����
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
				printf("\t%s ���ڵ� ������ �Ϸ�Ǿ����ϴ�.\n", temp_cmpy_name);
				printf("\t���԰������� split�� %d�� �Ͼ���ϴ�.\n", split_cnt);
			}	// if ()
			break;
		case 'd':
			// �޴� �Է¿��� �̸� ����
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
				printf("\t���α׷��� �����մϴ�.\n");
				return 0;
			}	// if ()
		default:
			printf("\t�׷� ����� �������� �ʽ��ϴ�.\n");
			break;
		}	// switch ()

	}	// while (1)

	return 1;
}