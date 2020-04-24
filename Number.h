#pragma once
#include <vector>
#include <algorithm>
#include <iostream>
#include "Number.h"
using namespace std;
class Number
{
protected:
	//vector<int> digits;
	string digits;
public:
	static const int BASE = 10;
	Number();
	Number(int num);
	Number(string str);
	int getSize();
	int getDigit(int index);
	void setDigit(int index, int value);
	void addDigit(int digit);
	void addDigitToIndex(int digit, int index);
	void removeDigit();
	Number operator+(Number secondNumber);
	Number operator-(Number secondNumber);
	void print();
	Number* splitNumber();
};
