#pragma once
#include <string.h>
#include <iostream>
#include <fstream>
using namespace std;
class Flow2
{
	public:
	string GetStr();
	void CleanBuf();
	void OutputStr(string& str);
	int SumStr(string& str);
};