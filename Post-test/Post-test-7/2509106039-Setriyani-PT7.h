#ifndef KERANG_H
#define KERANG_H

#include <iostream>
#include <string>
#include <vector>
#include <stdexcept>
using namespace std;

void validasiInputTidakKosong(const string &teks, const string &nama_field) {
    if (teks.empty()) {
        throw invalid_argument(nama_field + " tidak boleh kosong!");
    }
}

void validasiRole(const string &role) {
    if (role != "user" && role != "admin") {
        throw invalid_argument("Role ga valid! Pilih 'user' atau 'admin'.");
    }
}

void validasiNomorPilihan(int nomor, int batas_bawah, int batas_atas) {
    if (nomor < batas_bawah || nomor > batas_atas) {
        throw out_of_range("Nomor di luar batas! Masukkan antara "
                           + to_string(batas_bawah) + "-" + to_string(batas_atas) + ".");
    }
}

void validasiNilai(double nilai) {
    if (nilai < 0 || nilai > 100) {
        throw out_of_range("Nilai harus antara 0-100!");
    }
}

void validasiVectorTidakKosong(int ukuran, const string &nama_data) {
    if (ukuran == 0) {
        throw runtime_error(nama_data + " masih kosong!");
    }
}

#endif