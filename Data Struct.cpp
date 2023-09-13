#include <iostream>
#include <string>
using namespace std;

const int MAX_DATA = 10;

struct Data {
    string nama;
    int umur;
};

// Fungsi untuk menampilkan data
void tampilkanData(Data data[], int jumlahData) {
    cout << "Data saat ini:" << endl;
    for (int i = 0; i < jumlahData; i++) {
        cout << "Data ke-" << i + 1 << ":" << endl;
        cout << "Nama: " << data[i].nama << endl;
        cout << "Umur: " << data[i].umur << endl;
        cout << endl;
    }
}

void tambahData(Data data[], int &jumlahData) {
    if (jumlahData < MAX_DATA) {
        cout << "Masukkan nama: ";
        cin >> data[jumlahData].nama;
        cout << "Masukkan umur: ";
        cin >> data[jumlahData].umur;
        jumlahData++;
        cout << "Data berhasil ditambahkan!" << endl;
    } else {
        cout << "Data penuh." << endl;
    }
}

void hapusData(Data data[], int &jumlahData, int indeks) {
    if (indeks >= 0 && indeks < jumlahData) {
        for (int i = indeks; i < jumlahData - 1; i++) {
            data[i] = data[i + 1];
        }
        jumlahData--;
        cout << "Data berhasil dihapus!" << endl;
    } else {
        cout << "Indeks data tidak valid." << endl;
    }
}

void ubahData(Data data[], int jumlahData, int indeks) {
    if (indeks >= 0 && indeks < jumlahData) {
        cout << "Masukkan nama baru: ";
        cin >> data[indeks].nama;
        cout << "Masukkan umur baru: ";
        cin >> data[indeks].umur;
        cout << "Data berhasil diubah!" << endl;
    } else {
        cout << "Indeks data tidak valid." << endl;
    }
}

int main() {
    Data data[MAX_DATA];
    int jumlahData = 0;

    while (true) {
        cout << "Menu:" << endl;
        cout << "1. Tampilkan Data" << endl;
        cout << "2. Tambah Data" << endl;
        cout << "3. Hapus Data" << endl;
        cout << "4. Ubah Data" << endl;
        cout << "5. Keluar" << endl;
        cout << "Pilih menu: ";
        
        int pilihan;
        cin >> pilihan;

        switch (pilihan) {
            case 1:
                tampilkanData(data, jumlahData);
                break;
            case 2:
                tambahData(data, jumlahData);
                break;
            case 3:
                int indeksHapus;
                cout << "Masukkan indeks data yang ingin dihapus: ";
                cin >> indeksHapus;
                hapusData(data, jumlahData, indeksHapus);
                break;
            case 4:
                int indeksUbah;
                cout << "Masukkan indeks data yang ingin diubah: ";
                cin >> indeksUbah;
                ubahData(data, jumlahData, indeksUbah);
                break;
            case 5:
                return 0;
            default:
                cout << "Tidak valid. Coba lagi." << endl;
                break;
        }
    }

    return 0;
}
