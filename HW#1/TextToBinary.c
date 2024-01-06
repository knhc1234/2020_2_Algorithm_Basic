#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct {
	char name[20];
	int stno;
	double gpa;
} student;

int main() {
	//char name[20];
	//int stno;
	//double gpa;
	student item;
	int rn, num_ret;
	char *char_ptr, line[100];
	//size_t sz;	
	FILE *fp_r, *fp_w, *fp;

	// text file�� ������ �о �̸� binary file�� ���� 
	fp_r = fopen("sdata.txt", "r");
	if (!fp_r) {
		printf("File Open Error!\n");
		return -1;
	}
	fp_w = fopen("sdata.bin", "wb");
	num_ret = 0;	// ����� ���ڵ� ��

	while (1) {
		// Fill your code
		if (fscanf(fp_r,"%s %d %lf",item.name, &item.stno, &item.gpa) != EOF) {		// fscanf �Լ��� �Ἥ text file�� �� �ٿ� �ִ� ����(�̸� �й� ����)�� �о item(student ����ü)�� ������ (text ������ ������ ���� �� ���� �ݺ�(fscanf ��� ���� EOF�� ���))
			fwrite(&item, sizeof(item), 1, fp_w);	// item(struct ����ü)�� ����� �������� sdata.bin ���Ͽ� ������ 
			num_ret++;								// ������ ���ڵ� ���� 1����
		}
		else
			break;	// fscanf ��� ���� EOF �� ���� ��� ������ ��� ������ �о����Ƿ� �ݺ������� ��������
	}

	fclose(fp_r);
	fclose(fp_w);

	// ���ڵ� ��ȣ�� �ָ� binary file�� �ش� ���ڵ带 �о���� 
	// ������ �Է��ϸ� ���� 
	fp = fopen("sdata.bin", "r+b");
	do {
		printf("Input type record number:");
		char_ptr = gets(line);

		if (!char_ptr)
			break;
		rn = atoi(line);

		// Fill your code
		if (rn < 0) 		// �Է� ���� ���ڵ� ��ȣ�� ������ ��� do while���� ���������� ���α׷��� ������
			printf("���α׷� ����\n");

		else if (rn >= num_ret)	// �Է� ���� ���ڵ� ��ȣ�� ����� ���ڵ� �� �̻��� ��� (���ڵ� ��ȣ�� 0���� �����ϸ� ���� ū ���ڵ� ��ȣ�� (����� ���ڵ� ��(num_ret) - 1) �̴�) �߸��� �Է��̶� ǥ���ϰ� ���ڵ� ��ȣ�� �ٽ� �Է� ���� (rn >= 0 �̹Ƿ� do while���� �ٽ� ����)
			printf("�߸��� �Է��Դϴ�. �Է��� Record #%d \n", rn);
		
		else {	// �������� ���ڵ� ��ȣ�� �Է��� ��� 
			fseek(fp, sizeof(item) * rn, SEEK_SET);	// binary file�� �ش� ���ڵ��� ��ġ�� �̵��Ͽ�
			fread(&item, sizeof(item), 1, fp);		// �ش� ���ڵ带 �о���� item(student ����ü)�� �����Ͽ� 

			printf("Record #%d = %s %d %5.2f\n", rn, item.name, item.stno, item.gpa);	// �о�� �������� �����
		}
	} while (rn >= 0);
	fclose(fp);

	return 0;
}