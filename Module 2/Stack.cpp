#include <iostream>
#include <conio.h>
#include <stdlib.h>

#define MAX 20

using namespace std;

struct Stack {
    int data[MAX];
    int top;
};
Stack Tumpuk;

void inisialisasi() {
    Tumpuk.top = -1;
}
bool kosong() {
    return Tumpuk.top == -1;
}
bool penuh() {
    return Tumpuk.top == MAX - 1;
}
void push(int data) {
    if (penuh()) {
        cout << "Tumpukan Penuh\n";
    } else {
        Tumpuk.top++;
        Tumpuk.data[Tumpuk.top] = data;
        cout << "Data " << data << " Masuk Ke Stack\n";
    }
}
void pop() {
    if (kosong()) {
        cout << "Data Kosong\n";
    } else {
        cout << "Data Teratas Sudah Terambil: " << Tumpuk.data[Tumpuk.top] << endl;
        Tumpuk.top--;
    }
}

void tampil() {
    if (kosong()) {
        cout << "Tumpukan Kosong\n";
    } else {
        for (int i = Tumpuk.top; i >= 0; i--) {
            cout << "Tumpukan Ke " << i << " = " << Tumpuk.data[i] << endl;
        }
    }
}
void reset() {
    Tumpuk.top = -1;
    cout << "Tumpukan Kosong !\n";
}
int main(){
int pilihan, nilai;
inisialisasi();

do {
    cout << "\n=== MENU STACK ===\n";
    cout << "1. Push (Input)\n";
    cout << "2. Pop (Hapus)\n";
    cout << "3. Tampilkan Stack\n";
    cout << "4. Reset Stack\n";
    cout << "5. Keluar\n";
    cout << "Pilih: ";
    cin >> pilihan;

    switch (pilihan) {
        case 1:
            cout << "Masukkan data: ";
            cin >> nilai;
            push(nilai);
            break;
        case 2:
            pop();
            break;
        case 3:
            tampil();
            break;
        case 4:
            reset();
            break;
        case 5:
            cout << "Keluar...\n";
            break;
        default:
            cout << "Pilihan tidak valid\n";
    }
    cout << "\nTekan tombol apapun untuk melanjutkan...";
    getch();
    system("cls");
} while (pilihan != 5);

return 0;
}