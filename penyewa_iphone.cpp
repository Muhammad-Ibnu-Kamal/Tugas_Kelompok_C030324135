#include <iostream>
#include <conio.h>
#include <cstdlib>
#include <vector>

using namespace std;

vector<int> hargaSewa;  // Menyimpan harga sewa iPhone per pesanan

void tukar(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}

void bubble_sort(vector<int> &data) {
    int n = data.size();
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (data[j] > data[j + 1]) {
                tukar(data[j], data[j + 1]);
            }
        }
    }
}

void tampilMenu() {
    system("cls");
    cout << "=== Aplikasi Penyewaan iPhone ===\n";
    cout << "1. Input Harga Sewa iPhone\n";
    cout << "2. Tampilkan Harga Sewa\n";
    cout << "3. Urutkan Harga (Bubble Sort)\n";
    cout << "4. Motivasi Hari Ini\n";
    cout << "5. Keluar\n";
    cout << "Pilihan Anda: ";
}

void motivasiHariIni() {
    system("cls");
    cout << "Ingat, menyewa iPhone adalah awal menuju gaya hidup stylish!\n";
    getch();
}

void inputHargaSewa() {
    system("cls");
    int jumlah;
    cout << "Masukkan jumlah iPhone yang ingin disewa: ";
    cin >> jumlah;

    hargaSewa.clear();
    cout << "Masukkan harga sewa (per unit):\n";
    for (int i = 0; i < jumlah; ++i) {
        int harga;
        cout << "iPhone ke-" << (i + 1) << ": Rp ";
        cin >> harga;
        hargaSewa.push_back(harga);
    }

    cout << "\nData harga sewa berhasil disimpan!";
    getch();
}

void tampilkanHargaSewa() {
    system("cls");
    if (hargaSewa.empty()) {
        cout << "Belum ada data harga sewa yang dimasukkan.\n";
    } else {
        cout << "Harga sewa iPhone yang dimasukkan:\n";
        for (int i = 0; i < hargaSewa.size(); ++i) {
            cout << "iPhone ke-" << (i + 1) << ": Rp " << hargaSewa[i] << "\n";
        }
    }
    getch();
}

void urutkanHargaSewa() {
    system("cls");
    if (hargaSewa.empty()) {
        cout << "Tidak ada data untuk diurutkan.\n";
    } else {
        cout << "Harga sebelum diurutkan:\n";
        for (int h : hargaSewa) cout << "Rp " << h << " ";
        cout << "\n\n";

        bubble_sort(hargaSewa);

        cout << "Harga setelah diurutkan (terendah ke tertinggi):\n";
        for (int h : hargaSewa) cout << "Rp " << h << " ";
        cout << "\n\nProses pengurutan selesai!";
    }
    getch();
}

int main() {
    char pilihan;
    do {
        tampilMenu();
        pilihan = getch();
        switch (pilihan) {
            case '1':
                inputHargaSewa();
                break;
            case '2':
                tampilkanHargaSewa();
                break;
            case '3':
                urutkanHargaSewa();
                break;
            case '4':
                motivasiHariIni();
                break;
            case '5':
                system("cls");
                cout << "Terima kasih telah menggunakan aplikasi penyewaan iPhone!\n";
                break;
            default:
                system("cls");
                cout << "Pilihan tidak valid. Silakan coba lagi.";
                getch();
                break;
        }
    } while (pilihan != '5');

    return 0;
}