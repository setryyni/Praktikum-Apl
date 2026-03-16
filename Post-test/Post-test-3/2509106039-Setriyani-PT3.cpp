#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include <cstdlib>
#include <ctime>
using namespace std;

struct ProfilPengguna {
    string nama;
    string nim;
};

struct Pengguna {
    ProfilPengguna profil;
    string role;
    int jumlah_pertanyaan_dibuat;
};

struct Pertanyaan {
    string isi_pertanyaan;
    string jawaban_kerang;
    string nama_pemilik;
};

vector<Pengguna>   daftar_pengguna;
vector<Pertanyaan> daftar_pertanyaan;
vector<string>     bank_jawaban;

void inisialisasiBankJawaban() {
    bank_jawaban.push_back("Mungkin suatu hari nanti...");
    bank_jawaban.push_back("Tidak.");
    bank_jawaban.push_back("Coba lagi nanti.");
    bank_jawaban.push_back("Tentu saja.");
    bank_jawaban.push_back("Kerang tidak menjawab pertanyaan itu.");
    bank_jawaban.push_back("Sepertinya iya.");
    bank_jawaban.push_back("Sepertinya tidak.");
    bank_jawaban.push_back("Sudah jelas jawabannya.");
}

void tampilHeaderTabel(int lebar_col1, string judul_col1) {
    cout << "+-" << setfill('-') << setw(4) << "-"
         << "+-" << setw(lebar_col1) << "-" << "+" << endl;
    cout << setfill(' ');
    cout << "| " << left << setw(4) << "No"
         << "| " << setw(lebar_col1) << judul_col1 << "|" << endl;
    cout << "+-" << setfill('-') << setw(4) << "-"
         << "+-" << setw(lebar_col1) << "-" << "+" << endl;
    cout << setfill(' ');
}

void tampilHeaderTabel(int lebar_col1, int lebar_col2,
                       string judul_col1, string judul_col2) {
    cout << "+-" << setfill('-') << setw(4)        << "-"
         << "+-" << setw(lebar_col1) << "-"
         << "+-" << setw(lebar_col2) << "-" << "+" << endl;
    cout << setfill(' ');
    cout << "| " << left << setw(4)        << "No"
         << "| " << setw(lebar_col1) << judul_col1
         << "| " << setw(lebar_col2) << judul_col2 << "|" << endl;
    cout << "+-" << setfill('-') << setw(4)        << "-"
         << "+-" << setw(lebar_col1) << "-"
         << "+-" << setw(lebar_col2) << "-" << "+" << endl;
    cout << setfill(' ');
}

void tampilHeaderTabel(int lebar_col1, int lebar_col2, int lebar_col3,
                       string judul_col1, string judul_col2, string judul_col3) {
    cout << "+-" << setfill('-') << setw(4)        << "-"
         << "+-" << setw(lebar_col1) << "-"
         << "+-" << setw(lebar_col2) << "-"
         << "+-" << setw(lebar_col3) << "-" << "+" << endl;
    cout << setfill(' ');
    cout << "| " << left << setw(4)        << "No"
         << "| " << setw(lebar_col1) << judul_col1
         << "| " << setw(lebar_col2) << judul_col2
         << "| " << setw(lebar_col3) << judul_col3 << "|" << endl;
    cout << "+-" << setfill('-') << setw(4)        << "-"
         << "+-" << setw(lebar_col1) << "-"
         << "+-" << setw(lebar_col2) << "-"
         << "+-" << setw(lebar_col3) << "-" << "+" << endl;
    cout << setfill(' ');
}

void tampilGarisBawahTabel(int lebar_col1, int lebar_col2) {
    cout << "+-" << setfill('-') << setw(4)        << "-"
         << "+-" << setw(lebar_col1) << "-"
         << "+-" << setw(lebar_col2) << "-" << "+" << endl;
    cout << setfill(' ');
}

