#include <iostream>
#include <string>

using namespace std;

struct program 
{
    char Huruf;
    string Kata;
    int Angka;
};

int main()
{
    program p;

    cout << "Masukkan sebuah huruf: "; cin >> p.Huruf;
    cout << "Masukkan sebuah kata : "; cin >> p.Kata;
    cout << "Masukkan sebuah angka: "; cin >> p.Angka;

    cout << "\nHuruf yang Anda masukkan adalah......" << p.Huruf
         << "\nKata yang Anda masukkan adalah......." << p.Kata
         << "\nAngka yang Anda Masukkan adalah......" << p.Angka;

    return 0;
}