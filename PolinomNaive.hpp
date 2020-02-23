#ifndef POLINOMNAIVE_HPP
#define POLINOMNAIVE_HPP
#include "Polinom.hpp"

class PolinomNaive : public Polinom
{
public:
    PolinomNaive();
    PolinomNaive(int);
    PolinomNaive(double *, int);
    PolinomNaive(PolinomNaive const &);
    PolinomNaive operator*(PolinomNaive const &);
};

#endif