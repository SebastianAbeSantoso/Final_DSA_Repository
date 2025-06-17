#include <iostream>
#include <conio.h>
#include <random>
#include <vector>
#include <algorithm>

using namespace std;

void sequentialSearch(const vector<int> &nums, int target){
    vector<int> indices;

    for (auto i = 0; i < nums.size(); i++){
        if (nums[i] == target) indices.push_back(i);
    }
    if (indices.empty()) cout << "Angka " << target << " tidak ditemukan pada array" << endl;
    else {
        cout << "Angka " << target << " terdapat pada array sebanyak " << indices.size() << " kali" << endl;
        cout << "Angka " << target << " ditemukan pada indeks: ";
        for (auto i = 0; i < indices.size(); i++){
            cout << indices[i];
            if (i != indices.size() - 1) cout << ", ";
        }
        cout << "." << endl;
    }
}

void binarySearch(const vector<int> &nums, int target){
    int high = nums.size() - 1;
    int low = 0;
    int index = -1;

    while (low <= high){
        int mid = low + (high - low) / 2;

        if (nums[mid] == target){
            index = mid;
            break;
        }
        if (nums[mid] < target) low = mid + 1;
        else high = mid - 1;
    }

    if (index == -1) cout << "angka " << target << " tidak ditemukan pada array" << endl;
    else cout << "angka " << target << " ditemukan pada indeks ke " << index << endl; 
}

void clearTerminal(){
    system("cls");
}

void explanation() {
    cout << "\nPERBEDAAN SEQUENTIAL (LINEAR) SEARCH DENGAN BINARY SEARCH\n" << endl;

    cout << "SEQUENTIAL (LINEAR) SEARCH:" << endl;
    cout << "> Melakukan pengecekan elemen pada array secara berurutan (traversal dari indeks 0 hingga n-1)." << endl;
    cout << "> Jika elemen array yang dicek sama dengan elemen target, maka indeks tersebut dikembalikan atau dicetak." << endl;
    cout << "> Kompleksitas Waktu: O(n), karena dalam kasus terburuk harus memeriksa semua elemen." << endl;
    cout << "> Kompleksitas Ruang: O(1), hanya menggunakan variabel konstan." << endl;
    cout << "> Tidak ada syarat array harus terurut." << endl;
    cout << "> Dapat diterapkan pada:" << endl;
    cout << "  1. Data yang tidak terurut." << endl;
    cout << "  2. Data berukuran kecil di mana O(n) masih cukup efisien." << endl;
    cout << "  3. Struktur data seperti Linked List, di mana kita hanya bisa traversing satu per satu.\n" << endl;

    cout << "BINARY SEARCH:" << endl;
    cout << "> Hanya berlaku pada array yang sudah terurut (misalnya menaik)." << endl;
    cout << "> Inisialisasi indeks 'low' = 0 dan 'high' = n - 1. Lalu hitung mid = (low + high) / 2." << endl;
    cout << "> Bandingkan elemen di posisi mid dengan target:" << endl;
    cout << "  - Jika array[mid] == target, maka posisi mid dikembalikan atau dicetak." << endl;
    cout << "  - Jika array[mid] < target, cari pada subarray sebelah kanan (low = mid + 1)." << endl;
    cout << "  - Jika array[mid] > target, cari pada subarray sebelah kiri (high = mid - 1)." << endl;
    cout << "> Ulangi langkah di atas hingga target ditemukan atau low > high (artinya elemen tidak ada)." << endl;
    cout << "> Kompleksitas Waktu: O(log n), karena setiap iterasi ukuran interval setengahnya." << endl;
    cout << "> Kompleksitas Ruang: O(1) (iteratif); jika menggunakan rekursif, ruang menjadi O(log n) karena tumpukan panggil." << endl;
    cout << "> Syarat: array harus terurut lebih dulu." << endl;
    cout << "> Dapat diterapkan pada:" << endl;
    cout << "  1. Pencarian data pada dataset besar (misalnya indeks database yang sudah terurut)." << endl;
    cout << "  2. Aplikasi seperti pencarian di kamus/dictionary, bibliografi, atau katalog." << endl;
    cout << "  3. Algoritma pada Machine Learning (misalnya mencari nilai ambang di array terurut) dan Computer Graphics (ray tracing berbasis interval terurut, lookup tabel tekstur terurut).\n" << endl;

    cout << "Jadi perbedaannya adalah:" << endl;
    cout << "- Linear Search memeriksa setiap elemen satu per satu tanpa memerlukan array terurut, cocok untuk data kecil atau data yang tidak terurut, namun memiliki efisiensi O(n)." << endl;
    cout << "- Binary Search membagi ruang pencarian secara berulang (divide and conquer) dengan memanfaatkan array terurut, memberikan efisiensi O(log n), tetapi tidak bisa digunakan pada data yang belum terurut.\n" << endl;
}

int main() {
    int opt, target;
    do {
        cout << "Pilih menu" << endl;
        cout << "1. Sequential Searching" << endl;
        cout << "2. Binary Searching" << endl;
        cout << "3. Jelaskan Perbedaan Sequential Searching dan Binary Searching!" << endl;
        cout << "4. Exit" << endl;
        cout << "Pilih: ";
        cin >> opt;

        switch (opt) {
            case 1: {
                vector<int> nums (100);
                mt19937_64 rng(random_device{}());
                uniform_int_distribution<int> dist(1, 50);

                for (auto &val: nums) {
                    val = dist(rng);
                }

                cout << "Generating 100 numbers..." << endl;
                for (auto i = 0; i < nums.size(); i++){
                    cout << nums[i] << "[" << i << "]" << " ";
                }
                cout << endl;
                cout << "Masukkan angka yang ingin dicari: "; cin >> target;

                sequentialSearch(nums, target);
                break;
            }

            case 2: {
                int size;
                cout << "Masukkan ukuran vector: ";
                cin >> size;
                if (size < 1){
                    cout << "Error: Mohon masukkan bilangan di atas 0" << endl;
                    break;
                }

                vector<int> nums(size);
                mt19937_64 rng(random_device{}());
                uniform_int_distribution<int> dist(1, 100);

                for (auto &val: nums) {
                    val = (dist(rng));
                }

                sort(nums.begin(), nums.end());

                cout << "Generating " << size << " numbers..." << endl;
                for (auto i = 0; i < nums.size(); i++){
                    cout << nums[i] << "[" << i << "]" << " ";
                }
                cout << endl;
                cout << "Masukkan angka yang ingin dicari: "; cin >> target;

                binarySearch(nums, target);
                break;
            }

            case 3:
                explanation();
                break;

            case 4:
                cout << "\nTERIMA KASIH\n";
                cout << "Program was made by Sebastian Abe Santoso (2410817210002)" << endl;
                break;

            default:
                cout << "Opsi tidak terdefinisi, mohon masukkan ulang opsi" << endl;
                break;
        }

        if (opt != 4) {
            cout << "\nTekan tombol apa saja untuk melanjutkan...";
            getch();
            clearTerminal();
        }

    } while (opt != 4);

    return 0;
}