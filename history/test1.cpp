#include <bits/stdc++.h>
#include "PolinomNaive.hpp"
using namespace std;

int main()
{
    double x[] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};
    double y[] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};
    PolinomNaive p(x, 12), q(y, 12);
    PolinomNaive u = p * q;
    cout << u.getNumPlusMinus() << ' ' << u.getNumProduct() << endl;
    u.printAll();
    // Polinom n = p + q;
    // cout << n.getSize() << endl;
    // n.printAll();
    return 0;
}
