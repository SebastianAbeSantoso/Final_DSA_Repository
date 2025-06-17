#include <iostream>

using namespace std;

struct Kendaraan 
{
    string Plat_No, JenisKendaraan, NamaPemilik, Alamat, Kota;
};

int main()
{
    Kendaraan Mobil_1;
    
    Mobil_1.Plat_No = "DA1234MK";
    Mobil_1.JenisKendaraan = "RUSH";
    Mobil_1.NamaPemilik = "Andika Hartanto";
    Mobil_1.Alamat = "Jl. Kayu Tangi 1";
    Mobil_1.Kota = "Banjarmasin";

    cout << "\nPlat nomor      : " << Mobil_1.Plat_No
         << "\nJenis Kendaraan : " << Mobil_1.JenisKendaraan
         << "\nNama Pemilik    : " << Mobil_1.NamaPemilik
         << "\nAlamat Pemilik  : " << Mobil_1.Alamat
         << "\nKota Kendaraan  : " << Mobil_1.Kota;

    return 0;
}
