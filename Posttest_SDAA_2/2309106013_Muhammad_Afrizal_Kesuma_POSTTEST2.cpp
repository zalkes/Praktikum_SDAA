#include <iostream>
#include <windows.h>
#include <iomanip>

using namespace std;

struct musik {
    string judul;
    string artist;
};

struct infomusik {
    struct musik lagu;
    int durasi;
    string genre;
    int tahunrilis;
};

struct infomusik playlist[50] = {
    {{"Viva La Vida", "Coldplay"}, 242, "Alternative Rock", 2008},
    {{"Fix You", "Coldplay"}, 294, "Alternative Rock", 2005},
    {{"Adventure of a Lifetime", "Coldplay"}, 259, "Alternative Rock", 2015},
    {{"Talking to the Moon", "Bruno Mars"}, 217, "Pop", 2010},
    {{"Perfect", "Ed Sheeran"}, 263, "Pop", 2017}
};

void tampilkan_playlist(struct infomusik *playlist, int &banyak_data, int index = 0) {
    cout << "                                            PLAYLIST MUSIK" << endl;
    cout << "=========================================================================================================" << endl;
    cout << left << setw(5) << "No" << setw(30) << "Judul" << setw(20) 
    << "Artist" << setw(15) << "Durasi(s)" << setw(20) 
    << "Genre" << setw(20) << "Tahun Rilis" << endl;
    cout << setfill('-') << setw(105) << "" << endl;
    cout << setfill(' '); 
    for (int i = 0; i < banyak_data; ++i) {
        cout << left << setw(5) << i+1 << setw(30) << playlist[i].lagu.judul 
        << setw(23) << playlist[i].lagu.artist << setw(12) << playlist[i].durasi 
        << setw(24) << playlist[i].genre << setw(10) << playlist[i].tahunrilis << endl;
    }
    cout << "=========================================================================================================" << endl;
}

void check_string_kosong(string &inputan, string jenis) {
    while (inputan.empty() || inputan == " ") {
        cout << "Inputan tidak boleh kosong" << endl;
        cout << "Masukkan " << jenis << ": ";
        getline(cin, inputan);
    }
}

void check_angka(int &inputan, string jenis) {
    while (cin.fail() || inputan < 0) {
        cout << "Inputan harus berupa angka" << endl;
        cout << "Masukkan " << jenis << ": ";
        cin.clear();
        cin.ignore(INT_MAX, '\n');
        cin >> inputan;
    }
}

string tambah_musik(struct infomusik *playlist, int &banyak_data) { 
    cout << "|| TAMBAHKAN MUSIK ||" << endl;
    cout << "=====================\n" << endl;
    cout << "Masukkan judul musik : ";
    cin.ignore();
    getline(cin, playlist[banyak_data].lagu.judul);
    check_string_kosong(playlist[banyak_data].lagu.judul, "judul musik");
    for (int i = 0; i < banyak_data; i++) {
        while (playlist[i].lagu.judul == playlist[banyak_data].lagu.judul) {
            cout << "Judul musik sudah terdapat di playlist" << endl;
            cout << "Masukkan judul musik : ";
            getline(cin, playlist[banyak_data].lagu.judul);
        }
    }
    cout << "Masukkan nama artist : ";
    getline(cin, playlist[banyak_data].lagu.artist);
    check_string_kosong(playlist[banyak_data].lagu.artist, "nama artist");
    cout << "Masukkan durasi musik (dalam detik) : ";
    cin >> playlist[banyak_data].durasi;
    check_angka(playlist[banyak_data].durasi, "durasi musik");
    cout << "Masukkan genre musik : ";
    cin.ignore();
    getline(cin, playlist[banyak_data].genre);
    check_string_kosong(playlist[banyak_data].genre, "genre musik");
    cout << "Masukkan tahun rilis musik : ";
    cin >> playlist[banyak_data].tahunrilis;
    check_angka(playlist[banyak_data].tahunrilis, "tahun rilis musik");
    return playlist[banyak_data].lagu.judul, playlist[banyak_data].lagu.artist;
}

