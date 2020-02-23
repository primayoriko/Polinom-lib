#include <bits/stdc++.h>
#include "PolinomNaive.hpp"
#include "PolinomDnC.hpp"
using namespace std;

const int MAX = 1e3 + 8;

PolinomNaive aN, bN;
PolinomDnC aD, bD;

int randNum(int range, int cnt, time_t *t)
{
    srand(time(0) * time(t) * 1200 - cnt);
    int num = rand() % (2 * range);
    num -= range;
    //cout << num << endl;
    return num;
}

void randPol(Polinom *p, Polinom *q, int size1, int size2, int type)
{
    freopen("polRand.txt", "w", stdout);
    cout << size1 << ' ' << size2 << endl;
    if (type == 1)
    {
        PolinomNaive temp1(size1), temp2(size2);
        for (int i = 0; i < size2; i++)
        {
            time_t tim = time(nullptr);
            temp1.setElmt(i, (double)randNum(100, i * i * i, &tim));
            cout << temp1.getElmt(i) << ' ';
        }
        cout << endl;
        for (int i = size2 - 1; i >= 0; i--)
        {
            time_t tim = time(nullptr);
            temp2.setElmt(i, (double)randNum(100, i * i, &tim));
            cout << temp2.getElmt(i) << ' ';
        }
        //cout << "hashdash" << endl;
        // PolinomNaive r = temp1;
        *p = temp1;
        *q = temp2;
        //fclose(stdout);
        //cout << "sadjas" << endl;
        temp1.printAll();
        cout << "Polinom 1 hasil generate:" << endl;
        p->printAll();
        cout << "Polinom 2 hasil generate:" << endl;
        q->printAll();
        cout << p->getSize() << endl;
    }

    else if (type == 2)
    {
        PolinomDnC temp1(size1), temp2(size2);
        for (int i = 0; i < size2; i++)
        {
            time_t tim = time(nullptr);
            temp1.setElmt(i, (double)randNum(100, i * i, &tim));
            cout << temp1.getElmt(i) << ' ';
        }
        cout << endl;
        for (int i = size2 - 1; i >= 0; i--)
        {
            time_t tim = time(nullptr);
            temp2.setElmt(i, (double)randNum(100, i * i * i, &tim));
            cout << temp2.getElmt(i) << ' ';
        }
        cout << endl;
        *p = temp1;
        *q = temp2;
        cout << temp1.getSize() << ' ' << p->getSize() << endl;
        cout << "Polinom 1 hasil generate:" << endl;
        p->printAll();
        cout << "Polinom 2 hasil generate:" << endl;
        q->printAll();
    }
}

void multiplyPol(int t)
{
    PolinomNaive N1, N2, Nres;
    PolinomDnC D1, D2, Dres;
    int n1, n2, opsi;
    string s;
    double k;
    printf("Pilih metode input polinom:\n1. Generate random\n2. Dari file\n\nInput opsi: ");
    cin >> opsi;
    switch (opsi)
    {
    case 1:
        printf("Input derajat/orde polinom 1: ");
        cin >> n1;
        printf("Input derajat/orde polinom 2: ");
        cin >> n2;
        if (t = 1)
        {
            N1.resizeElmt(n1);
            N2.resizeElmt(n2);
            randPol(&N1, &N2, n1, n2, 1);
        }
        else
        {
            D1.resizeElmt(n1);
            D2.resizeElmt(n2);
            randPol(&D1, &D2, n1, n2, 2);
        }
        break;
    case 2:
        // printf("Input nama file: ");
        // cin >> s;
        freopen("polRand.txt", "r", stdin);
        cin >> n1 >> n2;
        if (t == 1)
        {
            N1.resizeElmt(n1);
            N2.resizeElmt(n2);
            for (int i = 0; i < n1; i++)
            {
                cin >> k;
                N1.setElmt(i, k);
            }
            for (int i = 0; i < n2; i++)
            {
                cin >> k;
                N2.setElmt(i, k);
            }
        }
        else
        {
            D1.resizeElmt(n1);
            D2.resizeElmt(n2);
            for (int i = 0; i < n1; i++)
            {
                cin >> k;
                D1.setElmt(i, k);
            }
            for (int i = 0; i < n2; i++)
            {
                cin >> k;
                D2.setElmt(i, k);
            }
        }

        for (int i = 0; i < n1; i++)
        {
            cin >> k;
            if (t == 1)
                N1.setElmt(i, k);
            else
                D1.setElmt(i, k);
        }
        for (int i = 0; i < n2; i++)
        {
            cin >> k;
            cin >> k;
            if (t == 1)
                N2.setElmt(i, k);
            else
                D2.setElmt(i, k);
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
        cout << "\nTotal Durasi Komputasi: " << fixed << Nres.getOpDuration() << setprecision(6) << " ms";
    }
    else if (t == 2)
    {
        Dres = D1 * D2;
        Dres.printAll();
        Dres.printAll("resultDnC.txt");
        printf("Total Penjumlahan/Pengurangan: %d\n Total Perkalian: %d\n", Dres.getNumPlusMinus(), Dres.getNumProduct());
        cout << "\nTotal Durasi Komputasi: " << fixed << Dres.getOpDuration() << setprecision(6) << " ms";
    }
}

void sumSubstractPol(int t)
{
    Polinom A, B, Pres;
    int n1, n2, opsi;
    string s;
    double k;
    printf("Pilih metode input polinom:\n1. Generate random\n2. Dari file\n\nInput opsi: ");
    cin >> opsi;
    switch (opsi)
    {
    case 1:
        printf("Input derajat/orde polinom 1: ");
        cin >> n1;
        printf("Input derajat/orde polinom 2: ");
        cin >> n2;
        A.resizeElmt(n1);
        B.resizeElmt(n2);
        randPol(&A, &B, n1, n2, 1);
        break;
    case 2:
        // printf("Input nama file: ");
        // cin >> s;
        freopen("polRand.txt", "r", stdin);
        cin >> n1 >> n2;
        A.resizeElmt(n1);
        B.resizeElmt(n2);
        for (int i = 0; i < n1; i++)
        {
            cin >> k;
            A.setElmt(i, k);
        }
        for (int i = 0; i < n2; i++)
        {
            cin >> k;
            B.setElmt(i, k);
        }
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
    cout << "\nTotal Durasi Komputasi: " << fixed << Pres.getOpDuration() << setprecision(6) << " ms";
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