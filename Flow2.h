#pragma once
#include <string.h>
#include <iostream>
#include <fstream>
using namespace std;
class Flow2
{
	private:
	//string str;
	public:
	// potok 2
	string GetStr();
	void CleanBuf();
	void OutputStr(string& str);
	int SumStr(string& str);
};