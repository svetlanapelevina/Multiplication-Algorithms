#pragma once
#include <vector>
#include <algorithm>
#include <iostream>
#include "Number.h"
using namespace std;
class Number
{
public:
	static const int BASE = 10;
	vector<int> digits;
	Number();
	Number(int num);
	Number(string str);
	Number operator+(Number secondNumber);
	Number operator-(Number secondNumber);
	static Number generateRandomNumber(int k);
	void print();
};
