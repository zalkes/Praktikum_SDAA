#include <iostream>
#include <windows.h>
#include <iomanip>
#include <limits>

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

struct Node{
    infomusik data;
    Node* next;
};

Node* createNode();
void tampilkan_stack(Node* top);
void push(Node** top);
void pop(Node** top);
void tampilkan_queue(Node *front);
void enqueue(Node** front, Node** rear);
void dequeue(Node** front);
string mode;

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
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cin >> inputan;
    }
}

void tampilkan_stack(Node* top) {
    if (top == nullptr) {
        cout << "Playlist Anda Kosong" << endl;
        return;
    }
    Node* temp = top;
    int index = 1;
    cout << "                                            PLAYLIST MUSIK" << endl;
    cout << "=========================================================================================================" << endl;
    cout << left << setw(5) << "No" << setw(30) << "Judul" << setw(20) 
    << "Artist" << setw(15) << "Durasi(s)" << setw(20) 
    << "Genre" << setw(20) << "Tahun Rilis" << endl;
    cout << setfill('-') << setw(105) << "" << endl;
    cout << setfill(' '); 
    while (temp != nullptr) {
        cout << left << setw(5) << index++ << setw(30) << temp->data.lagu.judul 
        << setw(23) << temp->data.lagu.artist << setw(12) << temp->data.durasi 
        << setw(24) << temp->data.genre << setw(10) << temp->data.tahunrilis << endl;
        temp = temp->next;
    }
    cout << "=========================================================================================================" << endl;
}

void push(Node** top) {
    Node* newNode = createNode();
    newNode->next = *top;
    *top = newNode;
    cout << "\nBerhasil Menambahkan (" << newNode->data.lagu.judul << " - " << newNode->data.lagu.artist << ") ke Playlist" << endl;
    Sleep(1000);
}

void pop(Node** top) {
    if (*top == nullptr) {
        cout << "Playlist Anda Kosong" << endl;
        Sleep(1000);
        return;
    }
    Node* temp = *top;
    *top = (*top)->next;
    cout << "\nBerhasil Menghapus (" << temp->data.lagu.judul << " - " << temp->data.lagu.artist << ") dari Playlist" << endl;
    delete temp;
    Sleep(1000);
}

void tampilkan_queue(Node *front) {
    if (front == nullptr) {
        cout << "Playlist Anda Kosong" << endl;
        return;
    }
    Node* temp = front;
    int index = 1;
    cout << "                                            PLAYLIST MUSIK" << endl;
    cout << "=========================================================================================================" << endl;
    cout << left << setw(5) << "No" << setw(30) << "Judul" << setw(20) 
    << "Artist" << setw(15) << "Durasi(s)" << setw(20) 
    << "Genre" << setw(20) << "Tahun Rilis" << endl;
    cout << setfill('-') << setw(105) << "" << endl;
    cout << setfill(' '); 
    while (temp != nullptr) {
        cout << left << setw(5) << index++ << setw(30) << temp->data.lagu.judul 
        << setw(23) << temp->data.lagu.artist << setw(12) << temp->data.durasi 
        << setw(24) << temp->data.genre << setw(10) << temp->data.tahunrilis << endl;
        temp = temp->next;
    }
    cout << "=========================================================================================================" << endl;
}

void enqueue(Node** front, Node** rear) {
    Node* newNode = createNode();
    if (*front == nullptr) {
        *front = *rear = newNode;
    } else {
        (*rear)->next = newNode;
        *rear = newNode;
    }
    cout << "\nBerhasil Menambahkan (" << newNode->data.lagu.judul << " - " << newNode->data.lagu.artist << ") ke Playlist" << endl;
    Sleep(1000);
}

void dequeue(Node** front) {
    if (*front == nullptr) {
        cout << "Playlist Anda Kosong" << endl;
        Sleep(1000);
        return;
    }
    Node* temp = *front;
    *front = (*front)->next;
    cout << "\nBerhasil Menghapus (" << temp->data.lagu.judul << " - " << temp->data.lagu.artist << ") dari Playlist" << endl;
    delete temp;
    Sleep(1000);
}

