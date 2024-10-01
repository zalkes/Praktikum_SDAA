#include <iostream>
#include <windows.h>
#include <iomanip>

using namespace std;

struct musik {
    string judul;
    string artist;
};

struct infomusik {
    musik lagu;
    int durasi;
    string genre;
    int tahunrilis;
    infomusik* next;
};

infomusik* head = nullptr;

void tampilkan_playlist(infomusik* head) {
    infomusik* temp = head;
    int index = 1;
    cout << "                                            PLAYLIST MUSIK" << endl;
    cout << "=========================================================================================================" << endl;
    cout << left << setw(5) << "No" << setw(30) << "Judul" << setw(20) 
    << "Artist" << setw(15) << "Durasi(s)" << setw(20) 
    << "Genre" << setw(20) << "Tahun Rilis" << endl;
    cout << setfill('-') << setw(105) << "" << endl;
    cout << setfill(' '); 
    while (temp != nullptr) {
        cout << left << setw(5) << index++ << setw(30) << temp->lagu.judul 
        << setw(23) << temp->lagu.artist << setw(12) << temp->durasi 
        << setw(24) << temp->genre << setw(10) << temp->tahunrilis << endl;
        temp = temp->next;
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

void tambahMusik_awal(infomusik*& head) { 
    infomusik* newNode = new infomusik;
    cout << "|| TAMBAHKAN MUSIK ||" << endl;
    cout << "=====================\n" << endl;
    cout << "Masukkan judul musik : ";
    cin.ignore();
    getline(cin, newNode->lagu.judul);
    check_string_kosong(newNode->lagu.judul, "judul musik");
    infomusik* temp = head;
    while (temp != nullptr) {
        if (temp->lagu.judul == newNode->lagu.judul) {
            cout << "Judul musik sudah terdapat di playlist" << endl;
            cout << "Masukkan judul musik : ";
            getline(cin, newNode->lagu.judul);
        }
        temp = temp->next;
    }
    cout << "Masukkan nama artist : ";
    getline(cin, newNode->lagu.artist);
    check_string_kosong(newNode->lagu.artist, "nama artist");
    cout << "Masukkan durasi musik (dalam detik) : ";
    cin >> newNode->durasi;
    check_angka(newNode->durasi, "durasi musik");
    cout << "Masukkan genre musik : ";
    cin.ignore();
    getline(cin, newNode->genre);
    check_string_kosong(newNode->genre, "genre musik");
    cout << "Masukkan tahun rilis musik : ";
    cin >> newNode->tahunrilis;
    check_angka(newNode->tahunrilis, "tahun rilis musik");
    newNode->next = head;
    head = newNode;
    cout << "\nBerhasil Menambahkan (" << newNode->lagu.judul << " - " << newNode->lagu.artist << ") ke Awal Playlist" << endl;
}

void tambahMusik_akhir(infomusik*& head) { 
    infomusik* newNode = new infomusik;
    cout << "|| TAMBAHKAN MUSIK ||" << endl;
    cout << "=====================\n" << endl;
    cout << "Masukkan judul musik : ";
    cin.ignore();
    getline(cin, newNode->lagu.judul);
    check_string_kosong(newNode->lagu.judul, "judul musik");
    infomusik* temp = head;
    while (temp != nullptr) {
        if (temp->lagu.judul == newNode->lagu.judul) {
            cout << "Judul musik sudah terdapat di playlist" << endl;
            cout << "Masukkan judul musik : ";
            getline(cin, newNode->lagu.judul);
        }
        temp = temp->next;
    }
    cout << "Masukkan nama artist : ";
    getline(cin, newNode->lagu.artist);
    check_string_kosong(newNode->lagu.artist, "nama artist");
    cout << "Masukkan durasi musik (dalam detik) : ";
    cin >> newNode->durasi;
    check_angka(newNode->durasi, "durasi musik");
    cout << "Masukkan genre musik : ";
    cin.ignore();
    getline(cin, newNode->genre);
    check_string_kosong(newNode->genre, "genre musik");
    cout << "Masukkan tahun rilis musik : ";
    cin >> newNode->tahunrilis;
    check_angka(newNode->tahunrilis, "tahun rilis musik");
    newNode->next = nullptr;

    if (head == nullptr) {
        head = newNode;
    } else {
        temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
    cout << "\nBerhasil Menambahkan (" << newNode->lagu.judul << " - " << newNode->lagu.artist << ") ke Akhir Playlist" << endl;
}

void ubahdata_playlist(infomusik* head) {
    system("cls");
    int urutan;
    cout << "|| UBAH DATA PLAYLIST ||" << endl;
    cout << "========================\n" << endl;
    tampilkan_playlist(head);
    cout << "\nMasukkan No. Urut Musik yang Ingin Diubah: ";
    cin >> urutan;
    infomusik* temp = head;
    for (int i = 1; i < urutan && temp != nullptr; ++i) {
        temp = temp->next;
    }
    if (temp == nullptr) {
        cout << "\nData Tidak Ditemukan" << endl;
        cin.clear();
        cin.ignore(INT_MAX, '\n');
        Sleep(1000);
    } else {
        cout << "Masukkan perubahan judul musik : ";
        cin.ignore();
        getline(cin, temp->lagu.judul);
        check_string_kosong(temp->lagu.judul, "judul musik");
        cout << "Masukkan perubahan nama artist : ";
        getline(cin, temp->lagu.artist);
        check_string_kosong(temp->lagu.artist, "nama artist");
        cout << "Masukkan perubahan durasi musik (dalam detik) : ";
        cin >> temp->durasi;
        check_angka(temp->durasi, "durasi musik");
        cout << "Masukkan perubahan genre musik : ";
        cin.ignore();
        getline(cin, temp->genre);
        check_string_kosong(temp->genre, "genre musik");
        cout << "Masukkan perubahan tahun rilis musik : ";
        cin >> temp->tahunrilis;
        check_angka(temp->tahunrilis, "tahun rilis musik");
        cout << "\nBerhasil Mengubah Data Playlist" << endl;
        Sleep(1000);
    }
}

void hapusMusik(infomusik*& head) {
    system("cls");
    int urutan;
    cout << "|| HAPUS MUSIK DARI PLAYLIST ||" << endl;
    cout << "===============================\n" << endl;
    tampilkan_playlist(head);
    cout << "\nMasukkan No. Urut Musik yang Ingin Dihapus : ";
    cin >> urutan;
    if (urutan < 1) {
        cout << "\nData Tidak Ditemukan" << endl;
        cin.clear();
        cin.ignore(INT_MAX, '\n');
        Sleep(1000);
        return;
    }
    infomusik* temp = head;
    if (urutan == 1) {
        head = head->next;
        cout << "\nBerhasil Menghapus (" << temp->lagu.judul << " - " << temp->lagu.artist << ") dari Playlist" << endl;
        delete temp;
    } else {
        for (int i = 1; i < urutan - 1 && temp != nullptr; ++i) {
            temp = temp->next;
        }
        if (temp == nullptr || temp->next == nullptr) {
            cout << "\nData Tidak Ditemukan" << endl;
            cin.clear();
            cin.ignore(INT_MAX, '\n');
            Sleep(1000);
            return;
        }
        infomusik* toDelete = temp->next;
        temp->next = toDelete->next;
        cout << "\nBerhasil Menghapus (" << toDelete->lagu.judul << " - " << toDelete->lagu.artist << ") dari Playlist" << endl;
        delete toDelete;
    }
    Sleep(1000);
}

void hapusMusik_awal(infomusik*& head) {
    system("cls");
    if (head == nullptr) {
        cout << "Playlist Anda Kosong" << endl;
        Sleep(1000);
        return;
    }
    infomusik* temp = head;
    head = head->next;
    cout << "\nBerhasil Menghapus (" << temp->lagu.judul << " - " << temp->lagu.artist << ") dari Playlist" << endl;
    delete temp;
    Sleep(1000);
}

void hapusMusik_akhir(infomusik*& head) {
    system("cls");
    if (head == nullptr) {
        cout << "Playlist Anda Kosong" << endl;
        Sleep(1000);
        return;
    }
    infomusik* temp = head;
    if (temp->next == nullptr) {
        cout << "\nBerhasil Menghapus (" << temp->lagu.judul << " - " << temp->lagu.artist << ") dari Playlist" << endl;
        delete temp;
        head = nullptr;
        Sleep(1000);
        return;
    }
    while (temp->next->next != nullptr) {
        temp = temp->next;
    }
    infomusik* toDelete = temp->next;
    temp->next = nullptr;
    cout << "\nBerhasil Menghapus (" << toDelete->lagu.judul << " - " << toDelete->lagu.artist << ") dari Playlist" << endl;
    delete toDelete;
    Sleep(1000);
}

int main(){
    int urutan;
    string pilihan;   
    infomusik* newNode = new infomusik;
    newNode->lagu.judul = "Viva La Vida"; newNode->lagu.artist = "Coldplay"; newNode->durasi = 242; newNode->genre = "Alternative Rock"; newNode->tahunrilis = 2008; newNode->next = nullptr; 
    head = newNode;
    
    newNode = new infomusik; newNode->lagu.judul = "Fix You"; newNode->lagu.artist = "Coldplay"; newNode->durasi = 294; newNode->genre = "Alternative Rock"; newNode->tahunrilis = 2005; newNode->next = head;
    head = newNode;

    newNode = new infomusik; newNode->lagu.judul = "Talking to the Moon"; newNode->lagu.artist = "Bruno Mars"; newNode->durasi = 217; newNode->genre = "Pop"; newNode->tahunrilis = 2010; newNode->next = head;
    head = newNode;

    while (true) {
        system("cls");
        cout << "              PLAYLIST MENU" << endl;
        cout << "==========================================" << endl;
        cout << "|| [1] Tampilkan Playlist Musik         ||" << endl;
        cout << "|| [2] Tambahkan Musik ke Awal Playlist ||" << endl;
        cout << "|| [3] Tambahkan Musik ke Akhir Playlist||" << endl;
        cout << "|| [4] Ubah Data Playlist               ||" << endl;
        cout << "|| [5] Hapus Musik Pada Awal Playlist   ||" << endl;
        cout << "|| [6] Hapus Musik Pada Akhir Playlist  ||" << endl;
        cout << "|| [7] Hapus Musik Berdasarkan No. Urut ||" << endl;
        cout << "|| [8] Keluar Program                   ||" << endl;
        cout << "==========================================" << endl;
        cout << "Pilih Menu : ";
        cin >> pilihan;
        system("cls");
        if (pilihan == "1") {
            if (head == nullptr){
                cout << "Playlist Anda Kosong" << endl;
                Sleep(1000);
                continue;
            }
            tampilkan_playlist(head);
            cout << "\nTekan Enter untuk kembali ke menu";
            cin.ignore();
            cin.get();
        }
        
        else if (pilihan == "2") {
            tambahMusik_awal(head);
        }

        else if (pilihan == "3") {
            tambahMusik_akhir(head);
        } 

        else if (pilihan == "4") {
            if (head == nullptr){
                cout << "Playlist Anda Kosong" << endl;
                Sleep(1000);
                continue;
            }
            ubahdata_playlist(head);
        } 

        else if (pilihan == "5") {
            hapusMusik_awal(head);
        }

        else if (pilihan == "6") {
            hapusMusik_akhir(head);
        }

        else if (pilihan == "7") {
            hapusMusik(head);
        }

        else if (pilihan == "8"){
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