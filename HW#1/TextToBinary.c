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

	// text file의 내용을 읽어서 이를 binary file에 저장 
	fp_r = fopen("sdata.txt", "r");
	if (!fp_r) {
		printf("File Open Error!\n");
		return -1;
	}
	fp_w = fopen("sdata.bin", "wb");
	num_ret = 0;	// 저장된 레코드 수

	while (1) {
		// Fill your code
		if (fscanf(fp_r,"%s %d %lf",item.name, &item.stno, &item.gpa) != EOF) {		// fscanf 함수를 써서 text file의 한 줄에 있는 정보(이름 학번 성적)를 읽어서 item(student 구조체)에 저장함 (text 파일의 내용이 없을 때 까지 반복(fscanf 결과 값이 EOF인 경우))
			fwrite(&item, sizeof(item), 1, fp_w);	// item(struct 구조체)에 저장된 정보들을 sdata.bin 파일에 저장함 
			num_ret++;								// 저장한 레코드 수를 1증가
		}
		else
			break;	// fscanf 결과 값이 EOF 가 나온 경우 파일의 모든 내용을 읽었으므로 반복문에서 빠져나옴
	}

	fclose(fp_r);
	fclose(fp_w);

	// 레코드 번호를 주면 binary file의 해당 레코드를 읽어오기 
	// 음수를 입력하면 종료 
	fp = fopen("sdata.bin", "r+b");
	do {
		printf("Input type record number:");
		char_ptr = gets(line);

		if (!char_ptr)
			break;
		rn = atoi(line);

		// Fill your code
		if (rn < 0) 		// 입력 받은 레코드 번호가 음수인 경우 do while문을 빠져나가며 프로그램을 종료함
			printf("프로그램 종료\n");

		else if (rn >= num_ret)	// 입력 받은 레코드 번호가 저장된 레코드 수 이상인 경우 (레코드 번호는 0부터 시작하며 가장 큰 레코드 번호는 (저장된 레코드 수(num_ret) - 1) 이다) 잘못된 입력이라 표시하고 레코드 번호를 다시 입력 받음 (rn >= 0 이므로 do while문을 다시 시작)
			printf("잘못된 입력입니다. 입력한 Record #%d \n", rn);
		
		else {	// 정상적인 레코드 번호를 입력한 경우 
			fseek(fp, sizeof(item) * rn, SEEK_SET);	// binary file의 해당 레코드의 위치로 이동하여
			fread(&item, sizeof(item), 1, fp);		// 해당 레코드를 읽어오며 item(student 구조체)에 저장하여 

			printf("Record #%d = %s %d %5.2f\n", rn, item.name, item.stno, item.gpa);	// 읽어온 정보들을 출력함
		}
	} while (rn >= 0);
	fclose(fp);

	return 0;
}