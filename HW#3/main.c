// main.c

#include "functions.h"

int main()
{
	char menu[str_MAX];			// �޴� �Է�
	int name_len = 0;			// r �޴� �Է¿��� �̸� ���� 
	char* temp_name = NULL;		// r �޴� �Է¿��� �̸� ����� 
	long R = Tbl_Size - 1;		// �ܼ� ���ڸ� ã�⿡�� ���� ���ڸ� ��ġ 

	// make table
	ptr_record Rec = (ptr_record)malloc(Tbl_Size*sizeof(type_record));
	table_initialization(Rec); 

	printf("\n�ܼ��� ���ڸ� ã��� ������ �����մϴ�.\n");
	// �ؽ����̺� ���� �۾�
	make_ht_with_naive_empty_finding(Rec, &R);
	printf("������ �Ϸ�Ǿ����ϴ�.\n");

	// e(����) �Է� ������ �ݺ�
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
			temp_name = malloc((name_len) * sizeof(char));
			name_extracting(menu, temp_name, name_len);
			menu_r(Rec, temp_name);
			break; 
		case 'v':
			print_PT(Rec, 'v'); 
			break;
		case 'p':
			print_PT(Rec, 'p'); 
			break;
		case 'e':
			printf("������ �����մϴ�.\n");
			return 0;
		default:
			printf("�׷� ����� �������� �ʽ��ϴ�.\n");
			break;
		}	// switch ()

	}	// while (1)

	return 0;
}