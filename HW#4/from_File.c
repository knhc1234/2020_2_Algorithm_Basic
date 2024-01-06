// from_File.c 

#include "functions.h" 

void Trie_I_from_File(nptr_pck package, char FileName[])
{
	char word[WORD_LEN] = { 0 }; 

	FILE* fp = fopen(FileName, "r"); 

	if (!fp) {
		printf("%s ���� �б� �������� ������ �߻��Ͽ����ϴ�.\n", FileName);
		printf("�۾��� ����մϴ�.");
		return;
	}	// if () 

	while (1) {
		// FileName ���ϻ󿡼� ���پ� �޴´�
		if (fgets(word, WORD_LEN, fp) == NULL) { break; }
		// fgets() �Լ��� '\n'���� �����Ƿ� ���ڿ� ���� ���� '\n'����
		strtok(word, "\n");
		// Trie�� ����
		insert_trie(package, word);
	}	// while (1) 

	fclose(fp);

	printf("%s ���Ϸκ��� Trie Insertion��(��) �Ϸ�Ǿ����ϴ�.\n", FileName); 

	return;
} 

void compare_to_the_Original(char Original[], char Print_FileName[])
{
	int flag = 1; 

	char word1[WORD_LEN] = { 0 }; 
	char word2[WORD_LEN] = { 0 }; 

	FILE* fp1 = fopen(Original, "r"); 
	FILE* fp2 = fopen(Print_FileName, "r"); 

	if (!fp1) {
		printf("\t%s ���� �б� �������� ������ �߻��Ͽ����ϴ�.\n", Original);
		printf("\t�۾��� ����մϴ�.");
		return;
	}	// if () 

	if (!fp2) {
		printf("\t%s ���� �б� �������� ������ �߻��Ͽ����ϴ�.\n", Print_FileName);
		printf("\t�۾��� ����մϴ�.");
		return;
	}	// if () 

	while (1) {
		if (fgets(word1, WORD_LEN, fp1) != NULL && fgets(word2, WORD_LEN, fp2) != NULL) {
			strtok(word1, "\n");
			strtok(word2, "\n");

			if (strcmp(word1, word2) == 0) {
				flag = 0;
			}	// if () 
			else {
				flag = 1;
				break;
			}	// else 
		}	// if () 
		else {
			if (fgets(word2, WORD_LEN, fp2) != NULL) {
				flag = 1;
			}	// if () 
			break;
		}	// else  

	}	// while (1) 

	fclose(fp1);
	fclose(fp2);

	if (flag == 0) {
		printf("\t%s ���ϰ� ��ġ�մϴ�.\n", Original); 
	}	// if () 
	else {
		printf("\t%s ���ϰ� ��ġ���� �ʽ��ϴ�.\n", Original);
	}	// else 

	return; 
}