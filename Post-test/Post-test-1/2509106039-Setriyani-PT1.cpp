#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

int main() {

    string nama_benar    = "Setri";
    string password_benar = "039";  

    string nama_input;
    string password_input;

    int percobaan      = 0;
    int maks_percobaan = 3;
    bool login_berhasil = false;

    cout << "========================================" << endl;
    cout << "         SELAMAT DATANG                 " << endl;
    cout << "     PROGRAM KONVERSI PANJANG           " << endl;
    cout << "========================================" << endl;
    cout << endl;

    while (percobaan < maks_percobaan) {
        percobaan++;

        cout << "Percobaan ke-" << percobaan << " dari " << maks_percobaan << endl;
        cout << "----------------------------------------" << endl;
        cout << "Nama     : ";
        cin  >> nama_input;
        cout << "Password : ";
        cin  >> password_input;

        if (nama_input == nama_benar && password_input == password_benar) {
            login_berhasil = true;
            break;
        } else {
            if (percobaan < maks_percobaan) {
                cout << endl;
                cout << "  Nama atau passwordmu salah kocak!" << endl;
                cout << "      Sisa percobaan: " << (maks_percobaan - percobaan) << " kali" << endl;
                cout << endl;
            }
        }
    }

    if (!login_berhasil) {
        cout << endl;
        cout << "==========================================" << endl;
        cout << "  TUHKAN AKSES DITOLAK!                      " << endl;
        cout << " Kamu udah 3x salah, Programnya berhenti deh " << endl;
        cout << "==========================================" << endl;
        return 0;
    }

    cout << endl;
    cout << "========================================" << endl;
    cout << "   LOGIN BERHASIL CIHUY! Wassup, " << nama_benar << "!    " << endl;
    cout << "========================================" << endl;
    cout << endl;

    int pilihan_menu = 0;

    while (pilihan_menu != 4) {

        cout << "========================================" << endl;
        cout << "         MENU KONVERSI PANJANG          " << endl;
        cout << "========================================" << endl;
        cout << "  1. Meter      --> Kilometer & Centimeter" << endl;
        cout << "  2. Kilometer  --> Meter    & Centimeter" << endl;
        cout << "  3. Centimeter --> Meter    & Kilometer " << endl;
        cout << "  4. Keluar                              " << endl;
        cout << "========================================" << endl;
        cout << "  Pilih cepat. : ";
        cin  >> pilihan_menu;
        cout << endl;

        if (pilihan_menu == 1) {

            double nilai_meter = 0;
            cout << "  Masukin nilai dalam Meter: ";
            cin  >> nilai_meter;

            double hasil_kilometer  = nilai_meter / 1000.0;
            double hasil_centimeter = nilai_meter * 100.0;

            cout << endl;
            cout << "  ---- HASIL KONVERSI ----" << endl;
            cout << fixed << setprecision(4);
            cout << "  " << nilai_meter   << " Meter" << endl;
            cout << "    = " << hasil_kilometer  << " Kilometer" << endl;
            cout << "    = " << hasil_centimeter << " Centimeter" << endl;
            cout << "  ------------------------" << endl;
            cout << endl;

        } else if (pilihan_menu == 2) {
            
            double nilai_kilometer = 0;
            cout << "  Masukin nilai dalam Kilometer: ";
            cin  >> nilai_kilometer;

            double hasil_meter      = nilai_kilometer * 1000.0;
            double hasil_centimeter = nilai_kilometer * 100000.0;

            cout << endl;
            cout << "  ---- HASIL KONVERSI ----" << endl;
            cout << fixed << setprecision(4);
            cout << "  " << nilai_kilometer  << " Kilometer" << endl;
            cout << "    = " << hasil_meter      << " Meter" << endl;
            cout << "    = " << hasil_centimeter << " Centimeter" << endl;
            cout << "  ------------------------" << endl;
            cout << endl;

        } else if (pilihan_menu == 3) {

            double nilai_centimeter = 0;
            cout << "  Masukin nilai dalam Centimeter: ";
            cin  >> nilai_centimeter;

            double hasil_meter     = nilai_centimeter / 100.0;
            double hasil_kilometer = nilai_centimeter / 100000.0;

            cout << endl;
            cout << "  ---- HASIL KONVERSI ----" << endl;
            cout << fixed << setprecision(6);
            cout << "  " << nilai_centimeter << " Centimeter" << endl;
            cout << "    = " << hasil_meter      << " Meter" << endl;
            cout << "    = " << hasil_kilometer  << " Kilometer" << endl;
            cout << "  ------------------------" << endl;
            cout << endl;

        } else if (pilihan_menu == 4) {

            cout << "========================================" << endl;
            cout << "  Terima kasih dah nyoba program ini      " << endl;
            cout << "  lain kali gausah nyoba lagi             " << endl;
            cout << "  see you  " << nama_benar << "!          " << endl;
            cout << "========================================" << endl;
            cout << endl;

        } else {

            cout << "  Nguwawor Pilihanmu ga valid! Masukkan angka 1-4." << endl;
            cout << endl;

        }
    }

    return 0;
}