void tampilGarisBawahTabel(int lebar_col1, int lebar_col2, int lebar_col3) {
    cout << "+-" << setfill('-') << setw(4)        << "-"
         << "+-" << setw(lebar_col1) << "-"
         << "+-" << setw(lebar_col2) << "-"
         << "+-" << setw(lebar_col3) << "-" << "+" << endl;
    cout << setfill(' ');
}

void tampilBarisRekursif(int index_saat_ini, string nama_pemilik,
                         int &nomor_urut, int lebar_col1, int lebar_col2) {
    if (index_saat_ini >= (int)daftar_pertanyaan.size()) return;

    if (daftar_pertanyaan[index_saat_ini].nama_pemilik == nama_pemilik) {
        nomor_urut++;
        string pertanyaan = daftar_pertanyaan[index_saat_ini].isi_pertanyaan;
        string jawaban    = daftar_pertanyaan[index_saat_ini].jawaban_kerang;
        if ((int)pertanyaan.length() > lebar_col1 - 2)
            pertanyaan = pertanyaan.substr(0, lebar_col1 - 5) + "...";
        if ((int)jawaban.length() > lebar_col2 - 2)
            jawaban = jawaban.substr(0, lebar_col2 - 5) + "...";
        cout << "| " << left << setw(4)        << nomor_urut
             << "| " << setw(lebar_col1) << pertanyaan
             << "| " << setw(lebar_col2) << jawaban << "|" << endl;
    }

    tampilBarisRekursif(index_saat_ini + 1, nama_pemilik,
                        nomor_urut, lebar_col1, lebar_col2);
}

string ambilJawabanAcak(vector<string> &daftar_jawaban) {
    int index_acak = rand() % (int)daftar_jawaban.size();
    return daftar_jawaban[index_acak];
}

bool namaSudahAda(string nama_dicari) {
    for (int i = 0; i < (int)daftar_pengguna.size(); i++) {
        if (daftar_pengguna[i].profil.nama == nama_dicari)
            return true;
    }
    return false;
}

void registerPengguna() {
    string nama_input, nim_input, role_input;

    cout << "==========================================" << endl;
    cout << "               REGISTER                   " << endl;
    cout << "==========================================" << endl;
    cout << "  Nama             : "; getline(cin, nama_input);
    cout << "  Password (NIM)   : "; getline(cin, nim_input);
    cout << "  Role (user/admin): "; getline(cin, role_input);

    for (int i = 0; i < (int)role_input.length(); i++)
        role_input[i] = tolower(role_input[i]);

    if (role_input != "user" && role_input != "admin") {
        cout << "  Role ga valid! Pilih 'user' atau 'admin'." << endl << endl;
        return;
    }

    if (namaSudahAda(nama_input)) {
        cout << "  Nama udah ada, ganti yang lain." << endl << endl;
        return;
    }

    Pengguna pengguna_baru;
    pengguna_baru.profil.nama              = nama_input;
    pengguna_baru.profil.nim               = nim_input;
    pengguna_baru.role                     = role_input;
    pengguna_baru.jumlah_pertanyaan_dibuat = 0;
    daftar_pengguna.push_back(pengguna_baru);

    cout << "  You berhasil register sebagai " << role_input << ". Silakan login." << endl << endl;
}

int loginPengguna(vector<Pengguna> &daftar_pengguna) {
    int  percobaan       = 0;
    bool login_berhasil  = false;
    int  index_pengguna  = -1;

    cout << "==========================================" << endl;
    cout << "                 LOGIN                    " << endl;
    cout << "==========================================" << endl;

    while (percobaan < 3) {
        percobaan++;
        string nama_input, nim_input;
        cout << "  Percobaan ke-" << percobaan << " dari 3" << endl;
        cout << "  Nama          : "; getline(cin, nama_input);
        cout << "  Password (NIM): "; getline(cin, nim_input);

        string nama_input_lower = nama_input;
        for (int i = 0; i < (int)nama_input_lower.length(); i++)
            nama_input_lower[i] = tolower(nama_input_lower[i]);

        for (int i = 0; i < (int)daftar_pengguna.size(); i++) {
            string nama_tersimpan_lower = daftar_pengguna[i].profil.nama;
            for (int j = 0; j < (int)nama_tersimpan_lower.length(); j++)
                nama_tersimpan_lower[j] = tolower(nama_tersimpan_lower[j]);

            if (nama_tersimpan_lower == nama_input_lower &&
                daftar_pengguna[i].profil.nim == nim_input) {
                login_berhasil = true;
                index_pengguna = i;
            }
        }

        if (login_berhasil) break;

        if (percobaan < 3)
            cout << "  Nama atau NIM salah. Sisa: " << (3 - percobaan) << "x" << endl << endl;
    }

    return index_pengguna;
}

