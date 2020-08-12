  #include "Flow2.h"

// Получение строки из буфера
string Flow2::GetStr()
{
	string str;
	ifstream file("buffer.txt");
	file >> str;
	file.close();
	return str;
}

//Очистка буфера
void Flow2::CleanBuf()
{
	ofstream file("buffer.txt");
	file << "";
}

// Вывод строки
void Flow2::OutputStr(string& str)
{
	cout << str << endl;
}

// Сумма численных элементов
int Flow2::SumStr(string& str)
{
	int count = 0;
	int cx;
	for (char num : str) {
		if ((int)num > 48 && (int)num < 57){
		cx = num - '0';
			count += cx;
		}
	}
	return count;
}
