#include <iostream>
#include <string>

using namespace std;

struct mhs
{
    string nama, nim, jurusan;
    int sks, program;
};

mhs bayar[2];

int main()
{
    int bts, var, tetap;

    for (int i=0; i < 2 ; i++)
    {
        cout << "-----------------------------------------------------";
        cout << "\n\nNama mhs                    = "; getline(cin, bayar[i].nama);
        cout << "NIM                         = "; getline(cin, bayar[i].nim); 
        cout << "Jurusan{TI, PTK}            = "; getline(cin, bayar[i].jurusan); 
         
        input:
        cout << "Program{1 = D3, 2=S1)       = ";
        cin  >> bayar[i].program;

        if (bayar[i].program < 1 || bayar[i].program > 2)
        {
            cout << "Program tidak sesuai\n";
            goto input;
        } cout << "Jumlah sks                  = "; cin >> bayar[i].sks;

        if (bayar[i].program == 1)
        {
            tetap = 500000;
            var = bayar[i].sks*25000;
        } else if(bayar[i].program == 2)
        
        {
            tetap = 750000;
            var = bayar[i].sks*50000;
        } cout << endl;

        cout << "\n\n-----------------------------------------------------\n"
             << " Output "
             << "\n-----------------------------------------------------\n"
             << "\nNama mhs                    = " << bayar[i].nama
             << "\nNIM                         = " << bayar[i].nim
             << "\nJurusan                     = " << bayar[i].jurusan
             << "\nProgram                     = " << bayar[i].program
             << "\nJumlah sks                  = " << bayar[i].sks
             << "\nSPP tetap                   = " << tetap
             << "\nSPP variable                = " << var << endl << endl; cin.ignore();

    }
    return 0;
}