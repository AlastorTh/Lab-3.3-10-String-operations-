#include "Header.h"

int main() 
{
	setlocale(LC_ALL, "Rus");

	/*FILE* in;
	FILE* out;
	in = fopen("Text.txt", "rt");*/
	
	int maxLen;
	int* len_ptr = &maxLen;
	maxLen=MaxString("Text.txt");   // ������� ������ ����. ������

	
	SpaceCreated("Text.txt", len_ptr);
	return 0;
}