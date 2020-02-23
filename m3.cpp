#include <bits/stdc++.h>
//#include "PolinomDnC.hpp"
using namespace std;

double *countProduct(double *a, double *b, int size_a, int size_b)
{
    int i, j;
    // Base Case (Conquer Part)
    if (size_a == 1 && size_b == 1)
    {
        double *ans = new double[1];
        //cout << "reach base case" << ' ' << a[0] << ' ' << b[0] << endl;
        //numproduct++;
        ans[0] = a[0] * b[0];
        return ans;
    }
    // else if (size_a == 1)
    // {
    //     double *ans = new double[size_b];
    //     cout << "reach base case" << ' ' << a[0] << endl;
    //     for (i = 0; i < size_b; i++)
    //         ans[i] = b[i] * a[0];
    //     numproduct += size_b;
    //     return ans;
    // }
    // else if (size_b == 1)
    // {
    //     double *ans = new double[size_a];
    //     cout << "reach base case" << ' ' << b[0] << endl;
    //     for (i = 0; i < size_a; i++)
    //         ans[i] = a[i] * b[0];
    //     numproduct += size_a;
    //     return ans;
    // }

    // Divide Part
    int ceil_a = pow(2, ceil(log2(size_a))), ceil_b = pow(2, ceil(log2(size_b)));
    int N = max(ceil_a, ceil_b);
    double t1[N], t2[N];

    for (i = 0; i < size_a; i++)
        t1[i] = a[i];
    for (; i < N; i++)
        t1[i] = 0;

    for (i = 0; i < size_b; i++)
        t2[i] = b[i];
    for (; i < N; i++)
        t2[i] = 0;

    // int mid = (size_a) / 2, mid = (size_b) / 2;
    int mid = N / 2;
    // cout << "ukuran" << ' ' << mid << ' ' << mid << endl;
    double *res = new double[2 * N + 1];
    double a1[mid], a2[mid];
    double b1[mid], b2[mid];
    double c1[mid], c2[mid];
    copy_n(t1, mid, a1);
    copy_n(t1 + mid, mid, a2);
    copy_n(t2, mid, b1);
    copy_n(t2 + mid, mid, b2);
    // for (i = 0; i < mid; i++)
    //     cout << a1[i] << ' ';
    // cout << endl;
    // for (i = 0; i < mid; i++)
    //     cout << a2[i] << ' ';
    // cout << endl;
    // for (i = 0; i < mid; i++)
    //     cout << b1[i] << ' ';
    // cout << endl;
    // for (i = 0; i < mid; i++)
    //     cout << b2[i] << ' ';
    // cout << endl;

    for (i = 0; i < mid; i++)
        c1[i] = a1[i] + a2[i];
    for (i = 0; i < mid; i++)
        c2[i] = b2[i] + b1[i];

    //cout << "success copy" << endl;
    double *res1 = countProduct(a1, b1, mid, mid);
    double *res2 = countProduct(c1, c2, mid, mid);
    double *res3 = countProduct(a2, b2, mid, mid);

    // Merge Part
    memset(res, 0, sizeof(res));
    for (i = 0; i < N; i++)
    {
        // if (res1[i])
        // {
        res[i] += res1[i];
        //numplusminus++;
        //}
        // if (res3[i])
        // {
        res[i + N] += res3[i];
        //numplusminus++;
        //}
        // if (res2[i] - res1[i] - res3[i])
        // {
        res[i + mid] += (res2[i] - res1[i] - res3[i]);
        //numplusminus++;
        // }
    }
    //Delete non-used container
    //if (res1 != NULL)
    // delete[] res1;
    // //if (res2 != NULL)
    // delete[] res2;
    // //if (res3 != NULL)
    // delete[] res3;
    //cout << "reach delete" << endl;

    for (i = 0; i < 2 * N; i++)
        cout << res[i] << ' ';
    cout << endl;
    return res;
}

