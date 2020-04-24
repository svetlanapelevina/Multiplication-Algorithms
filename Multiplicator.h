#pragma once
#include "Number.h"

class Multiplicator
{
public:
	static Number generateRandomNumber(int k);

	static Number gradeSchoolAlgorithm(Number number1, Number number2);

	static double gradeSchoolAlgorithmTime(Number number1, Number number2);

	static Number divideAndConquer(Number number1, Number number2);

	static double divideAndConquerTime(Number number1, Number number2);

	static Number karatsubaAlgorithm(Number number1, Number number2);

	static double karatsubaAlgorithmTime(Number number1, Number number2);

	
};
