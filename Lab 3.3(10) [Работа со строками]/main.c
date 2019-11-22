#include "Header.h"

int main() 
{
	setlocale(LC_ALL, "Rus");

	
	
	int maxLen;
	int* len_ptr = &maxLen;
	maxLen=MaxString("Text.txt");   // функция взятия макс. строки

	
	SpaceCreated("Temp.txt", len_ptr);
	return 0;
}