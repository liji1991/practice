#define _CRT_SECURE_NO_WARNINGS
#include <cstdlib>
#include <cstdio>
#include <cstring>

int main01()
{
	int i = 0;
	FILE *fp = NULL;
	const char *filename = "./1.txt";
	char a[27] = "ablccccs";
	fp = fopen(filename, "r+");
	if (fp == NULL) {
		printf("func fopen() err.\n");
		return -1;
	}
	printf("打开成功!\n");
	for (i = 0;i < strlen(a);i++) {
		fputc(a[i], fp);
	}
	fclose(fp);


	return 0;



}

int main02()
{
	int i = 0;
	FILE *fp = NULL;
	const char *filename = "./1.txt";
	char a[27] = "ablccccs";
	fp = fopen(filename, "r+");
	if (fp == NULL) {
		printf("func fopen() err.\n");
		return -1;
	}
	printf("打开成功!\n");

	while (!feof(fp)) {
		char tmpc = fgetc(fp);
		printf("%c", tmpc);
	}
	if (fp != NULL) {
		fclose(fp);
	}


	return 0;



}

int main()
{
	main02();

	system("pause");
	return 0;
}