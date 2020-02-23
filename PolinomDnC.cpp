#include "PolinomDnC.hpp"
#include <bits/stdc++.h>
using namespace std;

PolinomDnC::PolinomDnC() : Polinom() {}

PolinomDnC::PolinomDnC(int n) : Polinom(n) {}

PolinomDnC::PolinomDnC(double *q, int r) : Polinom(q, r) {}

PolinomDnC::PolinomDnC(PolinomDnC const &q) : Polinom(q) {}

PolinomDnC PolinomDnC::operator*(PolinomDnC const &p)
{
    PolinomDnC x;
    int N = max(pow(2, ceil(log2(size))), pow(2, ceil(log2(p.size))));
    vector<double> temp1, temp2, ans;
    temp1.resize(N);
    temp2.resize(N);
    ans.resize(2 * N);
    for (int i = 0; i < size; i++)
        temp1[i] = elmt[i];
    for (int i = 0; i < p.size; i++)
        temp2[i] = p.elmt[i];
    x.begins = clock();
    ans = countProduct(&temp1, &temp2, 0, N, &(x.numplusminus), &(x.numproduct));
    x.ends = clock();

    x.size = size + p.size - 1;
    x.elmt = new double[x.size];
    for (int i = 0; i < x.size; i++)
        x.elmt[i] = ans[i];
    //cout << x.getNumPlusMinus() << ' ' << x.getNumProduct() << endl;
    return x;
}

vector<double> PolinomDnC::countProduct(vector<double> *a, vector<double> *b, int cnt, int N, int *addPlus, int *addProd)
{
    int i, j;
    // Base Case (Conquer Part)
    if (N == 1)
    {
        (*addProd)++;
        vector<double> res = {a->at(cnt) * b->at(cnt)};
        return res;
    }

    // Divide Part
    int mid = N / 2;
    vector<double> c1, c2;
    c1.resize(mid);
    c2.resize(mid);
    for (i = 0; i < mid; i++)
    {
        c1[i] = a->at(i + cnt + mid) + a->at(i + cnt);
        c2[i] = b->at(i + cnt + mid) + b->at(i + cnt);
    }

    vector<double> p1 = countProduct(a, b, cnt, mid, addPlus, addProd);
    vector<double> p2 = countProduct(&c1, &c2, 0, mid, addPlus, addProd);
    vector<double> p3 = countProduct(a, b, cnt + mid, mid, addPlus, addProd);
    vector<double> res;
    res.resize(2 * N);
    for (i = 0; i < 2 * N; i++)
        res[i] = 0;
    for (i = 0; i < N; i++)
    {
        if (abs(p1[i]) > 1e-8)
        {
            res[i] += p1[i];
            (*addPlus)++;
        }
        if (abs(p2[i] - p1[i] - p3[i]) > 1e-8)
        {
            res[i + mid] += (p2[i] - p1[i] - p3[i]);
            (*addPlus)++;
        }
        if (abs(p3[i]) > 1e-8)
        {
            res[i + N] += p3[i];
            (*addPlus)++;
        }
    }
    return res;
}

// double *PolinomDnC::countProduct(double *a, double *b, int size_a, int size_b)
// {
//     int i, j;
//     // Base Case (Conquer Part)
//     if (size_a == 1 && size_b == 1)
//     {
//         double *ans = new double[1];
//         //cout << "reach base case" << ' ' << a[0] << ' ' << b[0] << endl;
//         numproduct++;
//         ans[0] = a[0] * b[0];
//         return ans;
//     }
//     // else if (size_a == 1)
//     // {
//     //     double *ans = new double[size_b];
//     //     cout << "reach base case" << ' ' << a[0] << endl;
//     //     for (i = 0; i < size_b; i++)
//     //         ans[i] = b[i] * a[0];
//     //     numproduct += size_b;
//     //     return ans;
//     // }
//     // else if (size_b == 1)
//     // {
//     //     double *ans = new double[size_a];
//     //     cout << "reach base case" << ' ' << b[0] << endl;
//     //     for (i = 0; i < size_a; i++)
//     //         ans[i] = a[i] * b[0];
//     //     numproduct += size_a;
//     //     return ans;
//     // }

//     // Divide Part
//     int ceil_a = pow(2, ceil(log2(size_a))), ceil_b = pow(2, ceil(log2(size_b)));
//     int N = max(ceil_a, ceil_b);
//     double t1[N], t2[N];

//     for (i = 0; i < size_a; i++)
//         t1[i] = a[i];
//     for (; i < N; i++)
//         t1[i] = 0;

//     for (i = 0; i < size_b; i++)
//         t2[i] = b[i];
//     for (; i < N; i++)
//         t2[i] = 0;

//     // int mid = (size_a) / 2, mid = (size_b) / 2;
//     int mid = N / 2;
//     // cout << "ukuran" << ' ' << mid << ' ' << mid << endl;
//     double *res = new double[2 * N];
//     double a1[mid], a2[mid];
//     double b1[mid], b2[mid];
//     double c1[mid], c2[mid];
//     copy_n(t1, mid, a1);
//     copy_n(t1 + mid, mid, a2);
//     copy_n(t2, mid, b1);
//     copy_n(t2 + mid, mid, b2);

//     for (i = 0; i < mid; i++)
//         c1[i] = a1[i] + a2[i];
//     for (i = 0; i < mid; i++)
//         c2[i] = b2[i] + b1[i];

//     //cout << "success copy" << endl;
//     double *res1 = countProduct(a1, b1, mid, mid);
//     double *res2 = countProduct(c1, c2, mid, mid);
//     double *res3 = countProduct(a2, b2, mid, mid);

//     // Merge Part
//     memset(res, 0, sizeof(res));
//     for (i = 0; i < max(size_a, size_b); i++)
//     {
//         // if (res1[i])
//         // {
//         res[i] += res1[i];
//         numplusminus++;
//         //}
//         // if (res3[i])
//         // {
//         res[i + N] += res3[i];
//         numplusminus++;
//         //}
//         // if (res2[i] - res1[i] - res3[i])
//         // {
//         res[i + mid] += (res2[i] - res1[i] - res3[i]);
//         numplusminus++;
//         // }
//     }
//     //Delete non-used container
//     // if (res1 != NULL)
//     //     delete[] res1;
//     // if (res2 != NULL)
//     //     delete[] res2;
//     // if (res3 != NULL)
//     //     delete[] res3;
//     //cout << "reach delete" << endl;

//     // for (i = 0; i < 2 * N; i++)
//     //     cout << res[i] << ' ';
//     // cout << endl;
//     return res;
// }