void tanyaKerang(int index_pengguna) {
    string pertanyaan_baru;
    cout << "  Tanyakan apapun pada kerang ajaib..." << endl;
    cout << "  Pertanyaanmu: "; getline(cin, pertanyaan_baru);

    string jawaban_terpilih = ambilJawabanAcak(bank_jawaban);

    Pertanyaan pertanyaan_baru_obj;
    pertanyaan_baru_obj.isi_pertanyaan = pertanyaan_baru;
    pertanyaan_baru_obj.jawaban_kerang = jawaban_terpilih;
    pertanyaan_baru_obj.nama_pemilik   = daftar_pengguna[index_pengguna].profil.nama;
    daftar_pertanyaan.push_back(pertanyaan_baru_obj);
    daftar_pengguna[index_pengguna].jumlah_pertanyaan_dibuat++;

    cout << endl;
    cout << "  Kerang Ajaib berkata.." << endl;
    cout << "  >> \"" << jawaban_terpilih << "\"" << endl << endl;
}

void lihatHistori(int index_pengguna) {
    string nama_aktif = daftar_pengguna[index_pengguna].profil.nama;
    int    jumlah_milik = daftar_pengguna[index_pengguna].jumlah_pertanyaan_dibuat;

    cout << "  Histori punya " << nama_aktif
         << " (" << jumlah_milik << " pertanyaan)" << endl;

    if (jumlah_milik == 0) {
        cout << "  Belum ada pertanyaan. Tanya kerang dulu kocak." << endl << endl;
        return;
    }

    tampilHeaderTabel(30, 30, "Pertanyaan", "Jawaban Kerang");
    int nomor_urut = 0;
    tampilBarisRekursif(0, nama_aktif, nomor_urut, 30, 30);
    tampilGarisBawahTabel(30, 30);
    cout << endl;
}

vector<int> kumpulkanIndexMilikUser(string nama_pemilik) {
    vector<int> daftar_index;
    for (int i = 0; i < (int)daftar_pertanyaan.size(); i++) {
        if (daftar_pertanyaan[i].nama_pemilik == nama_pemilik)
            daftar_index.push_back(i);
    }
    return daftar_index;
}

void tampilTabelPertanyaanUser(vector<int> daftar_index) {
    tampilHeaderTabel(45, "Pertanyaan");

    for (int i = 0; i < (int)daftar_index.size(); i++) {
        string pertanyaan = daftar_pertanyaan[daftar_index[i]].isi_pertanyaan;
        if ((int)pertanyaan.length() > 43) pertanyaan = pertanyaan.substr(0, 40) + "...";
        cout << "| " << left << setw(4) << i + 1
             << "| " << setw(45) << pertanyaan << "|" << endl;
    }

    cout << "+-" << setfill('-') << setw(4) << "-"
         << "+-" << setw(45)    << "-" << "+" << endl;
    cout << setfill(' ');
}

