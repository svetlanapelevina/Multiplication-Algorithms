#include <string>
#include <algorithm>
#include "Number.h"

using namespace std;

Number::Number() {}

Number::Number(string str)
{
	for (int i = str.length() - 1; i >= 0; i--)
	{
		digits += str[i];
	}
}

Number::Number(int num)
{
	while (num > 0)
	{
		digits += to_string(num % BASE);
		num = num / BASE;
	}
}

int Number::getSize()
{
	return digits.length();
}

int Number::getDigit(int index)
{
	return digits[index] - '0';
}

void Number::setDigit(int index, int value)
{
	digits[index] = (char)(value + '0');
}

void Number::addDigit(int digit)
{
	digits += to_string(digit);
}

void Number::addDigitToIndex(int digit, int index)
{
	digits.insert(index, to_string(digit));
}

void Number::removeDigit()
{
	digits.pop_back();
}

Number Number::operator+(Number secondNumber)
{
	string result;

	if (digits.size() == 0) return secondNumber;
	if (secondNumber.digits.size() == 0) return *this;

	int maxSize = max(secondNumber.digits.size(), digits.size());

	while (secondNumber.digits.length() < maxSize)
		secondNumber.addDigit(0);

	while (digits.size() < maxSize)
		this->addDigit(0);

	int carry = 0;
	for (int i = 0; i < maxSize; i++)
	{
		int sum = ((digits[i] - '0') + (secondNumber.digits[i] - '0') + carry);
		result += to_string(sum % BASE);
		carry = sum / BASE;
	}

	if (carry != 0) result += to_string(carry);

	// remove '0' from the begin
	while (result.size() > 1 && (char)result[result.size() - 1] == '0')
		result.pop_back();

	reverse(result.begin(), result.end());

	return Number(result);
}

Number Number::operator-(Number secondNumber)
{
	string result;

	while (secondNumber.digits.size() < digits.size())
		secondNumber.digits.push_back('0');

	int diff;
	int carry = 0;
	for (int i = 0; i < digits.size(); i++)
	{
		diff = digits[i] - '0' - (secondNumber.digits[i] - '0') - carry;
		if (diff >= 0)
		{
			result += to_string(diff);
			carry = 0;
		}
		else {
			result += to_string(diff + BASE);
			carry = (-diff) / 10 + 1;
		}
	}

	// remove '0' from the begin
	while (result.size() > 1 && (char)result[result.size() - 1] == '0')
		result.pop_back();

	reverse(result.begin(), result.end());

	return Number(result);
}

void Number::print()
{
	for (int i = digits.size() - 1; i >= 0; i--)
		cout << digits[i];
	cout << "\n";
}

Number* Number::splitNumber()
{
	Number* result = new Number[2];

	int n = getSize();

	if (n == 1)
	{
		result[0].addDigit(0);
		result[1].digits = digits;
		return result;
	}

	result[1].digits = digits.substr(0, n / 2);
	result[0].digits = digits.substr(n / 2, n - n / 2);

	return result;
}