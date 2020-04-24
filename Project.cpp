#include <iostream>
#include <fstream>
#include "Number.h"
#include "Multiplicator.h"

vector<double*> performCalculation(int k);
void outputCsv(vector<double*>);


int main()
{
    vector<double*> results = performCalculation(50);
    outputCsv(results);
}

vector<double*> performCalculation(int k)
{
    vector<double*> result;
    for (int i = 1; i <= k; i++)
    {
        double time1 = 0, time2 = 0, time3 = 0;
        for (int j = 0; j < 3; j++)
        {
            Number m = Multiplicator::generateRandomNumber(i);
            Number n = Multiplicator::generateRandomNumber(i);
            time1 += Multiplicator::gradeSchoolAlgorithmTime(m, n);
            time2 += Multiplicator::divideAndConquerTime(m, n);
            time3 += Multiplicator::karatsubaAlgorithmTime(m, n);
        }
        result.push_back(new double[3]{ time1 / 3, time2 / 3, time3 / 3 });
    }
    return result;
}

void outputCsv(vector<double*> values)
{
    ofstream file;
    file.open("results_of_algorithms2.csv");
    file << "Index" << "," << "Grand School Algorithm" << "," << "Divide And Conquer Algorithm" << "," << "Karatsuba Algorithm" << "\n";
    for (int i = 0; i < values.size(); i++)
    {
        file << i + 1 << "," << values[i][0] << "," << values[i][1] << "," << values[i][2] << "\n";
    }
    file.close();
}
