#include <bits/stdc++.h>
#include "PolinomDnC.hpp"
#include "PolinomNaive.hpp"
using namespace std;

int main()
{
    int N = 20000;
    double x[N];
    double y[N];
    vector<double> p, q;
    int i, j, N0 = N;
    N = pow(2, ceil(log2(N)));
    for (i = 0; i < N0; i++)
    {
        x[i] = 1;
        y[i] = 1;
    }

    PolinomNaive c(x, N0), d(y, N0);
    PolinomNaive z2 = c * d;
    PolinomDnC a(x, N0), b(x, N0);
    PolinomDnC z = a * b;
    //z.printAll();
    cout << z.getNumPlusMinus() << ' ' << z.getNumProduct() << ' ' << z.getOpDuration() << endl;
    //z2.printAll();
    cout << z2.getNumPlusMinus() << ' ' << z2.getNumProduct() << ' ' << z2.getOpDuration() << endl;
}