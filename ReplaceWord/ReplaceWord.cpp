#include <iostream>
using namespace std;

void f(char* str, char* word, char* word1) {
	// вычисление кол-ва слов
	int n = 0;
	char* p = str;
	while (p = strstr(p, word))
	{
		n++;
		p += strlen(word);
	}

	//создание итоговой строки
	int length = strlen(str) - n * strlen(word) + n * strlen(word1) + 1;
	char* res_str = new char[length] {};

	char* p2 = str; // p - для поиска слова, p2 - для подстроки после слова
	while (p = strstr(p2, word)) {
		strncat_s(res_str, length, p2, strlen(p2) - strlen(p));
		strcat_s(res_str, length, word1);
		p2 = p + strlen(word);
	}
	if (strlen(p2) > 0) strcat_s(res_str, length, p2);
	puts(res_str);
}

int main()
{
	setlocale(LC_ALL, "");

	// test 1
	char* text1 = new char[50] { "У лукоморья дуб зеленый" };
	char* word1 = new char[10] {"дуб"};
	char* replace_word1 = new char[10] {"кот"};
	f(text1, word1, replace_word1);
	
	// test 2
	char* text2 = new char[100] { "Берем колбасу, кладем колбасу на хлеб" };
	char* word2 = new char[15] { "колбасу" };
	char* replace_word2 = new char[15] { "сыр" };
	f(text2, word2, replace_word2);
	
	// test 3
	char* text3 = new char[150] { "В черном, черном городе, "
		"стоит в черном, черном доме дама в черном" };
	char* word3 = new char[50] { "черном" };
	char* replace_word3 = new char[50] { "светлом со стразами" };
	f(text3, word3, replace_word3);
	
	// test 4
	char* text4 = new char[250] { "небо небо небо небо небо небо "
		"небо небо небо небо небо небо небо небо небо небо небо "
		"небо небо небо небо небо небо небо небо небо небо небо небо небо " };
	char* word4 = new char[250] { "небо небо небо" };
	char* replace_word4 = new char[250] { "почва" };
	f(text4, word4, replace_word4);
}