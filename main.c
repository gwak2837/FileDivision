#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>
#include "FileDivision.h"

int main()
{
	char *path = (char *)calloc(200, sizeof(char));
	char *filename = (char *)calloc(50, sizeof(char));
	char buffer = 0;
	unsigned int filesize;
	FILE *source;
	FILE *destination;
	int i, j;

	fputs("파일 경로를 입력하세요 : ", stdout);
	fgets(path, _msize(path), stdin);
	delete_enter(path);

	fputs("파일 이름을 입력하세요 : ", stdout);
	fgets(filename, _msize(filename), stdin);
	delete_enter(filename);

	fputs("파일을 개당 몇 킬로바이트로 분할할까요? : ", stdout);
	scanf("%d", &filesize);
	getchar();

	strcat(path, "\\");
	strcat(path, filename);
	strcat(path, ".txt");
	path = (char *)realloc(path, strlen(path) + 10);
	filename = (char *)realloc(filename, strlen(filename) + 1);

	source = fopen(path, "r");
	if (source == NULL)
	{
		puts("지정된 경로의 파일을 열 수 없습니다.");
		return -1;
	}

	for (i = 1; buffer != EOF; i++)
	{
		delete_filename(path);
		create_filename(path, filename, i);
		destination = fopen(path, "w");
		if (destination == NULL)
		{
			puts("파일을 열 수 없습니다.");
			return -2;
		}

		for (j = 0; j < filesize * 1024 && buffer != EOF; j++)
		{
			buffer = fgetc(source);
			fputc(buffer, destination);
		}
		fclose(destination);
	}
	
	free(path);
	free(filename);
	fputs("\n\n성공!\n", stdout);
	system("pause");
	return 0;
}
