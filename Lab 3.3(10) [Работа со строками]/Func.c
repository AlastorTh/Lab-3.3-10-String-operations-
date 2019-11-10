#include "Header.h"

int MaxString(char *filename) // длина макс. строки
{
	FILE* in = fopen("Text.txt", "rt");
	char s[256];
	int i;
	int j;
	int k;
	int index;
	int cur_len;
	if (in == NULL) 
	{
		printf("Ошибка чтения входного файла!");
		return -1;
	}
	int max_loc = 0;
	int max_cur = 0;
	while (fgets(s, 256, in) != NULL) 
	{
		max_cur = strlen(s);
		if (s[strlen(s)-1] == '\n') 
		{
			max_cur -= 1;
		}
		if (max_cur > max_loc) 
		{
			max_loc = max_cur;
		}
		
		for (i = 0; i < strlen(s); i++) 
		{
			if (s[i] == '\t') 
			{
				cur_len = strlen(s);
				for (j = i; j <= cur_len; j++) 
				{
					s[j + 5] = s[j];
				}
				
				for (i; i<i+5; i++) 
				{
					s[i] = ' ';
				}

			}
		}
	}
	
	
	fclose(in);
	return max_loc;

}

int SpaceCreated(char* filename,int* len_ptr) 
{
	FILE* in = fopen("Text.txt", "rt");
	FILE* out = fopen("Output.txt", "wt");
	char s[256] = { 0 };
	int i;
	int cur_len=0;
	int delta = 0;
	int spaceLen;
	char spaceArr[256] = { 0 };
	char ToFile[256] = { 0 };
	
	if (in == NULL) 
	{
		printf("Ошибка чтения входного файла!");
		return -2;
	}

	if (out == NULL)
	{
		printf("Ошибка чтения входного файла!");
		return -3;
	}

	scanf("%d", &delta);
	if (delta < 0) 
	{
		printf("Delta below zero");
		return -5;
	}
	

	while (fgets(s, 256, in) != NULL) 
	{
		cur_len = strlen(s);
		if (s[strlen(s) - 1] == '\n')
		{
			cur_len -= 1;
		}

		spaceLen = ((*len_ptr-cur_len)/2)+delta;
		
		for (i = 0; i < spaceLen; i++) 
		{
			spaceArr[i] = ' ';
		}
		spaceArr[spaceLen] = '\0';
		strcpy(ToFile, spaceArr);
		strcat(ToFile, s);
		printf("%s", ToFile);
		fputs(ToFile, out);

	}
}