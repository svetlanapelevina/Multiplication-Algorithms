#include <iostream>
#include <fstream>
#include "Number.h"
#include "Multiplicator.h"
//#include <Python.h>

vector<double*> performCalculation(int k);
void outputCsv(vector<double*>);

int main()
{
    /*
    Number m = Multiplicator::generateRandomNumber(20);
    Number n = Multiplicator::generateRandomNumber(20);

    
    Number k = Multiplicator::karatsubaAlgorithm(*m, *n);
    cout << "\n";
    k.print();
    
    cout << Multiplicator::gradeSchoolAlgorithm(m, n) << endl;

    cout << Multiplicator::karatsubaAlgorithmTime(m, n) << endl;
    */
    vector<double*> results = performCalculation(7);

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
            time1 += Multiplicator::gradeSchoolAlgorithm(m, n);
            time2 += Multiplicator::karatsubaAlgorithmTime(m, n);
        }
        result.push_back(new double[2]{ time1 / 3, time2 / 3 });
    }
    return result;
}

void outputCsv(vector<double*> values)
{
    ofstream file;
    file.open("results_of_algorithms.csv");
    file << "index" << "," << "first" << "," << "second" << "\n";
    for (int i = 0; i < values.size(); i++)
    {
        cout << values[i][0] << endl;
        cout << values[i][1] << endl;
        file << i + 1 << "," << values[i][0] << "," << values[i][1] << "\n";
    }
    file.close();
}
