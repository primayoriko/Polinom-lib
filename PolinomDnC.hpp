#ifndef POLINOMDNC_HPP
#define POLINOMDNC_HPP
#include <bits/stdc++.h>
#include "Polinom.hpp"
using namespace std;

class PolinomDnC : public Polinom
{
public:
    PolinomDnC();
    PolinomDnC(int);
    PolinomDnC(double *, int);
    PolinomDnC(PolinomDnC const &);
    PolinomDnC operator*(PolinomDnC const &);

protected:
    vector<double> countProduct(vector<double> *, vector<double> *, int, int, int *, int *);
    //double *countProduct(double *, double *, int, int);
};

#endif