void editPertanyaan(int index_pengguna) {
    string nama_aktif   = daftar_pengguna[index_pengguna].profil.nama;
    vector<int> daftar_index = kumpulkanIndexMilikUser(nama_aktif);

    if (daftar_index.empty()) {
        cout << "  Belum ada pertanyaan." << endl << endl;
        return;
    }

    tampilTabelPertanyaanUser(daftar_index);

    int nomor_pilihan;
    cout << "  Pilih nomor: "; cin >> nomor_pilihan; cin.ignore();

    if (nomor_pilihan < 1 || nomor_pilihan > (int)daftar_index.size()) {
        cout << "  Nomor ga valid." << endl << endl;
        return;
    }

    string pertanyaan_baru;
    cout << "  Pertanyaan baru: "; getline(cin, pertanyaan_baru);

    string jawaban_baru = ambilJawabanAcak(bank_jawaban);
    int    index_asli   = daftar_index[nomor_pilihan - 1];

    daftar_pertanyaan[index_asli].isi_pertanyaan = pertanyaan_baru;
    daftar_pertanyaan[index_asli].jawaban_kerang = jawaban_baru;

    cout << "  Pertanyaan diperbarui!" << endl;
    cout << "  >> Kerang: \"" << jawaban_baru << "\"" << endl << endl;
}

void hapusPertanyaanUser(int index_pengguna) {
    string nama_aktif   = daftar_pengguna[index_pengguna].profil.nama;
    vector<int> daftar_index = kumpulkanIndexMilikUser(nama_aktif);

    if (daftar_index.empty()) {
        cout << "  Blom ada pertanyaan." << endl << endl;
        return;
    }

    tampilTabelPertanyaanUser(daftar_index);

    int nomor_pilihan;
    cout << "  Pilih nomor: "; cin >> nomor_pilihan; cin.ignore();

    if (nomor_pilihan < 1 || nomor_pilihan > (int)daftar_index.size()) {
        cout << "  Nomor ga valid." << endl << endl;
        return;
    }

    int index_asli = daftar_index[nomor_pilihan - 1];
    daftar_pertanyaan.erase(daftar_pertanyaan.begin() + index_asli);
    daftar_pengguna[index_pengguna].jumlah_pertanyaan_dibuat--;

    cout << "  Pertanyaan dihapus." << endl << endl;
}

void lihatSemuaPertanyaan() {
    if (daftar_pertanyaan.empty()) {
        cout << "  Belum ada pertanyaan." << endl << endl;
        return;
    }

    tampilHeaderTabel(15, 28, 28, "Pemilik", "Pertanyaan", "Jawaban");

    for (int i = 0; i < (int)daftar_pertanyaan.size(); i++) {
        string pemilik    = daftar_pertanyaan[i].nama_pemilik;
        string pertanyaan = daftar_pertanyaan[i].isi_pertanyaan;
        string jawaban    = daftar_pertanyaan[i].jawaban_kerang;
        if ((int)pemilik.length()    > 13) pemilik    = pemilik.substr(0, 10)    + "...";
        if ((int)pertanyaan.length() > 26) pertanyaan = pertanyaan.substr(0, 23) + "...";
        if ((int)jawaban.length()    > 26) jawaban    = jawaban.substr(0, 23)    + "...";
        cout << "| " << left << setw(4)  << i + 1
             << "| " << setw(15) << pemilik
             << "| " << setw(28) << pertanyaan
             << "| " << setw(28) << jawaban << "|" << endl;
    }

    tampilGarisBawahTabel(15, 28, 28);
    cout << endl;
}

