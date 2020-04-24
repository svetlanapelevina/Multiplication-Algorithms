#include <string>
#include <algorithm>
#include "Number.h"

// add getDigit
// setDigit


using namespace std;

Number::Number()
{

}

Number::Number(string str)
{
	for (int i = str.length()-1; i >= 0; i--)
	{
		digits.push_back(int(str[i] - '0'));
	}
}

Number::Number(int num)
{
	while (num > 0)
	{
		digits.push_back(num % BASE);
		num = num / BASE;
	}
}

Number Number::operator+(Number secondNumber)
{
	Number result;

	if (digits.size() == 0 || secondNumber.digits.size() == 0) return Number(0);

	int maxSize = max(secondNumber.digits.size(), digits.size());

	if (maxSize == 1) return digits[0] + secondNumber.digits[0];

	for (int i = 0; i < maxSize + 2; i++)
		result.digits.push_back(0);

	int carry = 0;
	for (size_t i = 0; i < maxSize || carry != 0; i++)
	{
		if (i == digits.size())
		{
			for (size_t j = digits.size(); j < secondNumber.digits.size(); j++)
			{
				result.digits[j] = (secondNumber.digits[j] + carry) % BASE;
			}
			break;
		}
		else if (i == secondNumber.digits.size())
		{
			for (size_t j = secondNumber.digits.size(); j < digits.size(); j++)
			{
				result.digits[j] = (digits[j] + carry) % BASE;
				carry = (digits[j] + carry) / BASE;
			}
			break;
		}
		else {
			result.digits[i] = (digits[i] + secondNumber.digits[i] + carry) % BASE;
			carry = (digits[i] + secondNumber.digits[i] + carry) / BASE;
		}
	}

	// remove '0' from the begin
	while (result.digits.size() > 1 && result.digits[result.digits.size() - 1] == 0)
		result.digits.pop_back();

	return result;
}

Number Number::operator-(Number secondNumber)
{
	// if left number < right number change them
	if (digits.size() < secondNumber.digits.size())
	{
		Number temp;
		for (int i = 0; i < digits.size(); i++)
			temp.digits.push_back(digits[i]);

		digits.clear();

		for (int i = 0; i < secondNumber.digits.size(); i++)
			digits.push_back(secondNumber.digits[i]);

		secondNumber.digits.clear();

		for (int i = 0; i < temp.digits.size(); i++)
			secondNumber.digits.push_back(temp.digits[i]);
	}

	while (secondNumber.digits.size() < digits.size())
		secondNumber.digits.push_back(0);

	Number result;

	while (result.digits.size() < digits.size())
		result.digits.push_back(0);

	int diff;
	int carry = 0;
	int i;

	for (i = 0; i < digits.size(); i++)
	{
		diff = digits[i] - secondNumber.digits[i] - carry;
		if (diff >= 0)
		{
			result.digits[i] = diff;
			carry = 0;
		}
		else {
			result.digits[i] = diff+BASE;
			carry = (-diff) / 10 + 1;
		}
	}

	// remove '0' from the begin
	while (result.digits.size() > 1 && result.digits[result.digits.size() - 1] == 0)
		result.digits.pop_back();

	return result;
}


void Number::print()
{
	for (int i = digits.size() - 1; i >= 0; i--)
		cout << digits[i];
	cout << "\n";
}