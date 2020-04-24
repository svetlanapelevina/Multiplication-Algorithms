#include <iostream>
#include <fstream>
#include "Number.h"
#include "Multiplicator.h"

vector<double*> performCalculation(int k);
void outputCsv(vector<double*>);


int main()
{
    vector<double*> results = performCalculation(10);
    outputCsv(results);
}

vector<double*> performCalculation(int k)
{
    vector<double*> result;
    for (int i = 1; i <= k; i++)
    {
        double time1 = 0;
        double time2 = 0;
        for (int j = 0; j < 3; j++)
        {
            Number m = Multiplicator::generateRandomNumber(i);
            Number n = Multiplicator::generateRandomNumber(i);
            time1 += Multiplicator::gradeSchoolAlgorithmTime(m, n);
            time2 += Multiplicator::karatsubaAlgorithmTime(m, n);
        }
        result.push_back(new double[2]{ time1 / 3, time2 / 3 });
    }
    return result;
}

void outputCsv(vector<double*> values)
{
    ofstream file;
    file.open("results_of_algorithms2.csv");
    file << "Index" << "," << "Grand School Algorithm" << "," << "Karatsuba Algprothm" << "\n";
    for (int i = 0; i < values.size(); i++)
    {
        cout << values[i][0] << endl;
        cout << values[i][1] << endl;
        file << i + 1 << "," << values[i][0] << "," << values[i][1] << "\n";
    }
    file.close();
}