void hapusPertanyaanAdmin() {
    if (daftar_pertanyaan.empty()) {
        cout << "  Blom ada pertanyaan." << endl << endl;
        return;
    }

    tampilHeaderTabel(15, 38, "Pemilik", "Pertanyaan");

    for (int i = 0; i < (int)daftar_pertanyaan.size(); i++) {
        string pemilik    = daftar_pertanyaan[i].nama_pemilik;
        string pertanyaan = daftar_pertanyaan[i].isi_pertanyaan;
        if ((int)pemilik.length()    > 13) pemilik    = pemilik.substr(0, 10)    + "...";
        if ((int)pertanyaan.length() > 36) pertanyaan = pertanyaan.substr(0, 33) + "...";
        cout << "| " << left << setw(4)  << i + 1
             << "| " << setw(15) << pemilik
             << "| " << setw(38) << pertanyaan << "|" << endl;
    }

    tampilGarisBawahTabel(15, 38);

    int nomor_pilihan;
    cout << "  Pilih nomor: "; cin >> nomor_pilihan; cin.ignore();

    if (nomor_pilihan < 1 || nomor_pilihan > (int)daftar_pertanyaan.size()) {
        cout << "  Nomor ga valid." << endl << endl;
        return;
    }

    int index_hapus = nomor_pilihan - 1;

    for (int i = 0; i < (int)daftar_pengguna.size(); i++) {
        if (daftar_pengguna[i].profil.nama == daftar_pertanyaan[index_hapus].nama_pemilik)
            daftar_pengguna[i].jumlah_pertanyaan_dibuat--;
    }

    daftar_pertanyaan.erase(daftar_pertanyaan.begin() + index_hapus);
    cout << "  Pertanyaan dihapus." << endl << endl;
}

void editJawabanAdmin() {
    if (daftar_pertanyaan.empty()) {
        cout << "  Belum ada pertanyaan." << endl << endl;
        return;
    }

    tampilHeaderTabel(28, 28, "Pertanyaan", "Jawaban Sekarang");

    for (int i = 0; i < (int)daftar_pertanyaan.size(); i++) {
        string pertanyaan = daftar_pertanyaan[i].isi_pertanyaan;
        string jawaban    = daftar_pertanyaan[i].jawaban_kerang;
        if ((int)pertanyaan.length() > 26) pertanyaan = pertanyaan.substr(0, 23) + "...";
        if ((int)jawaban.length()    > 26) jawaban    = jawaban.substr(0, 23)    + "...";
        cout << "| " << left << setw(4)  << i + 1
             << "| " << setw(28) << pertanyaan
             << "| " << setw(28) << jawaban << "|" << endl;
    }

    tampilGarisBawahTabel(28, 28);

    int nomor_pilihan;
    cout << "  Pilih nomor: "; cin >> nomor_pilihan; cin.ignore();

    if (nomor_pilihan < 1 || nomor_pilihan > (int)daftar_pertanyaan.size()) {
        cout << "  Nomor ga valid." << endl << endl;
        return;
    }

    string jawaban_baru;
    cout << "  Jawaban baru: "; getline(cin, jawaban_baru);
    daftar_pertanyaan[nomor_pilihan - 1].jawaban_kerang = jawaban_baru;
    cout << "  Okree, Jawaban ini berhasil diubah." << endl << endl;
}

void tambahJawabanKerang() {
    cout << "  Jawaban saat ini:" << endl;
    for (int i = 0; i < (int)bank_jawaban.size(); i++)
        cout << "  " << i + 1 << ". " << bank_jawaban[i] << endl;
    cout << endl;

    cout << "  (Ketik 0 untuk batal hmzz )" << endl;
    string jawaban_baru;
    cout << "  Jawaban baru: "; getline(cin, jawaban_baru);

    if (jawaban_baru == "0") {
        cout << "  Dibatalkan." << endl << endl;
    } else if (jawaban_baru.empty()) {
        cout << "  Jawaban ga boleh kosong." << endl << endl;
    } else {
        bank_jawaban.push_back(jawaban_baru);
        cout << "  Jawaban baru ditambahin." << endl << endl;
    }
}

void menuUser(int index_pengguna) {
    int pilihan_menu = 0;

    while (pilihan_menu != 5) {
        cout << "==========================================" << endl;
        cout << "          MENU KERANG AJAIB               " << endl;
        cout << "  Halo, " << daftar_pengguna[index_pengguna].profil.nama << "!" << endl;
        cout << "==========================================" << endl;
        cout << "  1. Tanya Kerang" << endl;
        cout << "  2. Lihat Histori" << endl;
        cout << "  3. Edit Pertanyaan" << endl;
        cout << "  4. Hapus Pertanyaan" << endl;
        cout << "  5. Keluar" << endl;
        cout << "  Pilihan: ";
        cin  >> pilihan_menu;
        cin.clear();
        cin.ignore(1000, '\n');
        cout << endl;

        if      (pilihan_menu == 1) tanyaKerang(index_pengguna);
        else if (pilihan_menu == 2) lihatHistori(index_pengguna);
        else if (pilihan_menu == 3) editPertanyaan(index_pengguna);
        else if (pilihan_menu == 4) hapusPertanyaanUser(index_pengguna);
        else if (pilihan_menu == 5)
            cout << "  Bye, " << daftar_pengguna[index_pengguna].profil.nama
                 << ". PULU PULU PULU! PUJA KERANG AJAIBB!" << endl << endl;
        else
            cout << "  Pilihan ga valid." << endl << endl;
    }
}

