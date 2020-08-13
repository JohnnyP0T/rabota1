#include "Buf.h"

// Заполнение буфера
void Buf::FilB(string& str)
{
	ofstream file("buffer.txt");
	file << str;
	file.close();
} 


// Получение строки из буфера
string Buf::GetB()
{
	string str;
	ifstream file("buffer.txt");
	file >> str;
	file.close();
	return str;
}

//Очистка буфера
void Buf::CleanB()
{
	ofstream file("buffer.txt");
	file << "";
}