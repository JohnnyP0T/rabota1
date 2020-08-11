#include "Flow1.h"
//using namespace std;
void Flow1::InputStr(string &str)
{
	//string str;
	cin >> str;
}

int Flow1::CheckStr(string &str) // 0 good. 1 not good
{
	int count = 0;
	
	for (char num : str) {
		//cout << num << endl;
		count++;
		if ((int)num < 48 || (int)num > 57)
			return 1;
	}
	if (count > 64)
		return 1;
	return 0;
}

void Flow1::SortingStr(string& str)
{
	string st = "KB";
	int ch;
	for (int j = 1; j < str.length(); j++) {
		for (int i = 1; i < str.length(); i++) {
			if (str[i] > str[i - 1]) {
				ch = str[i - 1];
				str[i - 1] = str[i];
				str[i] = ch;
			}
		}
	}
	for (int i = 0; i < str.length(); i++) {
		if ((int)str[i] % 2 == 0) {
			str.replace(i, 1, st);
			i++;
		}
	}
}

void Flow1::FilingBuf(string& str)
{
	ofstream file("buffer.txt");
	file << str;
	file.close();
}