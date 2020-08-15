 #include "StrCls.h"

void StrCls::InputS(string &str) // Сделал отделный метод для дальнейшей модорнизации
{
	getline(cin, str);
}

// Проверка строки
int StrCls::CheckS(string &str) // 0 good. 1 not good
{
	int count = 0;
	
	for (char num : str) {
		count++;
		if ((int)num < 48 || (int)num > 57)
			return 1;
	}

	if (count > 64)
		return 1;

	return 0;
}

// Сортировка строки
void StrCls::SortS(string& str)
{
	string st = "KB";
	int ch;
	for (long unsigned int j = 1; j < str.length(); j++) {
		for (long unsigned int i = 1; i < str.length(); i++) {
			if (str[i] > str[i - 1]) {
				ch = str[i - 1];
				str[i - 1] = str[i];
				str[i] = ch;
			}
		}
	}
	for (long unsigned int i = 0; i < str.length(); i++) {
		if ((int)str[i] % 2 == 0) {
			str.replace(i, 1, st);
			i++;
		}
	}
}

// Вывод строки
void StrCls::OutputS(string& str)
{
	cout << str << endl;
}

// Сумма численных элементов
int StrCls::SumS(string& str)
{
	int count = 0;
	int cx;
	for (char num : str) {
		if ((int)num >= 48 && (int)num <= 57){
		cx = num - '0';
			count += cx;
		}
	}
	return count;
}