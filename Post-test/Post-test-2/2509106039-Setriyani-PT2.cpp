#include <iostream>
#include <string>
#include <iomanip>
#include <cstdlib>
#include <ctime>
using namespace std;

#define MAX_USER       20
#define MAX_PERTANYAAN 100
#define MAX_JAWABAN    20

struct ProfilPengguna {
    string nama;
    string nim;
};

struct Pengguna {
    ProfilPengguna profil; 
    string role;           
    int    jumlah_pertanyaan_dibuat;
};

struct Pertanyaan {
    string isi_pertanyaan;
    string jawaban_kerang;
    string nama_pemilik;
};

Pengguna   daftar_pengguna[MAX_USER];
int        jumlah_pengguna = 0;

Pertanyaan daftar_pertanyaan[MAX_PERTANYAAN];
int        jumlah_pertanyaan = 0;

string bank_jawaban[MAX_JAWABAN] = {
    "Mungkin suatu hari nanti...",
    "Tidak!",
    "Coba lagi nanti.",
    "Tentu saja!",
    "Kerang tidak menjawab pertanyaan itu.",
    "Sepertinya iya.",
    "Sepertinya tidak.",
    "Sudah jelas jawabannya!"
};
int jumlah_jawaban = 8;

int main() {
    srand(time(0));

    int    pilihan_awal;
    int    pilihan_menu;
    int    pilihan_admin;
    int    percobaan_login;
    bool   login_berhasil;
    int    index_pengguna_aktif;
    string nama_input;
    string nim_input;
    string role_input;

    cout << "==========================================" << endl;
    cout << "             SELAMAT DATANG               " << endl;
    cout << "    Tanyakan apapun pada 'KERANG AJAIB'   " << endl;
    cout << "==========================================" << endl;
    cout << endl;

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

            if (jumlah_pengguna >= MAX_USER) {
                cout << "  Kapasitas penuh!" << endl << endl;
            } else {
                cout << "==========================================" << endl;
                cout << "               REGISTER                   " << endl;
                cout << "==========================================" << endl;
                cout << "  Nama             : "; getline(cin, nama_input);
                cout << "  Password (NIM)   : "; getline(cin, nim_input);
                cout << "  Role (user/admin): "; getline(cin, role_input);

                string role_lower = role_input;
                for (int i = 0; i < (int)role_lower.length(); i++)
                    role_lower[i] = tolower(role_lower[i]);

                if (role_lower != "user" && role_lower != "admin") {
                    cout << "  Role ga valid! pilih dua aja jangan maruk. 'user' atau 'admin'." << endl << endl;
                } else {
                    bool nama_sudah_ada = false;
                    for (int i = 0; i < jumlah_pengguna; i++) {
                        if (daftar_pengguna[i].profil.nama == nama_input)
                            nama_sudah_ada = true;
                    }

                    if (nama_sudah_ada) {
                        cout << "  Nama udah ada, ganti yang lain " << endl << endl;
                    } else {
                        daftar_pengguna[jumlah_pengguna].profil.nama              = nama_input;
                        daftar_pengguna[jumlah_pengguna].profil.nim               = nim_input;
                        daftar_pengguna[jumlah_pengguna].role                     = role_lower;
                        daftar_pengguna[jumlah_pengguna].jumlah_pertanyaan_dibuat = 0;
                        jumlah_pengguna++;
                        cout << "  Register berhasil sebagai " << role_lower << ". Silakan login." << endl << endl;
                    }
                }
            }

        } else if (pilihan_awal == 2) {

            percobaan_login      = 0;
            login_berhasil       = false;
            index_pengguna_aktif = -1;

            cout << "==========================================" << endl;
            cout << "                 LOGIN                    " << endl;
            cout << "==========================================" << endl;

            while (percobaan_login < 3) {
                percobaan_login++;
                cout << "  Percobaan ke-" << percobaan_login << " dari 3" << endl;
                cout << "  Nama          : "; getline(cin, nama_input);
                cout << " Password (NIM) : "; getline(cin, nim_input);

                string nama_input_lower = nama_input;
                for (int i = 0; i < (int)nama_input_lower.length(); i++)
                    nama_input_lower[i] = tolower(nama_input_lower[i]);

                for (int i = 0; i < jumlah_pengguna; i++) {

                    string nama_tersimpan_lower = daftar_pengguna[i].profil.nama;
                    for (int j = 0; j < (int)nama_tersimpan_lower.length(); j++)
                        nama_tersimpan_lower[j] = tolower(nama_tersimpan_lower[j]);

                    if (nama_tersimpan_lower == nama_input_lower &&
                        daftar_pengguna[i].profil.nim == nim_input) {
                        login_berhasil       = true;
                        index_pengguna_aktif = i;
                    }
                }

                if (login_berhasil) break;

                if (percobaan_login < 3)
                    cout << "  Nama atau NIM salah hmzz.. Sisa: " << (3 - percobaan_login) << "x" << endl << endl;
            }

            if (!login_berhasil) {
                cout << endl;
                cout << "==========================================" << endl;
                cout << "  Akses ditolak Well. 3x percobaan gagal. " << endl;
                cout << "   Program dihentikan.                    " << endl;
                cout << "==========================================" << endl;
                return 0;
            }

            cout << endl;
            cout << "  LOGIN BERHASIL! Halo, " << daftar_pengguna[index_pengguna_aktif].profil.nama << endl;
            cout << "  Role: " << daftar_pengguna[index_pengguna_aktif].role << endl;
            cout << "==========================================" << endl << endl;

            if (daftar_pengguna[index_pengguna_aktif].role == "admin") {

                pilihan_admin = 0;
                while (pilihan_admin != 5) {

                    cout << "==========================================" << endl;
                    cout << "          MENU ADMIN KERANG AJAIB         " << endl;
                    cout << "  Halo Admin, " << daftar_pengguna[index_pengguna_aktif].profil.nama << "!" << endl;
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

                    if (pilihan_admin == 1) {

                        if (jumlah_pertanyaan == 0) {
                            cout << "  Belum ada pertanyaan." << endl << endl;
                        } else {
                            cout << "+-" << setfill('-') << setw(4) << "-" << "+-" << setw(15) << "-" << "+-" << setw(28) << "-" << "+-" << setw(28) << "-" << "+" << endl;
                            cout << setfill(' ');
                            cout << "| " << left << setw(4) << "No" << "| " << setw(15) << "Pemilik" << "| " << setw(28) << "Pertanyaan" << "| " << setw(28) << "Jawaban" << "|" << endl;
                            cout << "+-" << setfill('-') << setw(4) << "-" << "+-" << setw(15) << "-" << "+-" << setw(28) << "-" << "+-" << setw(28) << "-" << "+" << endl;
                            cout << setfill(' ');
                            for (int i = 0; i < jumlah_pertanyaan; i++) {
                                string p = daftar_pertanyaan[i].isi_pertanyaan;
                                string j = daftar_pertanyaan[i].jawaban_kerang;
                                string o = daftar_pertanyaan[i].nama_pemilik;
                                if ((int)p.length() > 26) p = p.substr(0, 23) + "...";
                                if ((int)j.length() > 26) j = j.substr(0, 23) + "...";
                                if ((int)o.length() > 13) o = o.substr(0, 10) + "...";
                                cout << "| " << left << setw(4) << i+1 << "| " << setw(15) << o << "| " << setw(28) << p << "| " << setw(28) << j << "|" << endl;
                            }
                            cout << "+-" << setfill('-') << setw(4) << "-" << "+-" << setw(15) << "-" << "+-" << setw(28) << "-" << "+-" << setw(28) << "-" << "+" << endl;
                            cout << setfill(' ') << endl;
                        }

                    } else if (pilihan_admin == 2) {

                        if (jumlah_pertanyaan == 0) {
                            cout << "  Belum ada pertanyaan." << endl << endl;
                        } else {
                            cout << "+-" << setfill('-') << setw(4) << "-" << "+-" << setw(15) << "-" << "+-" << setw(38) << "-" << "+" << endl;
                            cout << setfill(' ');
                            cout << "| " << left << setw(4) << "No" << "| " << setw(15) << "Pemilik" << "| " << setw(38) << "Pertanyaan" << "|" << endl;
                            cout << "+-" << setfill('-') << setw(4) << "-" << "+-" << setw(15) << "-" << "+-" << setw(38) << "-" << "+" << endl;
                            cout << setfill(' ');
                            for (int i = 0; i < jumlah_pertanyaan; i++) {
                                string p = daftar_pertanyaan[i].isi_pertanyaan;
                                string o = daftar_pertanyaan[i].nama_pemilik;
                                if ((int)p.length() > 36) p = p.substr(0, 33) + "...";
                                if ((int)o.length() > 13) o = o.substr(0, 10) + "...";
                                cout << "| " << left << setw(4) << i+1 << "| " << setw(15) << o << "| " << setw(38) << p << "|" << endl;
                            }
                            cout << "+-" << setfill('-') << setw(4) << "-" << "+-" << setw(15) << "-" << "+-" << setw(38) << "-" << "+" << endl;
                            cout << setfill(' ');

                            int nomor_hapus;
                            cout << "  Pilih nomor: "; cin >> nomor_hapus; cin.ignore();
                            if (nomor_hapus < 1 || nomor_hapus > jumlah_pertanyaan) {
                                cout << " Nomor ga valid " << endl << endl;
                            } else {
                                int idx = nomor_hapus - 1;
                                for (int i = 0; i < jumlah_pengguna; i++)
                                    if (daftar_pengguna[i].profil.nama == daftar_pertanyaan[idx].nama_pemilik)
                                        daftar_pengguna[i].jumlah_pertanyaan_dibuat--;
                                for (int i = idx; i < jumlah_pertanyaan - 1; i++)
                                    daftar_pertanyaan[i] = daftar_pertanyaan[i + 1];
                                jumlah_pertanyaan--;
                                cout << "  Pertanyaan dihapus. " << endl << endl;
                            }
                        }

                    } else if (pilihan_admin == 3) {

                        if (jumlah_pertanyaan == 0) {
                            cout << "  Belum ada pertanyaan." << endl << endl;
                        } else {
                            cout << "+-" << setfill('-') << setw(4) << "-" << "+-" << setw(28) << "-" << "+-" << setw(28) << "-" << "+" << endl;
                            cout << setfill(' ');
                            cout << "| " << left << setw(4) << "No" << "| " << setw(28) << "Pertanyaan" << "| " << setw(28) << "Jawaban Sekarang" << "|" << endl;
                            cout << "+-" << setfill('-') << setw(4) << "-" << "+-" << setw(28) << "-" << "+-" << setw(28) << "-" << "+" << endl;
                            cout << setfill(' ');
                            for (int i = 0; i < jumlah_pertanyaan; i++) {
                                string p = daftar_pertanyaan[i].isi_pertanyaan;
                                string j = daftar_pertanyaan[i].jawaban_kerang;
                                if ((int)p.length() > 26) p = p.substr(0, 23) + "...";
                                if ((int)j.length() > 26) j = j.substr(0, 23) + "...";
                                cout << "| " << left << setw(4) << i+1 << "| " << setw(28) << p << "| " << setw(28) << j << "|" << endl;
                            }
                            cout << "+-" << setfill('-') << setw(4) << "-" << "+-" << setw(28) << "-" << "+-" << setw(28) << "-" << "+" << endl;
                            cout << setfill(' ');

                            int nomor_edit;
                            cout << "  Pilih nomor: "; cin >> nomor_edit; cin.ignore();
                            if (nomor_edit < 1 || nomor_edit > jumlah_pertanyaan) {
                                cout << " Nomor ga valid " << endl << endl;
                            } else {
                                string jawaban_baru;
                                cout << "  Jawaban baru: "; getline(cin, jawaban_baru);
                                daftar_pertanyaan[nomor_edit - 1].jawaban_kerang = jawaban_baru;
                                cout << "  Jawaban berhasil diubah " << endl << endl;
                            }
                        }

                    } else if (pilihan_admin == 4) {

                        if (jumlah_jawaban >= MAX_JAWABAN) {
                            cout << " Jawaban penuh " << endl << endl;
                        } else {
                            cout << "  Jawaban saat ini:" << endl;
                            for (int i = 0; i < jumlah_jawaban; i++)
                                cout << "  " << i+1 << ". " << bank_jawaban[i] << endl;
                            cout << endl;
                            cout << "  (Ketik 0 untuk batal)" << endl;
                            string jawaban_baru;
                            cout << "  Jawaban baru: "; getline(cin, jawaban_baru);

                            if (jawaban_baru == "0") {
                                cout << "  Dibatalkan." << endl << endl;
                            } else if (jawaban_baru.empty()) {
                                cout << "  Jawaban ga boleh kosong!" << endl << endl;
                            } else {
                                bank_jawaban[jumlah_jawaban++] = jawaban_baru;
                                cout << " Jawaban ditambahkan " << endl << endl;
                            }
                        }

                    } else if (pilihan_admin == 5) {
                        cout << "  Bye, Admin, " << daftar_pengguna[index_pengguna_aktif].profil.nama << "!" << endl << endl;
                    } else {
                        cout << " Pilihan ga valid " << endl << endl;
                    }
                }

            } else {

                pilihan_menu = 0;
                while (pilihan_menu != 5) {

                    cout << "==========================================" << endl;
                    cout << "          MENU KERANG AJAIB               " << endl;
                    cout << "  Halo, " << daftar_pengguna[index_pengguna_aktif].profil.nama << "!" << endl;
                    cout << "==========================================" << endl;
                    cout << "  1. Tanya Kerang     " << endl;
                    cout << "  2. Lihat Histori    " << endl;
                    cout << "  3. Edit Pertanyaan  " << endl;
                    cout << "  4. Hapus Pertanyaan " << endl;
                    cout << "  5. Keluar" << endl;
                    cout << "  Pilihan: ";
                    cin  >> pilihan_menu;
                    cin.clear();
                    cin.ignore(1000, '\n');
                    cout << endl;

                    if (pilihan_menu == 1) {

                        if (jumlah_pertanyaan >= MAX_PERTANYAAN) {
                            cout << "  Histori penuh. Hapus dulu beberapa." << endl << endl;
                        } else {
                            string pertanyaan_baru;
                            cout << "  Tanyakan apapun pada kerang ajaib..." << endl;
                            cout << "  Pertanyaanmu: "; getline(cin, pertanyaan_baru);
                            int idx_acak = rand() % jumlah_jawaban;
                            daftar_pertanyaan[jumlah_pertanyaan].isi_pertanyaan = pertanyaan_baru;
                            daftar_pertanyaan[jumlah_pertanyaan].jawaban_kerang = bank_jawaban[idx_acak];
                            daftar_pertanyaan[jumlah_pertanyaan].nama_pemilik   = daftar_pengguna[index_pengguna_aktif].profil.nama;
                            jumlah_pertanyaan++;
                            daftar_pengguna[index_pengguna_aktif].jumlah_pertanyaan_dibuat++;
                            cout << endl;
                            cout << "  Kerang Ajaib berkata.. " << endl;
                            cout << "  >> \"" << bank_jawaban[idx_acak] << "\"" << endl << endl;
                        }

                    } else if (pilihan_menu == 2) {

                        int jumlah_milik = 0;
                        for (int i = 0; i < jumlah_pertanyaan; i++)
                            if (daftar_pertanyaan[i].nama_pemilik == daftar_pengguna[index_pengguna_aktif].profil.nama)
                                jumlah_milik++;

                        cout << "  Histori milik " << daftar_pengguna[index_pengguna_aktif].profil.nama << " (" << jumlah_milik << " pertanyaan)" << endl;

                        if (jumlah_milik == 0) {
                            cout << "  Belum ada pertanyaan. Tanya kerang dulu kocak. " << endl << endl;
                        } else {
                            cout << "+-" << setfill('-') << setw(4) << "-" << "+-" << setw(30) << "-" << "+-" << setw(30) << "-" << "+" << endl;
                            cout << setfill(' ');
                            cout << "| " << left << setw(4) << "No" << "| " << setw(30) << "Pertanyaan" << "| " << setw(30) << "Jawaban Kerang" << "|" << endl;
                            cout << "+-" << setfill('-') << setw(4) << "-" << "+-" << setw(30) << "-" << "+-" << setw(30) << "-" << "+" << endl;
                            cout << setfill(' ');
                            int nomor = 0;
                            for (int i = 0; i < jumlah_pertanyaan; i++) {
                                if (daftar_pertanyaan[i].nama_pemilik == daftar_pengguna[index_pengguna_aktif].profil.nama) {
                                    nomor++;
                                    string p = daftar_pertanyaan[i].isi_pertanyaan;
                                    string j = daftar_pertanyaan[i].jawaban_kerang;
                                    if ((int)p.length() > 28) p = p.substr(0, 25) + "...";
                                    if ((int)j.length() > 28) j = j.substr(0, 25) + "...";
                                    cout << "| " << left << setw(4) << nomor << "| " << setw(30) << p << "| " << setw(30) << j << "|" << endl;
                                }
                            }
                            cout << "+-" << setfill('-') << setw(4) << "-" << "+-" << setw(30) << "-" << "+-" << setw(30) << "-" << "+" << endl;
                            cout << setfill(' ') << endl;
                        }

                    } else if (pilihan_menu == 3) {

                        int jumlah_milik = 0;
                        int idx_milik[MAX_PERTANYAAN];
                        cout << "+-" << setfill('-') << setw(4) << "-" << "+-" << setw(45) << "-" << "+" << endl;
                        cout << setfill(' ');
                        cout << "| " << left << setw(4) << "No" << "| " << setw(45) << "Pertanyaan" << "|" << endl;
                        cout << "+-" << setfill('-') << setw(4) << "-" << "+-" << setw(45) << "-" << "+" << endl;
                        cout << setfill(' ');
                        for (int i = 0; i < jumlah_pertanyaan; i++) {
                            if (daftar_pertanyaan[i].nama_pemilik == daftar_pengguna[index_pengguna_aktif].profil.nama) {
                                idx_milik[jumlah_milik] = i;
                                jumlah_milik++;
                                string p = daftar_pertanyaan[i].isi_pertanyaan;
                                if ((int)p.length() > 43) p = p.substr(0, 40) + "...";
                                cout << "| " << left << setw(4) << jumlah_milik << "| " << setw(45) << p << "|" << endl;
                            }
                        }
                        cout << "+-" << setfill('-') << setw(4) << "-" << "+-" << setw(45) << "-" << "+" << endl;
                        cout << setfill(' ');

                        if (jumlah_milik == 0) {
                            cout << "  Belum ada pertanyaan." << endl << endl;
                        } else {
                            int nomor_edit;
                            cout << "  Pilih nomor: "; cin >> nomor_edit; cin.ignore();
                            if (nomor_edit < 1 || nomor_edit > jumlah_milik) {
                                cout << "  Nomor ga valid " << endl << endl;
                            } else {
                                string pertanyaan_baru;
                                cout << "  Pertanyaan baru: "; getline(cin, pertanyaan_baru);
                                int idx_acak = rand() % jumlah_jawaban;
                                daftar_pertanyaan[idx_milik[nomor_edit-1]].isi_pertanyaan = pertanyaan_baru;
                                daftar_pertanyaan[idx_milik[nomor_edit-1]].jawaban_kerang = bank_jawaban[idx_acak];
                                cout << "  Pertanyaan diperbarui " << endl;
                                cout << "  >> Kerang: \"" << bank_jawaban[idx_acak] << "\"" << endl << endl;
                            }
                        }

                    } else if (pilihan_menu == 4) {

                        int jumlah_milik = 0;
                        int idx_milik[MAX_PERTANYAAN];
                        cout << "+-" << setfill('-') << setw(4) << "-" << "+-" << setw(45) << "-" << "+" << endl;
                        cout << setfill(' ');
                        cout << "| " << left << setw(4) << "No" << "| " << setw(45) << "Pertanyaan" << "|" << endl;
                        cout << "+-" << setfill('-') << setw(4) << "-" << "+-" << setw(45) << "-" << "+" << endl;
                        cout << setfill(' ');
                        for (int i = 0; i < jumlah_pertanyaan; i++) {
                            if (daftar_pertanyaan[i].nama_pemilik == daftar_pengguna[index_pengguna_aktif].profil.nama) {
                                idx_milik[jumlah_milik] = i;
                                jumlah_milik++;
                                string p = daftar_pertanyaan[i].isi_pertanyaan;
                                if ((int)p.length() > 43) p = p.substr(0, 40) + "...";
                                cout << "| " << left << setw(4) << jumlah_milik << "| " << setw(45) << p << "|" << endl;
                            }
                        }
                        cout << "+-" << setfill('-') << setw(4) << "-" << "+-" << setw(45) << "-" << "+" << endl;
                        cout << setfill(' ');

                        if (jumlah_milik == 0) {
                            cout << "  Belum ada pertanyaan." << endl << endl;
                        } else {
                            int nomor_hapus;
                            cout << "  Pilih nomor: "; cin >> nomor_hapus; cin.ignore();
                            if (nomor_hapus < 1 || nomor_hapus > jumlah_milik) {
                                cout << "  Nomor ga valid " << endl << endl;
                            } else {
                                int idx_asli = idx_milik[nomor_hapus - 1];
                                for (int i = idx_asli; i < jumlah_pertanyaan - 1; i++)
                                    daftar_pertanyaan[i] = daftar_pertanyaan[i+1];
                                jumlah_pertanyaan--;
                                daftar_pengguna[index_pengguna_aktif].jumlah_pertanyaan_dibuat--;
                                cout << " Pertanyaan dihapus " << endl << endl;
                            }
                        }

                    } else if (pilihan_menu == 5) {
                        cout << "  Bye, " << daftar_pengguna[index_pengguna_aktif].profil.nama << ". PULU PULU PULU! PUJA KERANG AJAIBB!" << endl << endl;
                    } else {
                        cout << "  Pilihan ga valid " << endl << endl;
                    }
                }
            }

        } else if (pilihan_awal == 3) {
            cout << "  Kerang menunggumu kembali. PULU PULU PULU! PUJA KERANG AJAIBB! " << endl << endl;
            break;
        } else {
            cout << " Pilihan ga valid " << endl << endl;
        }
    }

    return 0;
}