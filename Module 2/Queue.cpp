#include <iostream>
#include <conio.h>
#include <stdlib.h>
#define n 10
using namespace std;
int PIL, F, R;
char PILIHAN[1], HURUF;
char Q[n];

void INSERT() {
    if (R >= n - 1) {
        cout << "Queue PENUH!" << endl;
    } else {
        cout << "Masukkan 1 huruf: ";
        cin >> HURUF;
        if (F == -1) F = 0;
        R++;
        Q[R] = HURUF;
        cout << "Huruf '" << HURUF << "' dimasukkan ke queue." << endl;
    }
}

void DELETE() {
    if (F == -1 || F > R) {
        cout << "Queue KOSONG!" << endl;
    } else {
        cout << "Huruf '" << Q[F] << "' dihapus dari queue." << endl;
        Q[F] = ' ';
        F++;
        if (F > R) {
            F = R = -1; 
        }
    }
}

void CETAKLAYAR() {
    cout << "Isi QUEUE : ";
    if (F == -1 || F > R) {
        cout << "KOSONG" << endl;
    } else {
        for (int i = F; i <= R; i++) {
            cout << Q[i] << " ";
        }
        cout << endl;
    }
}

void RESET() {
    for (int i = 0; i < n; i++) {
        Q[i] = ' ';
    }
    F = R = -1;
}

void Inisialisasi() {
    F = R = -1;
    RESET();
}

int main()
{
    Inisialisasi();
    do
    {
        cout << "QUEUE" << endl;
        cout << "==================" << endl;
        cout << "1. INSERT" << endl;
        cout << "2. DELETE" << endl;
        cout << "3. CETAK QUEUE" << endl;
        cout << "4. RESET QUEUE" << endl;
        cout << "5. QUIT" << endl;
        cout << "PILIHAN : "; cin >> PILIHAN;
        PIL = atoi(PILIHAN);

        switch (PIL)
        {
            case 1:
                INSERT();
                break;
            case 2:
                DELETE();
                break;
            case 3:
                CETAKLAYAR();
                break;
            case 4:
                RESET();
                cout << "Queue direset!" << endl;
                break;
            default:
                cout << "TERIMA KASIH" << endl;
                break;
        }
        cout << "press any key to continue" << endl;
        getch();
        system("cls");
    }
    while (PIL != 5);
    return 0; }