#ifndef Polinom_HPP
#define Polinom_HPP
#include <bits/stdc++.h>

class Polinom
{
public:
    // Konstruktor Destruktor
    Polinom();
    Polinom(int);
    Polinom(double *, int);
    Polinom(Polinom const &);
    ~Polinom();

    // Operator Overload
    Polinom operator=(Polinom const &);
    Polinom operator+(Polinom const &);
    Polinom operator-(Polinom const &);
    virtual Polinom operator*(Polinom const &);

    // Getter
    int getDegree();
    int getSize();
    double getElmt(int);
    int getNumPlusMinus();
    int getNumProduct();
    double getOpDuration();

    // Setter
    void resizeElmt(int);
    void setElmt(int, double);
    void setElmt(int, double *);

    // Fungsi Misc
    void printAll();
    void printAll(const char *);

protected:
    // Data
    int size;
    double *elmt;
    int numplusminus, numproduct;
    clock_t begins, ends;
};

#endif
