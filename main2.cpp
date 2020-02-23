#include <bits/stdc++.h>
#include "PolinomDnC.hpp"
#include "PolinomNaive.hpp"
using namespace std;

/*
    Menu utama -> nanya gen random / operasi
*/
void mainMenu();

void menuGenerator()
{
    printf("Pilih orde/suku/derajat polinom yang akan di generate: ");
    int n, range = 100;
    cin >> n;
    if (!(n > 0))
    {
        printf("Input salah!!\n\n");
        mainMenu();
    }
    Polinom a(n), b(n);
    for (int i = 0; i < n; i++)
    {
        srand((time(0) * i) + 7);
        int num = rand() % (2 * range + 1);
        num -= range;
        a.setElmt(i, num);
    }
    for (int i = 0; i < n; i++)
    {
        srand((time(0) * i) + 13);
        int num = rand() % (2 * range + 1);
        num -= range;
        b.setElmt(i, num);
    }
    printf("\nPolinom hasil generate 1:\n");
    a.printAll();
    printf("\nPolinom hasil generate 2:\n");
    b.printAll();

    freopen("Pol.txt", "w", stdout);
    cout << n << endl;
    for (int i = 0; i < n; i++)
        cout << a.getElmt(i) << ' ';
    cout << endl;
    for (int i = 0; i < n; i++)
        cout << b.getElmt(i) << ' ';
    cout << endl;
    fclose(stdout);
}

void menuOperasi()
{
    printf("\nPilih Operasi:\n 1. Perkalian\n 2. Penjumlahan\n 3. Pengurangan\n\nMasukan pilihan: ");
    int opsi, opsi2, n;
    cin >> opsi;
    printf("\nPilih metode input:\n 1. Dari textfile(Pol.txt)\n 2. Manual\n\nMasukkan opsi: ");
    cin >> opsi2;

    if (opsi2 == 1)
        freopen("Pol.txt", "r", stdin);
    else if (opsi2 == 2)
        printf("\nMasukkan orde/derajat: ");
    cin >> n;
    if (!(n > 0))
    {
        printf("Input salah!!\n\n");
        mainMenu();
    }

    if (opsi == 1)
    {
        double temp;
        PolinomDnC D1(n), D2(n);
        PolinomNaive N1(n), N2(n);
        for (int i = 0; i < n; i++)
        {
            cin >> temp;
            D1.setElmt(i, temp);
            N1.setElmt(i, temp);
        }
        for (int i = 0; i < n; i++)
        {
            cin >> temp;
            D2.setElmt(i, temp);
            N2.setElmt(i, temp);
        }
        if (opsi2 == 1)
            fclose(stdin);
        PolinomDnC Dres = D1 * D2;
        PolinomNaive Nres = N1 * N2;

        printf("\nPolinom hasil DnC vers. Karatsuba:\n");
        Dres.printAll();
        printf("Jumlah perkalian: %d   |   Jumlah penjumlahan/pengurangan: %d\n", Dres.getNumProduct(), Dres.getNumPlusMinus());
        printf("Waktu eksekusi : %.2f ms\n\n", Dres.getOpDuration());
        printf("Polinom hasil Brute Force:\n");
        Dres.printAll();
        printf("Jumlah perkalian: %d   |   Jumlah penjumlahan/pengurangan: %d\n", Nres.getNumProduct(), Nres.getNumPlusMinus());
        printf("Waktu eksekusi : %.2f ms\n\n", Nres.getOpDuration());

        Dres.printAll("resDnC.txt");
        Nres.printAll("resNaive.txt");
    }

    else if (opsi == 2 || opsi == 3)
    {
        double temp;
        Polinom D1(n), D2(n);
        for (int i = 0; i < n; i++)
        {
            cin >> temp;
            D1.setElmt(i, temp);
        }
        for (int i = 0; i < n; i++)
        {
            cin >> temp;
            D2.setElmt(i, temp);
        }
        if (opsi2 == 1)
            fclose(stdin);

        Polinom Dres = (opsi == 2) ? (D1 + D2) : (D1 - D2);
        // if (opsi == 2)
        //     Dres = ;
        // else
        //     Dres = ;
        printf("\nPolinom hasil %s:\n", (opsi == 2) ? "Penjumlahan" : "Pengurangan");
        Dres.printAll();
        printf("Jumlah perkalian: %d   |   Jumlah penjumlahan/pengurangan: %d\n", Dres.getNumProduct(), Dres.getNumPlusMinus());
        printf("Waktu eksekusi : %.2f ms\n\n", Dres.getOpDuration());
        Dres.printAll("resPlusMinus.txt");
    }
    else
    {
        printf("Input salah!!\n\n");
        mainMenu();
    }
}

void mainMenu()
{
    printf("Polinom Apps:\n\n 1. Generator Polinom\n 2. Operasi Polinom\n 3. Exit\n\nMasukan pilihan: ");
    int opsi;

    cin >> opsi;
    if (opsi == 1)
        menuGenerator();
    else if (opsi == 2)
        menuOperasi();
    else if (opsi == 3)
        printf("Selamat tinggal!!\n");
    else
    {
        printf("Input salah!!\n\n");
        mainMenu();
    }
}

int main()
{
    mainMenu();
    return 0;
}