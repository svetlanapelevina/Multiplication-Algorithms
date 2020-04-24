#include "Multiplicator.h"
#include "Number.h"
#include <ctime>

Number  Multiplicator::generateRandomNumber(int k)
{
	Number result;
	for (int i = 0; i < k; i++)
	{
		result.digits.push_back(rand() % 10);
	}
	return result;
}


//Time Complexity: O(m*n), where m and n are length of two number that need to be multiplied.

double Multiplicator::gradeSchoolAlgorithm(Number number1, Number number2)
{
	srand(time(0));

	Number result;
	
	// push '0' in the vector for conveniences
	for (int i = 0; i < number1.digits.size()+number2.digits.size(); i++)
		result.digits.push_back(0);

	// 2 indexes to find position in the result
	int resIndex1 = 0;
	int resIndex2 = 0;

	for (int i = 0; i < number1.digits.size(); i++)
	{
		int carry = 0;
		resIndex2 = 0;

		for (int j = 0; j < number2.digits.size(); j++)
		{
			int sum = number1.digits[i] * number2.digits[j] + 
				result.digits[resIndex1 + resIndex2] + carry;
			carry = sum / Number::BASE;
			result.digits[resIndex1 + resIndex2] = sum % Number::BASE;
			resIndex2++;
		}

		result.digits[resIndex1 + resIndex2] += carry;
		resIndex1++;
	}

	// remove '0' from the begin
	while (result.digits.size() > 1 && result.digits[result.digits.size() - 1] == 0)
		result.digits.pop_back();

	//result.print();

	return (double) clock() ;
}

Number* splitNumber(Number number)
{
	Number* result = new Number[2];

	int n = number.digits.size();

	if (n == 1)
	{
		result[0].digits.push_back(0);
		result[1].digits.push_back(number.digits[0]);
		return result;
	}

	for (int i = 0; i < n / 2; i++)
		result[1].digits.push_back(number.digits[i]);

	for (int i = n / 2; i < n; i++)
		result[0].digits.push_back(number.digits[i]);

	return result;
}

Number Multiplicator::karatsubaAlgorithm(Number number1, Number number2)
{
	int maxSize = max(number1.digits.size(), number2.digits.size());
	/*
	while (number1.digits.size() < maxSize)
		number1.digits.push_back(0);

	while (number2.digits.size() < maxSize)
		number2.digits.push_back(0);
	
	cout << "111111111\n";
	number1.print();
	number2.print();*/

	if (maxSize == 1)
		return Number(number1.digits[0] * number2.digits[0]);

	Number a = splitNumber(number1)[0];
	Number b = splitNumber(number1)[1];
	Number c = splitNumber(number2)[0];
	Number d = splitNumber(number2)[1];


	Number ac = karatsubaAlgorithm(a, c);
	Number bd = karatsubaAlgorithm(b, d);
	Number p2 = karatsubaAlgorithm(a+b, c+d);
	Number ad_bc = p2 - (ac + bd);
	/*
	cout << "222222222\n";
	ac.print();
	bd.print();
	ad_bc.print();
	cout << "\n";
	*/
	for (int i = 0; i < 2 * (maxSize / 2); i++)
		ac.digits.insert(ac.digits.begin(), 0);

	//ac.print();

	for (int i = 0; i < maxSize / 2; i++)
		ad_bc.digits.insert(ad_bc.digits.begin(), 0);

	//ad_bc.print();

	Number result = ac + bd + ad_bc;

	//result.print();

	return result;
}

double Multiplicator::karatsubaAlgorithmTime(Number number1, Number number2)
{
	srand(time(0));

	Number k = karatsubaAlgorithm(number1, number2);

	return (double) clock();
}

