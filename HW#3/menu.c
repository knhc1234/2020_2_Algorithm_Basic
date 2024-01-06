// menu.c

#include "functions.h"

void menu_r(ptr_record Rec, char name[])
{
	int probes = 1;
	int hash_value;

	// �Է� ���� ȸ��� hash value ���ϱ�
	hash_value = hash(name);

	while (1) {
		// hash_value ��ġ�� �ִٸ�
		if (strcmp(Rec[hash_value].name, name) == 0) { break; }
		// ���ٸ�
		else {
			// ��ũ�� �ѹ� �ǳ�
			hash_value = Rec[hash_value].link;
			probes++;
			// DUMMY_RECORD Ȯ��(ü���� �� ����)
			if (hash_value == DUMMY_RECORD) { 
				printf("�׷� ����Ÿ�� �������� �ʽ��ϴ�.\n");
				return;
			} // if ()
		}	// else
	}	// while(1)
	printf("\t������ġ = %d, Probe �� = %d\n", hash_value, probes);
}

void menu_v(ptr_record Rec)
{
	int success_count = 0;
	int fail_count = 0;
	char temp_Company[str_MAX];
	int hash_value;
	FILE *fp = fopen(Text_File_Name, "r");

	while (1) {
		// uns.txt ���ϻ󿡼� ���پ� �޴´�
		if (fgets(temp_Company, str_MAX, fp) == NULL) { break; }
		// fgets() �Լ��� '\n'���� �����Ƿ� ���ڿ� ���� ���� '\n' ����
		strtok(temp_Company, "\n");
		// �Է� ���� ȸ��� hash value ���ϱ�
		hash_value = hash(temp_Company);

		while (2) {
			// hash_value ��ġ�� �ִٸ�
			if (strcmp(Rec[hash_value].name, temp_Company) == 0) {
				success_count++;
				break;
			}	// if ()
			// ���ٸ�
			else {
				// ��ũ�� �ѹ� �ǳ�
				hash_value = Rec[hash_value].link;
				// DUMMY_RECORD Ȯ��(ü���� �� ����)
				if (hash_value == DUMMY_RECORD) {
					fail_count++;
					break;
				}	// if ()
			}	// else
		}	// while(2)

	}	//	while (1)

	printf("\tSuccess count: %d,\t Fail count: %d\n"
		, success_count, fail_count);
	fclose(fp);
}

void menu_p(ptr_record Rec)
{
	int probes = 1;
	double apn = 0;
	char temp_Company[str_MAX];
	int hash_value;
	FILE *fp = fopen(Text_File_Name, "r");

	while (1) {
		// uns.txt ���ϻ󿡼� ���پ� �޴´�
		if (fgets(temp_Company, str_MAX, fp) == NULL) { break; }
		// fgets() �Լ��� '\n'���� �����Ƿ� ���ڿ� ���� ���� '\n' ����
		strtok(temp_Company, "\n");
		// �Է� ���� ȸ��� hash value ���ϱ�
		hash_value = hash(temp_Company);

		while (2) {
			// hash_value ��ġ�� �ִٸ�
			if (strcmp(Rec[hash_value].name, temp_Company) == 0) { break; }
			// ���ٸ�
			else {
				// ��ũ�� �ѹ� �ǳ�
				hash_value = Rec[hash_value].link;
				probes++;
				// DUMMY_RECORD Ȯ��(ü���� �� ����)
				if (hash_value == DUMMY_RECORD) { break; }
			}	// else
		}	// while(2)

		apn += probes;
		probes = 1;
	}	//	while (1)

	apn /= N;
	printf("\tAverage probe number = %lf\n", apn);
	fclose(fp);
}