Node* createNode() {
    Node* newNode = new Node;
    cout << "|| TAMBAHKAN MUSIK ||" << endl;
    cout << "=====================\n" << endl;
    cout << "Masukkan judul musik : ";
    cin.ignore();
    getline(cin, newNode->data.lagu.judul);
    check_string_kosong(newNode->data.lagu.judul, "judul musik");
    cout << "Masukkan nama artist : ";
    getline(cin, newNode->data.lagu.artist);
    check_string_kosong(newNode->data.lagu.artist, "nama artist");
    cout << "Masukkan durasi musik (dalam detik) : ";
    cin >> newNode->data.durasi;
    check_angka(newNode->data.durasi, "durasi musik");
    cout << "Masukkan genre musik : ";
    cin.ignore();
    getline(cin, newNode->data.genre);
    check_string_kosong(newNode->data.genre, "genre musik");
    cout << "Masukkan tahun rilis musik : ";
    cin >> newNode->data.tahunrilis;
    check_angka(newNode->data.tahunrilis, "tahun rilis musik");
    newNode->next = nullptr;
    return newNode;
}

void ubahdata_playlist(Node** top, Node** front) {
    Node* temp = nullptr;
    if (mode == "stack") {
        temp = *top;
        tampilkan_stack(*top);
    } else if (mode == "queue") {
        temp = *front;
        tampilkan_queue(*front);
    } else {
        cout << "Mode tidak valid" << endl;
        return;
    }
    string judul, artist;
    cout << "\n|| UBAH DATA PLAYLIST ||" << endl;
    cout << "========================\n" << endl;
    cout << "Masukkan judul musik yang ingin diubah : ";
    cin.ignore();
    getline(cin, judul);
    check_string_kosong(judul, "judul musik");
    while (temp != nullptr) {
        if (temp->data.lagu.judul == judul) {
            cout << "Masukkan perubahan judul musik : ";
            getline(cin, temp->data.lagu.judul);
            check_string_kosong(temp->data.lagu.judul, "judul musik");
            cout << "Masukkan perubahan nama artist : ";
            getline(cin, temp->data.lagu.artist);
            check_string_kosong(temp->data.lagu.artist, "nama artist");
            cout << "Masukkan perubahan durasi musik (dalam detik) : ";
            cin >> temp->data.durasi;
            check_angka(temp->data.durasi, "durasi musik");
            cout << "Masukkan perubahan genre musik : ";
            cin.ignore();
            getline(cin, temp->data.genre);
            check_string_kosong(temp->data.genre, "genre musik");
            cout << "Masukkan perubahan tahun rilis musik : ";
            cin >> temp->data.tahunrilis;
            check_angka(temp->data.tahunrilis, "tahun rilis musik");
            cout << "\nBerhasil Mengubah Data Playlist" << endl;
            Sleep(1000);
            return;
        }
        temp = temp->next;
    }
    cout << "Musik tidak ditemukan" << endl;
    Sleep(1000);
}

void menu_stack (Node** top) {
    string pilihan;
    while (true) {
        system("cls");
        cout << "               STACK MENU" << endl;
        cout << "==========================================" << endl;
        cout << "|| [1] Tampilkan Playlist Musik         ||" << endl;
        cout << "|| [2] Push (Tambah Musik)              ||" << endl;
        cout << "|| [3] Pop (Hapus Musik)                ||" << endl;
        cout << "|| [4] Ubah Data Playlist Musik         ||" << endl;
        cout << "|| [5] Kembali ke Main Menu             ||" << endl;
        cout << "==========================================" << endl;
        cout << "Pilih Menu : ";
        cin >> pilihan;
        system("cls");
        if (pilihan == "1") {
            tampilkan_stack(*top);
            cout << "\nTekan Enter untuk kembali ke menu";
            cin.ignore();
            cin.get();
        } 
        else if (pilihan == "2") {
            push(top);
        } 
        else if (pilihan == "3") {
            pop(top);
        } 
        else if (pilihan == "4") {
            ubahdata_playlist(top, nullptr);
        } 
        else if (pilihan == "5") {
            break;
        }
    }
}

