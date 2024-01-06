// naive.c

#include "functions.h"

long naive_find_empty_loc(ptr_record Rec, long* R)
{
	while (1) {
		// 0 ���� ������(= ���ڸ��� ������)
		if (*R < 0) { return -1; }
		// (*R)�� ���ڸ����(�� ���� ���ڸ� ��ġ�� ��ĭ ���� �ø���)
		if (Rec[(*R)--].monincome == DUMMY_RECORD) {
			// ���ڸ� ��ġ ��ȯ
			return *R+1;	// �ռ� *R�� 1 ������ �����̹Ƿ� ���ڸ��� *R+1���� ��ȯ����
		}	// if ()
	}	// while (1)
}

void make_ht_with_naive_empty_finding(ptr_record Rec, long* R)
{
	char temp_Company[str_MAX];					// ���Ͽ��� �̸� �޾ƿ����
	int rand1, rand2;							// �� ���� ���� �Է¿�
	int hash_value;								// hash��
	int empty_location;							// ���ڸ� ��ġ
	FILE *fp;									// �޾ƿ��� ����
	FILE *fpout = fopen("HT_naive.txt", "w");	// �ؽ����̺� ���� ��¿�

	// ����ð� ��¿� ������
	float PT;
	LARGE_INTEGER TPS, ST, ET;
	LONGLONG CT;

	// ����ð� ���ϱ�(���� �ð�)
	QueryPerformanceFrequency(&TPS);
	QueryPerformanceCounter(&ST);

	fp = fopen(Text_File_Name, "r");
	if (!fp) {
		printf("���� �б� �������� ������ �߻��Ͽ����ϴ�.\n");
		printf("�۾��� ����մϴ�.");
		return;
	}

	srand(time(NULL));	// For every different seed value

	while (1) {
		// uns.txt ���ϻ󿡼� ���پ� �޴´�
		if (fgets(temp_Company, str_MAX, fp) == NULL) { break; }
		// fgets() �Լ��� '\n'���� �����Ƿ� ���ڿ� ���� ���� '\n' ����
		strtok(temp_Company, "\n");
		// �Է� ���� ȸ��� hash value ���ϱ�
		hash_value = hash(temp_Company);
		// monincome ���Կ� �� ���س���
		rand1 = rand() % 20001;
		rand2 = rand() % 1001;

		// Ȩ�ּ�(hash_value)�� �� �ڸ����
		if (Rec[hash_value].monincome == DUMMY_RECORD) {
			// ���ڵ� ����
			strcpy(Rec[hash_value].name, temp_Company);
			Rec[hash_value].monincome = rand1 * rand2;
			Rec[hash_value].link = DUMMY_RECORD; 
		}	// if ()

		// �� �ڸ��� �ƴ϶��
		else {
			// ���ڸ��� ã��
			empty_location = naive_find_empty_loc(Rec, R);
			// ��ũ�� �����ϱ� ���� Ȩ�ּҺ��� ������ ���� ü���� ã�Ƽ�
			while (Rec[hash_value].link != DUMMY_RECORD) {
				hash_value = Rec[hash_value].link;	// ��ũ�� ����
			}	// while ()
			// ������ ��ġ�� ����
			Rec[hash_value].link = empty_location;	// ������ ���� ü���� ��ũ�� ������ ��ġ�� ����(���� ����)
			// ���ڵ� ����
			strcpy(Rec[empty_location].name, temp_Company);		
			Rec[empty_location].monincome = rand1 * rand2; 
			Rec[empty_location].link = DUMMY_RECORD;
		}	// else

	}	//	while (1)

	// ����ð� ���ϱ�
	QueryPerformanceCounter(&ET);
	CT = ET.QuadPart - ST.QuadPart;
	PT = (float)CT / (float)TPS.QuadPart;

	// ����ð� ���
	printf("\t����ð� %f��\n", PT);

	// �ؽ����̺� ���� ���
	for (int i = 0; i < Tbl_Size; i++) {
		fprintf(fpout, "%d, �̸� : %s, ������ : %d, ��ũ : %d\n",
			i, Rec[i].name, Rec[i].monincome, Rec[i].link); 
	}	// for () 

	// ���� ���� �ݱ�
	fclose(fpout); fclose(fp);
}