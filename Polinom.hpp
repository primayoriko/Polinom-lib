#ifndef Polinom_HPP
#define Polinom_HPP
#include <bits/stdc++.h>

class Polinom
{
public:
    Polinom();
    Polinom(int);
    Polinom(double *, int);
    //Polinom(double[], int);
    Polinom(Polinom const &);
    ~Polinom();

    Polinom operator=(Polinom const &);
    Polinom operator+(Polinom const &);
    Polinom operator-(Polinom const &);
    virtual Polinom operator*(Polinom const &);

    int getDegree();
    int getSize();
    double getElmt(int);
    int getNumPlusMinus();
    int getNumProduct();
    double getOpDuration();

    void resizeElmt(int);
    void setElmt(int, double);
    void setElmt(int, double *);

    void printAll();
    void printAll(const char *);

protected:
    int size;
    double *elmt;
    int numplusminus, numproduct;
    clock_t begins, ends;
};

#endif