void menu_queue (Node** front, Node** rear) {
    string pilihan;
    while (true) {
        system("cls");
        cout << "               QUEUE MENU" << endl;
        cout << "==========================================" << endl;
        cout << "|| [1] Tampilkan Playlist Musik         ||" << endl;
        cout << "|| [2] Enqueue (Tambah Musik)           ||" << endl;
        cout << "|| [3] Dequeue (Hapus Musik)            ||" << endl;
        cout << "|| [4] Ubah Data Playlist Musik         ||" << endl;
        cout << "|| [5] Kembali ke Main Menu             ||" << endl;
        cout << "==========================================" << endl;
        cout << "Pilih Menu : ";
        cin >> pilihan;
        system("cls");
        if (pilihan == "1") {
            tampilkan_queue(*front);
            cout << "\nTekan Enter untuk kembali ke menu";
            cin.ignore();
            cin.get();
        } 
        else if (pilihan == "2") {
            enqueue(front, rear);
        } 
        else if (pilihan == "3") {
            dequeue(front);
        } 
        else if (pilihan == "4") {
            ubahdata_playlist(nullptr, front);
        } 
        else if (pilihan == "5") {
            break;
        }
    }
}

int main() {
    Node* top = nullptr;
    Node* front = nullptr;
    Node* rear = nullptr;
    string pilihan;

    // Inisialisasi data awal untuk mode stack
    Node* newNode = new Node;
    newNode->data.lagu.judul = "Viva La Vida"; newNode->data.lagu.artist = "Coldplay"; newNode->data.durasi = 242; newNode->data.genre = "Alternative Rock"; newNode->data.tahunrilis = 2008; newNode->next = nullptr;
    top = newNode;
    newNode = new Node; newNode->data.lagu.judul = "Talking to the Moon"; newNode->data.lagu.artist = "Bruno Mars"; newNode->data.durasi = 217; newNode->data.genre = "Pop"; newNode->data.tahunrilis = 2010; newNode->next = top;
    top = newNode;

    // Inisialisasi data awal untuk mode queue
    newNode = new Node;
    newNode->data.lagu.judul = "Viva La Vida"; newNode->data.lagu.artist = "Coldplay"; newNode->data.durasi = 242; newNode->data.genre = "Alternative Rock"; newNode->data.tahunrilis = 2008; newNode->next = nullptr;
    front = rear = newNode;
    newNode = new Node; newNode->data.lagu.judul = "Talking to the Moon"; newNode->data.lagu.artist = "Bruno Mars"; newNode->data.durasi = 217; newNode->data.genre = "Pop"; newNode->data.tahunrilis = 2010; newNode->next = nullptr;
    rear->next = newNode; rear = newNode;

    while (true) {
        system("cls");
        cout << "            PLAYLIST MAIN MENU" << endl;
        cout << "==========================================" << endl;
        cout << "|| [1] Stack Mode                       ||" << endl;
        cout << "|| [2] Queue Mode                       ||" << endl;
        cout << "|| [3] Keluar Program                   ||" << endl;
        cout << "==========================================" << endl;
        cout << "Pilih Menu : ";
        cin >> pilihan;
        system("cls");
        if (pilihan == "1") {
            mode = "stack";
            menu_stack(&top);
        } 
        else if (pilihan == "2") {
            mode = "queue";
            menu_queue(&front, &rear);
        } 
        else if (pilihan == "3") {
            break;
        }
    }
    system("cls");
    cout << "Anda Telah Keluar dari Program" << endl;
    return 0;
}