#include <bits/stdc++.h>
#include "Polinom.hpp"
using namespace std;

Polinom::Polinom()
{
    numplusminus = 0;
    numproduct = 0;
    size = 0;
}

Polinom::Polinom(int siz)
{
    numplusminus = numproduct = 0;
    size = siz;
    elmt = new double[size];
}

Polinom::Polinom(double *d, int siz)
{
    numplusminus = 0;
    numproduct = 0;
    while (siz >= 1 && d[siz - 1] == 0)
    {
        siz--;
    }
    size = siz;
    elmt = new double[size];
    //cout << sizeof(elmt) << endl;
    for (int i = 0; i < size; i++)
    {
        elmt[i] = d[i];
    }
}

Polinom::Polinom(Polinom const &p)
{
    size = p.size;
    elmt = new double[size];
    for (int i = 0; i < size; i++)
    {
        elmt[i] = p.elmt[i];
    }
    numplusminus = p.numplusminus;
    numproduct = p.numproduct;
    begins = p.begins;
    ends = p.ends;
}

Polinom::~Polinom()
{
    if (size != 0)
        delete[] elmt;
}

Polinom Polinom::operator=(Polinom const &p)
{
    if (size != 0)
        delete[] elmt;
    Polinom x(p);
    return x;
}

Polinom Polinom::operator+(Polinom const &p)
{
    Polinom x;
    x.size = max(size, p.size);
    x.elmt = new double[x.size];
    x.begins = clock();
    for (int i = 0; i < x.size; i++)
    {
        if (i > size)
            x.elmt[i] = p.elmt[i];
        else if (i > p.size)
            x.elmt[i] = elmt[i];
        else
            x.elmt[i] = elmt[i] + p.elmt[i];
        x.numplusminus++;
    }
    x.ends = clock();
    int k = x.size;
    while (k >= 1 && x.elmt[k - 1] == 0)
    {
        k--;
    }
    Polinom y(x.elmt, k);
    y.begins = x.begins;
    y.ends = x.ends;
    y.numplusminus = x.numplusminus;
    return y;
}

Polinom Polinom::operator-(Polinom const &p)
{
    Polinom x;
    x.size = max(size, p.size);
    x.elmt = new double[x.size];
    x.begins = clock();
    for (int i = 0; i < x.size; i++)
    {
        if (i > size)
            x.elmt[i] = -1 * p.elmt[i];
        else if (i > p.size)
            x.elmt[i] = elmt[i];
        else
            x.elmt[i] = elmt[i] - p.elmt[i];
        x.numplusminus++;
    }
    x.ends = clock();
    int k = x.size;
    while (k >= 1 && x.elmt[k - 1] == 0)
    {
        k--;
    }
    Polinom y(x.elmt, k);
    y.begins = x.begins;
    y.ends = x.ends;
    y.numplusminus = x.numplusminus;
    return y;
}

Polinom Polinom::operator*(Polinom const &p)
{
    return *this;
}

int Polinom::getDegree()
{
    return size - 1;
}

int Polinom::getSize()
{
    return size;
}

double Polinom::getElmt(int i)
{
    return elmt[i];
}

int Polinom::getNumPlusMinus()
{
    return numplusminus;
}

int Polinom::getNumProduct()
{
    return numproduct;
}

double Polinom::getOpDuration()
{
    return (double)(ends - begins) / (double)CLOCKS_PER_SEC * (double)1000;
}

void Polinom::resizeElmt(int siz)
{
    // if (size != 0)
    //     delete[] elmt;
    elmt = new double[siz];
    size = siz;
}

void Polinom::setElmt(int i, double x)
{
    elmt[i] = x;
}

void Polinom::setElmt(int siz, double *arr)
{
    size = siz;
    if (size != 0)
        delete[] elmt;
    elmt = new double[siz];
    for (int i = 0; i < siz; i++)
        elmt[i] = arr[i];
}

void Polinom::printAll()
{
    for (int i = size - 1; i > -1; i--)
    {
        if (elmt[i] == 0)
            continue;
        else if (elmt[i] < 0)
        {
            if (i == size - 1)
                cout << "-";
            else
                cout << " - ";
        }
        else
        {
            if (i != size - 1)
                cout << " + ";
        }

        if (abs(elmt[i]) != 1 || (i == 0 && elmt[i] != 0))
            cout << abs(elmt[i]);
        if (i != 0)
            cout << "x^" << i;
    }
    cout << endl;
}

void Polinom::printAll(const char *filename)
{
    freopen(filename, "w", stdout);
    printAll();
    fclose(stdout);
}