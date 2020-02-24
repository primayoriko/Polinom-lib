#include "PolinomNaive.hpp"
using namespace std;

PolinomNaive::PolinomNaive() : Polinom() {}

PolinomNaive::PolinomNaive(int n) : Polinom(n) {}

PolinomNaive::PolinomNaive(double *q, int r) : Polinom(q, r) {}

PolinomNaive::PolinomNaive(PolinomNaive const &q) : Polinom(q) {}

PolinomNaive PolinomNaive::operator*(PolinomNaive const &p)
{
    PolinomNaive x;
    double temp[size + p.size - 1];
    for (int i = 0; i < sizeof(temp) / sizeof(double); i++)
        temp[i] = 0;

    x.begins = clock();
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < p.size; j++)
        {
            if (elmt[i] != 0 && p.elmt[j] != 0)
            {
                x.numplusminus++;
                x.numproduct++;
                temp[i + j] += elmt[i] * p.elmt[j];
            }
        }
    }
    x.ends = clock();
    int k = size + p.size - 1;
    while (k >= 1 && temp[k - 1] == 0)
    {
        k--;
    }
    x.size = k;
    x.elmt = new double[k];
    for (int i = 0; i < k; i++)
    {
        x.elmt[i] = temp[i];
    }
    return x;
}