void ubahdata_playlist(struct infomusik *playlist, int banyak_data) {
    system("cls");
    int urutan;
    cout << "|| UBAH DATA PLAYLIST ||" << endl;
    cout << "========================\n" << endl;
    tampilkan_playlist(playlist, banyak_data);
    cout << "\nMasukkan No. Urut Musik yang Ingin Diubah: ";
    cin >> urutan;
    if (urutan > banyak_data || urutan < 1){
        cout << "\nData Tidak Ditemukan" << endl;
        cin.clear();
        cin.ignore(INT_MAX, '\n');
        Sleep(1000);
    }
    else {
        cout << "Masukkan perubahan judul musik : ";
        cin.ignore();
        getline(cin, playlist[urutan-1].lagu.judul);
        check_string_kosong(playlist[urutan-1].lagu.judul, "judul musik");
        cout << "Masukkan perubahan nama artist : ";
        getline(cin, playlist[urutan-1].lagu.artist);
        check_string_kosong(playlist[urutan-1].lagu.artist, "nama artist");
        cout << "Masukkan perubahan durasi musik (dalam detik) : ";
        cin >> playlist[urutan-1].durasi;
        check_angka(playlist[urutan-1].durasi, "durasi musik");
        cout << "Masukkan perubahan genre musik : ";
        cin.ignore();
        getline(cin, playlist[urutan-1].genre);
        check_string_kosong(playlist[urutan-1].genre, "genre musik");
        cout << "Masukkan perubahan tahun rilis musik : ";
        cin >> playlist[urutan-1].tahunrilis;
        check_angka(playlist[urutan-1].tahunrilis, "tahun rilis musik");
        cout << "\nBerhasil Mengubah Data Playlist" << endl;
        Sleep(1000);
    }
}

void hapus_musik(struct infomusik *playlist, int &banyak_data) {
    system("cls");
    int urutan;
    cout << "|| HAPUS MUSIK DARI PLAYLIST ||" << endl;
    cout << "===============================\n" << endl;
    tampilkan_playlist(playlist, banyak_data);
    cout << "\nMasukkan No. Urut Musik yang Ingin Dihapus : ";
    cin >> urutan;
    if (urutan > banyak_data || urutan < 1){
        cout << "\nData Tidak Ditemukan" << endl;
        cin.clear();
        cin.ignore(INT_MAX, '\n');
        Sleep(1000);
    }
    else {
        cout << "\nBerhasil Menghapus (" << playlist[urutan-1].lagu.judul << " - " << playlist[urutan-1].lagu.artist << ") dari Playlist" << endl;
        for (int i = urutan-1; i < banyak_data-1; i++) {
            playlist[i] = playlist[i+1];
        }
        banyak_data--;
        Sleep(1000);
    }
}

int main(){
    int banyak_data = 5;
    int urutan;
    string pilihan;   
    while (true) {
        system("cls");
        cout << "            PLAYLIST MENU" << endl;
        cout << "=====================================" << endl;
        cout << "|| [1] Tampilkan Playlist Musik    ||" << endl;
        cout << "|| [2] Tambahkan Musik ke Playlist ||" << endl;
        cout << "|| [3] Ubah Data Playlist          ||" << endl;
        cout << "|| [4] Hapus Musik dari Playlist   ||" << endl;
        cout << "|| [5] Keluar Program              ||" << endl;
        cout << "=====================================" << endl;
        cout << "Pilih Menu : ";
        cin >> pilihan;
        system("cls");
        if (pilihan == "1") {
            if (banyak_data == 0){
                cout << "Playlist Anda Kosong" << endl;
                Sleep(1000);
                continue;
            }
            tampilkan_playlist(playlist, banyak_data);
            cout << "\nTekan Enter untuk kembali ke menu";
            cin.ignore();
            cin.get();
        }
        
        else if (pilihan == "2") {
            tambah_musik(playlist, banyak_data);
            cout << "\nBerhasil Menambahkan (" << playlist[banyak_data].lagu.judul << " - " << playlist[banyak_data].lagu.artist << ") ke Playlist" << endl;
            banyak_data++;
            Sleep(1000);
        } 

        else if (pilihan == "3") {
            if (banyak_data == 0){
                cout << "Playlist Anda Kosong" << endl;
                Sleep(1000);
                continue;
            }
            ubahdata_playlist(playlist, banyak_data);
        } 

        else if (pilihan == "4") {
            if (banyak_data == 0){
                cout << "Playlist Anda Kosong" << endl;
                Sleep(1000);
                continue;
            }
            hapus_musik(playlist, banyak_data);
        }

        else if (pilihan == "5"){
            break;
        }

        else {
            cout << "Pilihan Tidak Valid" << endl;
            Sleep(1000);
        }
        
    }
    system("cls");
    cout << "Anda Telah Keluar dari Program" << endl;
    return 0;
}