void menuAdmin(int index_pengguna) {
    int pilihan_admin = 0;

    while (pilihan_admin != 5) {
        cout << "==========================================" << endl;
        cout << "          MENU ADMIN KERANG AJAIB         " << endl;
        cout << "  Halo Admin, " << daftar_pengguna[index_pengguna].profil.nama << "!" << endl;
        cout << "==========================================" << endl;
        cout << "  1. Lihat Semua Pertanyaan" << endl;
        cout << "  2. Hapus Pertanyaan" << endl;
        cout << "  3. Edit Jawaban Kerang" << endl;
        cout << "  4. Tambah Jawaban ke Kerang" << endl;
        cout << "  5. Keluar" << endl;
        cout << "  Pilihan: ";
        cin  >> pilihan_admin;
        cin.clear();
        cin.ignore(1000, '\n');
        cout << endl;

        if      (pilihan_admin == 1) lihatSemuaPertanyaan();
        else if (pilihan_admin == 2) hapusPertanyaanAdmin();
        else if (pilihan_admin == 3) editJawabanAdmin();
        else if (pilihan_admin == 4) tambahJawabanKerang();
        else if (pilihan_admin == 5)
            cout << "  Bye, Admin " << daftar_pengguna[index_pengguna].profil.nama << "!" << endl << endl;
        else
            cout << "  Pilihan ga valid." << endl << endl;
    }
}

int main() {
    srand(time(0));
    inisialisasiBankJawaban();

    cout << "==========================================" << endl;
    cout << "             SELAMAT DATANG               " << endl;
    cout << "    Tanyakan apapun pada 'KERANG AJAIB'   " << endl;
    cout << "==========================================" << endl;
    cout << endl;

    int pilihan_awal = 0;

    while (true) {
        cout << "  1. Register" << endl;
        cout << "  2. Login" << endl;
        cout << "  3. Keluar" << endl;
        cout << "  Pilihan: ";
        cin  >> pilihan_awal;
        cin.clear();
        cin.ignore(1000, '\n');
        cout << endl;

        if (pilihan_awal == 1) {
            registerPengguna();

        } else if (pilihan_awal == 2) {
            int index_pengguna_aktif = loginPengguna(daftar_pengguna);

            if (index_pengguna_aktif == -1) {
                cout << endl;
                cout << "==========================================" << endl;
                cout << "  Akses ditolak. 3x percobaan gagal.      " << endl;
                cout << "  Program dihentikan.                     " << endl;
                cout << "==========================================" << endl;
                return 0;
            }

            cout << endl;
            cout << "  YEAY LOGIN BERHASIL! Bonjour, "
                 << daftar_pengguna[index_pengguna_aktif].profil.nama << endl;
            cout << "  Role: " << daftar_pengguna[index_pengguna_aktif].role << endl;
            cout << "==========================================" << endl << endl;

            if (daftar_pengguna[index_pengguna_aktif].role == "admin")
                menuAdmin(index_pengguna_aktif);
            else
                menuUser(index_pengguna_aktif);

        } else if (pilihan_awal == 3) {
            cout << "  Kerang menunggumu kembali. PULU PULU PULU! PUJA KERANG AJAIBB!" << endl << endl;
            break;
        } else {
            cout << "  Pilihan ga valid." << endl << endl;
        }
    }

    return 0;
}