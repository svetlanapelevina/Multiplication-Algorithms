#include "Multiplicator.h"
#include "Number.h"
#include <ctime>
#include <string>

Number  Multiplicator::generateRandomNumber(int k)
{
	Number result = Number("0");
	for (int i = 0; i < k-1; i++)
	{
		result.addDigit(rand() % Number::BASE);
	}

	// fist digit can't be 0
	result.addDigit(rand() % (Number::BASE-1) + 1);

	return result;
}

Number Multiplicator::gradeSchoolAlgorithm(Number number1, Number number2)
{
	Number result = Number("0");

	// push '0' in the vector for conveniences
	for (int i = 0; i < number1.getSize() + number2.getSize(); i++)
	{
		result.addDigit(0);
	}

	// 2 indexes to find position in the result
	int resIndex1 = 0;
	int resIndex2 = 0;

	for (int i = 0; i < number1.getSize(); i++)
	{
		int carry = 0;
		resIndex2 = 0;
		for (int j = 0; j < number2.getSize(); j++)
		{
			int sum = number1.getDigit(i) * number2.getDigit(j) + result.getDigit(resIndex1 + resIndex2) + carry;
			carry = sum / Number::BASE;
			result.setDigit(resIndex1 + resIndex2, sum % Number::BASE);
			resIndex2++;
		}

		result.setDigit(resIndex1 + resIndex2, result.getDigit(resIndex1 + resIndex2) + carry);
		resIndex1++;
	}

	// remove '0' from the begin
	while (result.getSize() > 1 && result.getDigit(result.getSize() - 1) == 0)
	{
		result.removeDigit();
	}

	//result.print();

	return result;
}

double Multiplicator::gradeSchoolAlgorithmTime(Number number1, Number number2)
{
	clock_t start = clock();

	gradeSchoolAlgorithm(number1, number2);

	return (double)(clock() - start);
}

Number Multiplicator::divideAndConquer(Number number1, Number number2)
{
	int maxSize = max(number1.getSize(), number2.getSize());
	
	if (maxSize == 1) return Number(to_string(number1.getDigit(0) * number2.getDigit(0)));

	if (number1.getSize() == 0) return Number("0");
	if (number2.getSize() == 0) return Number("0");	

	Number* splitedNumber1 = number1.splitNumber();
	Number* splitedNumber2 = number2.splitNumber();
	Number a = splitedNumber1[0];
	Number b = splitedNumber1[1];
	Number c = splitedNumber2[0];
	Number d = splitedNumber2[1];

	delete[] splitedNumber1;
	delete[] splitedNumber2;

	Number ac = divideAndConquer(a, c);
	Number bd = divideAndConquer(b, d);
	Number ad = divideAndConquer(a, d);
	Number bc = divideAndConquer(b, c);
	Number ad_bc = ad + bc;

	for (int i = 0; i < 2 * (maxSize / 2); i++)
	{
		ac.addDigitToIndex(0, 0);
	}

	for (int i = 0; i < maxSize / 2; i++)
	{
		ad_bc.addDigitToIndex(0, 0);
	}

	//(ac + bd + ad_bc).print();

	return (ac + bd + ad_bc);
}

double Multiplicator::divideAndConquerTime(Number number1, Number number2)
{
	clock_t start = clock();

	divideAndConquer(number1, number2);

	return (double)(clock() - start);
}

Number Multiplicator::karatsubaAlgorithm(Number number1, Number number2)
{
	int maxSize = max(number1.getSize(), number2.getSize());
	
	if (maxSize == 1) return Number(to_string(number1.getDigit(0) * number2.getDigit(0)));

	if (number1.getSize() == 0) return Number("0");
	if (number2.getSize() == 0) return Number("0");

	Number* splitedNumber1 = number1.splitNumber();
	Number* splitedNumber2 = number2.splitNumber();
	Number a = splitedNumber1[0];
	Number b = splitedNumber1[1];
	Number c = splitedNumber2[0];
	Number d = splitedNumber2[1];

	delete[] splitedNumber1;
	delete[] splitedNumber2;

	Number ac = karatsubaAlgorithm(a, c);
	Number bd = karatsubaAlgorithm(b, d);
	Number ad_bc = karatsubaAlgorithm(a + b, c + d) - (ac + bd);

	for (int i = 0; i < 2 * (maxSize / 2); i++)
	{
		ac.addDigitToIndex(0, 0);
	}

	for (int i = 0; i < maxSize / 2; i++)
	{
		ad_bc.addDigitToIndex(0, 0);
	}

	//(ac + bd + ad_bc).print();

	return (ac + bd + ad_bc);
}

double Multiplicator::karatsubaAlgorithmTime(Number number1, Number number2)
{
	clock_t start = clock();

	karatsubaAlgorithm(number1, number2);

	return (double)(clock() - start);
}