vector<double> countProduct(vector<double> *a, vector<double> *b)
{
    int i, j;
    int size_a = a->size(), size_b = b->size();
    // Base Case (Conquer Part)
    if (size_a == 1 && size_b == 1)
    {
        vector<double> ans;
        //cout << "reach base case" << ' ' << a[0] << ' ' << b[0] << endl;
        //numproduct++;
        ans.push_back(a->at(0) * b->at(0));
        return ans;
    }
    // Divide Part
    int ceil_a = pow(2, ceil(log2(size_a))), ceil_b = pow(2, ceil(log2(size_b)));
    int N = max(ceil_a, ceil_b);
    double t1[N], t2[N];

    for (i = 0; i < size_a; i++)
        t1[i] = a->at(i);
    for (; i < N; i++)
        t1[i] = 0;

    for (i = 0; i < size_b; i++)
        t2[i] = b->at(i);
    for (; i < N; i++)
        t2[i] = 0;

    // for (i = 0; i < N; i++)
    //     cout << t1[i] << ' ';
    // cout << endl;
    // for (i = 0; i < N; i++)
    //     cout << t2[i] << ' ';
    // cout << endl;

    // int mid = (size_a) / 2, mid = (size_b) / 2;
    int mid = N / 2;
    // cout << "ukuran" << ' ' << mid << ' ' << mid << endl;
    vector<double> res;
    res.resize(2 * N);
    vector<double> a1, a2, b1, b2, c1, c2;
    a1.resize(mid);
    b1.resize(mid);
    c1.resize(mid);
    a2.resize(mid);
    b2.resize(mid);
    c2.resize(mid);
    copy_n(t1, mid, a1.begin());
    copy_n(t1 + mid, mid, a2.begin());
    copy_n(t2, mid, b1.begin());
    copy_n(t2 + mid, mid, b2.begin());
    // for (i = 0; i < mid; i++)
    //     cout << a1[i] << ' ';
    // cout << endl;
    // for (i = 0; i < mid; i++)
    //     cout << a2[i] << ' ';
    // cout << endl;
    // for (i = 0; i < mid; i++)
    //     cout << b1[i] << ' ';
    // cout << endl;
    // for (i = 0; i < mid; i++)
    //     cout << b2[i] << ' ';
    // cout << endl;

    for (i = 0; i < mid; i++)
        c1[i] = a1[i] + a2[i];
    for (i = 0; i < mid; i++)
        c2[i] = b2[i] + b1[i];

    //cout << "success copy" << endl;
    vector<double> res1 = countProduct(&a1, &b1);
    vector<double> res2 = countProduct(&c1, &c2);
    vector<double> res3 = countProduct(&a2, &b2);

    // Merge Part
    for (i = 0; i < N; i++)
    {
        res[i] += res1[i];
        //numplusminus++;
        res[i + N] += res3[i];
        res[i + mid] += (res2[i] - res1[i] - res3[i]);
    }

    return res;
}

vector<double> countProduct(vector<double> *a, vector<double> *b, int cnt, int N)
{
    int i, j;
    // Base Case (Conquer Part)
    if (N == 1)
    {
        //numproduct++;
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

    vector<double> p1 = countProduct(a, b, cnt, mid);
    vector<double> p2 = countProduct(&c1, &c2, 0, mid);
    vector<double> p3 = countProduct(a, b, cnt + mid, mid);

    vector<double> res;
    res.resize(2 * N);
    for (i = 0; i < 2 * N; i++)
        res[i] = 0;
    for (i = 0; i < N; i++)
    {
        res[i] += p1[i];
        res[i + mid] += (p2[i] - p1[i] - p3[i]);
        res[i + N] += p3[i];
    }

    return res;
}

vector<double> countProdN(vector<double> *a, vector<double> *b)
{
    vector<double> res;
    res.resize(2 * a->size());
    for (int i = 0; i < a->size(); i++)
        res[i] = 0;
    for (int i = 0; i < a->size(); i++)
    {
        for (int j = 0; j < a->size(); j++)
            res[i + j] += a->at(i) * b->at(j);
    }
    return res;
}

int main()
{
    int N = 350;
    // double x[N];
    // double y[N];
    vector<double> p, q;
    int i, j, N0 = N;
    N = pow(2, ceil(log2(N)));
    p.resize(N);
    q.resize(N);
    for (i = 0; i < N0; i++)
    {
        p[i] = 1;
        q[i] = 1;
    }
    for (; i < N; i++)
    {
        p[i] = 0;
        q[i] = 0;
    }
    // PolinomDnC p(x, 12), q(y, 12);
    // PolinomDnC u = p * q;
    clock_t ends, begins = clock();
    vector<double> res;
    res.resize(2 * N);
    // for (i = 0; i < 2 * N; i++)
    //     res[i] = 0;
    //
    res = countProdN(&p, &q);
    ends = clock();
    // for (i = 0; i < 2 * N0 - 1; i++)
    //     cout << res[i] << ' ';
    // cout << endl;
    double dur1 = (double)(ends - begins) / (double)CLOCKS_PER_SEC * (double)1000;
    begins = clock();
    res = countProduct(&p, &q, 0, N);
    ends = clock();
    double dur2 = (double)(ends - begins) / (double)CLOCKS_PER_SEC * (double)1000;
    cout << "\nTotal Durasi Komputasi Naive: " << fixed << dur1 << << setprecision(6) << " ms" << endl;
    cout << "\nTotal Durasi Komputasi DnC: " << fixed << dur2 << << setprecision(6) << " ms" << endl;
    vector<double> t;
    //cout << t.size() << ' ' << t[92] << endl;
    // t.resize(100);
    // cout << t.size() << ' ' << t[92] << endl;
    // cout << u.getNumPlusMinus() << ' ' << u.getNumProduct() << endl;
    // u.printAll();
    // Polinom n = p + q;
    // cout << n.getSize() << endl;
    // n.printAll();
    return 0;
}
