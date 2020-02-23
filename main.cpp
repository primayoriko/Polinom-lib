#include <bits/stdc++.h>
#include "PolinomNaive.hpp"
#include "PolinomDnC.hpp"
using namespace std;

const int MAX = 1e3 + 8;

PolinomNaive aN, bN;
PolinomDnC aD, bD;

int randNum(int range, int cnt)
{
    srand(time(0) - cnt);
    int num = rand() % (2 * range);
    num -= range;
    //cout << num << endl;
    return num;
}

void randPol(Polinom &p, Polinom &q, int size1, int size2, int type)
{
    if (type == 1)
    {
        PolinomNaive temp1(size1), temp2(size2);
        for (int i = 0; i < size2; i++)
            temp1.setElmt(i, (double)randNum(100, i * i));
        for (int i = 0; i < size2; i++)
            temp2.setElmt(i, (double)randNum(100, i * i));
        p = temp1;
        q = temp2;
        cout << "Polinom hasil generate:" << endl;
        p.printAll();
        cout << p.getSize() << endl;
    }

    else if (type == 2)
    {
        PolinomDnC temp1(size1), temp2(size2);
        for (int i = 0; i < size2; i++)
            temp1.setElmt(i, (double)randNum(100, i * i));
        for (int i = 0; i < size2; i++)
            temp2.setElmt(i, (double)randNum(100, i * i));
        p = temp1;
        q = temp2;
        cout << "Polinom hasil generate:" << endl;
        p.printAll();
    }
}

void multiplyPol(int t)
{
    PolinomNaive N1, N2, Nres;
    PolinomDnC D1, D2, Dres;
    int n1, n2, opsi;
    string s;
    printf("Pilih metode input polinom:\n1. Generate random\n2. Dari file\n");
    cin >> opsi;

    switch (opsi)
    {
    case 1:
        printf("Input derajat/orde polinom 1: ");
        cin >> n1;
        printf("Input derajat/orde polinom 2: ");
        cin >> n2;
        if (t = 1)
            randPol(N1, N2, n1, n2, 1);
        else
            randPol(D1, D2, n1, n2, 2);
        break;
    case 2:
        printf("Input nama file: ");
        cin >> s;
        freopen(s, "r", stdin);
        cin >> n1 >> n2;
        double arr1[n1], arr2[n2];
        for (int i = 0; i < n1; i++)
            cin >> arr1[i];
        for (int i = 0; i < n2; i++)
            cin >> arr2[i];
        if (t == 1)
        {
            N1.setElmt(n1, arr1);
            N2.setElmt(n2, arr2);
        }
        else
        {
            D1.setElmt(n1, arr1);
            D2.setElmt(n2, arr2);
        }
        fclose(stdin);
        break;
    default:
        printf("Input tidak valid!!\n");
        return;
    }

    printf("Polinom Hasilnya adalah \n");
    if (t == 1)
    {
        Nres = N1 * N2;
        Nres.printAll();
        Nres.printAll("resultNaive.txt");
        printf("Total Penjumlahan/Pengurangan: %d\n Total Perkalian: %d\n", Nres.getNumPlusMinus(), Nres.getNumProduct());
    }
    else if (t == 2)
    {
        Dres = D1 * D2;
        Dres.printAll();
        Dres.printAll("resultDnC.txt");
        printf("Total Penjumlahan/Pengurangan: %d\n Total Perkalian: %d\n", Dres.getNumPlusMinus(), Dres.getNumProduct());
    }
    cout << "\nTotal Durasi Komputasi: " << fixed << dur << setprecision(6) << " ms";
}

void sumSubstractPol(int t)
{
    Polinom A, B, Pres;
    int n1, n2, opsi;
    string s;
    printf("Pilih metode input polinom:\n1. Generate random\n2. Dari file\n");
    cin >> opsi;
    switch (opsi)
    {
    case 1:
        printf("Input derajat/orde polinom 1: ");
        cin >> n1;
        printf("Input derajat/orde polinom 2: ");
        cin >> n2;
        randPol(A, B, n1, n2, 1);
        break;
    case 2:
        printf("Input nama file: ");
        cin >> s;
        freopen(s, "r", stdin);
        cin >> n1 >> n2;
        double arr1[n1], arr2[n2];

        for (int i = 0; i < n1; i++)
            cin >> arr1[i];
        for (int i = 0; i < n2; i++)
            cin >> arr2[i];

        A.setElmt(n1, arr1);
        B.setElmt(n2, arr2);
        fclose(stdin);
        break;
    default:
        printf("Input tidak valid!!\n");
        return;
    }
    printf("Polinom Hasilnya adalah \n");
    if (t == 2)
        Pres = A + B;
    else
        Pres = A - B;

    Pres.printAll();
    Pres.printAll("resultPlusMinus.txt");
    printf("Total Penjumlahan/Pengurangan: %d\n Total Perkalian: %d\n", Pres.getNumPlusMinus(), Pres.getNumProduct());
    cout << "\nTotal Durasi Komputasi: " << fixed << dur << setprecision(6) << " ms";
}

int menu(bool &lp)
{
    printf("Polinom APPS\nPilih Operasi:\n 1. Perkalian\n 2. Penjumlahan\n 3. Pembagian\n 4. Exit\n\nMasukkan pilihan: ");
    int opsi;
    cin >> opsi;
    switch (opsi)
    {
    case 1:
        printf("\nMasukkan metode:\n 1. Brute Force\n 2. Divide and Conquer\n\nMasukkan pilihan: ");
        cin >> opsi;
        if (opsi == 1)
            multiplyPol(opsi);
        else
            printf("Input tidak valid!!\n");
        break;
    case 2:
    case 3:
        sumSubstractPol(opsi);
        break;
    case 4:
        printf("Sampai jumpa!!\n");
        lp = false;
        break;
    default:
        printf("Input tidak valid!!\n");
        break;
    }
    return 0;
}

int main()
{
    bool lp = true;
    while (lp)
        menu(lp);
    return 0;
}