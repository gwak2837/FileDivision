#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void delete_enter(char *string)
{
	int i = 0;
	for (i = 0; i < strlen(string); i++)
	{
		if (string[i] == '\r' || string[i] == '\n')
		{
			string[i] = '\0';
			return;
		}
	}
	while (getchar() != '\n');
}

void delete_filename(char *string)
{
	int i = 0;
	while (string[i])
	{
		i++;
	}
	while (string[i] != '\\')
	{
		i--;
	}
	string[i + 1] = '\0';
}

void create_filename(char *path, char *filename, int num)
{
	char *snum = (char *)calloc(10, sizeof(char));
	sprintf(snum, "%d", num);

	strcat(path, filename);
	strcat(path, " ");
	strcat(path, snum);
	strcat(path, ".txt");
}
