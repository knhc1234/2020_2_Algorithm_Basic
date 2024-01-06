// print_PT.c

#include "functions.h"

void print_PT(ptr_record Rec, char menu)
{
	// ����ð� ��¿� ������
	float PT;
	LARGE_INTEGER TPS, ST, ET;
	LONGLONG CT;

	// ����ð� ���ϱ�(���� �ð�)
	QueryPerformanceFrequency(&TPS);
	QueryPerformanceCounter(&ST);

	// �޴��� ����
	switch (menu) { 
	case 'v':
		menu_v(Rec);
		break;
	case 'p':
		menu_p(Rec);
		break;
	default:
		printf("print_PT() �Լ����� ���� �߻�\n");
		return;
	}	// switch ()

	// ����ð� ���ϱ�
	QueryPerformanceCounter(&ET);
	CT = ET.QuadPart - ST.QuadPart;
	PT = (float)CT / (float)TPS.QuadPart;

	// ����ð� ���
	printf("\t����ð� %f��\n", PT);
}