// from_File.c

#include "functions.h"

void B_tree_R_I_D_from_File(nptr_pck package, char FileName[], char what)
{
	char temp_Company[COMP_NAME_LEN] = { 0 };
	char fnc[5]						 = { 0 };

	FILE *fp = fopen(FileName, "r");

	switch (what) {
	case 'r': strcpy(fnc, "�˻�"); break;
	case 'i': strcpy(fnc, "�Է�"); break;
	case 'd': strcpy(fnc, "����"); break;
	default:
		printf("������� �����Դϴ�.\n");
		printf("���α׷��� �����մϴ�.\n");
		exit(1);
	}	// switch ()

	printf("%s ���Ϸκ��� B-tree %s��(��) �����մϴ�.\n", FileName, fnc);

	if (!fp) {
		printf("%s ���� �б� �������� ������ �߻��Ͽ����ϴ�.\n", FileName);
		printf("�۾��� ����մϴ�.");
		return;
	}	// if ()
	
	switch (what) {
	case 'r':
		while (1) {
			// FileName ���ϻ󿡼� ���پ� �޴´�
			if (fgets(temp_Company, COMP_NAME_LEN, fp) == NULL) { break; }
			// fgets() �Լ��� '\n'���� �����Ƿ� ���ڿ� ���� ���� '\n'����
			strtok(temp_Company, "\n");
			// B-tree���� �˻�
			retrieval(*(package->Root), temp_Company);
		}	// while (1)
		break;
	case 'i':
		while (1) {
			// FileName ���ϻ󿡼� ���پ� �޴´�
			if (fgets(temp_Company, COMP_NAME_LEN, fp) == NULL) { break; }
			// fgets() �Լ��� '\n'���� �����Ƿ� ���ڿ� ���� ���� '\n'����
			strtok(temp_Company, "\n");
			// B-tree�� ����
			B_tree_Insertion(package, temp_Company, 'f');
		}	// while (1)
		break;
	case 'd':
		while (1) {
			// FileName ���ϻ󿡼� ���پ� �޴´�
			if (fgets(temp_Company, COMP_NAME_LEN, fp) == NULL) { break; }
			// fgets() �Լ��� '\n'���� �����Ƿ� ���ڿ� ���� ���� '\n'����
			strtok(temp_Company, "\n");
			// B-tree���� ����
			B_tree_Deletion(package, temp_Company);
		}	// while (1)
		break;
	}	// switch ()

	fclose(fp);

	printf("%s ���Ϸκ��� B-tree %s��(��) �Ϸ�Ǿ����ϴ�.\n", FileName, fnc);
}