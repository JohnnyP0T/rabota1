  #include "Flow2.h"
 string Flow2::GetStr()
{
	string str;
	ifstream file("buffer.txt");
	file >> str;
	file.close();
	return str;
}

void Flow2::CleanBuf()
{
	ofstream file("buffer.txt");
	file << "";
}

void Flow2::OutputStr(string& str)
{
	cout << str;
}

int Flow2::SumStr(string& str)
{
	int count = 0;
	for (char num : str) {
		if ((int)num < 48 || (int)num > 57)
			count++;
	}
	return count;
}
