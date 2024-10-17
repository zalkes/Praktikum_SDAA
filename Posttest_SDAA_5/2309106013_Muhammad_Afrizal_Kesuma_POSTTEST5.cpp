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

struct Node {
    infomusik data;
    Node* next;
};

Node* createNode();
void tampilkan_playlist(Node* head);
void push(Node** head);
void pop(Node** head);
void enqueue(Node** head, Node** tail);
void dequeue(Node** head);

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

void tampilkan_playlist(Node* head) {
    if (head == nullptr) {
        cout << "Playlist Anda Kosong" << endl;
        return;
    }
    Node* temp = head;
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

void push(Node** head) {
    Node* newNode = createNode();
    newNode->next = *head;
    *head = newNode;
    cout << "\nBerhasil Menambahkan (" << newNode->data.lagu.judul << " - " << newNode->data.lagu.artist << ") ke Playlist" << endl;
    Sleep(1000);
}

void pop(Node** head) {
    if (*head == nullptr) {
        cout << "Playlist Anda Kosong" << endl;
        Sleep(1000);
        return;
    }
    Node* temp = *head;
    *head = (*head)->next;
    cout << "\nBerhasil Menghapus (" << temp->data.lagu.judul << " - " << temp->data.lagu.artist << ") dari Playlist" << endl;
    delete temp;
    Sleep(1000);
}

void enqueue(Node** head, Node** tail) {
    Node* newNode = createNode();
    if (*head == nullptr) {
        *head = *tail = newNode;
    } else {
        (*tail)->next = newNode;
        *tail = newNode;
    }
    cout << "\nBerhasil Menambahkan (" << newNode->data.lagu.judul << " - " << newNode->data.lagu.artist << ") ke Playlist" << endl;
    Sleep(1000);
}

void dequeue(Node** head) {
    if (*head == nullptr) {
        cout << "Playlist Anda Kosong" << endl;
        Sleep(1000);
        return;
    }
    Node* temp = *head;
    *head = (*head)->next;
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

void ubahdata_playlist(Node** head) {
    Node* temp = *head;
    tampilkan_playlist(*head);
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

Node* partition(Node* low, Node* high, Node** newLow, Node** newHigh) {
    Node* pivot = high;
    Node* prev = nullptr;
    Node* curr = low;
    Node* tail = pivot;

    while (curr != pivot) {
        if (curr->data.lagu.judul < pivot->data.lagu.judul) {
            if ((*newLow) == nullptr) {
                (*newLow) = curr;
            }
            prev = curr;
            curr = curr->next;
        } else {
            if (prev) {
                prev->next = curr->next;
            }
            Node* temp = curr->next;
            curr->next = nullptr;
            tail->next = curr;
            tail = curr;
            curr = temp;
        }
    }

    if ((*newLow) == nullptr) {
        (*newLow) = pivot;
    }

    (*newHigh) = tail;

    return pivot;
}

Node* getTail(Node* curr) {
    while (curr != nullptr && curr->next != nullptr) {
        curr = curr->next;
    }
    return curr;
}

Node* quickSortRecursive(Node* low, Node* high) {
    if (!low || low == high) {
        return low;
    }

    Node* newLow = nullptr;
    Node* newHigh = nullptr;

    Node* pivot = partition(low, high, &newLow, &newHigh);

    if (newLow != pivot) {
        Node* temp = newLow;
        while (temp->next != pivot) {
            temp = temp->next;
        }
        temp->next = nullptr;

        newLow = quickSortRecursive(newLow, temp);

        temp = getTail(newLow);
        temp->next = pivot;
    }

    pivot->next = quickSortRecursive(pivot->next, newHigh);

    return newLow;
}

void quickSort(Node** headRef) {
    (*headRef) = quickSortRecursive(*headRef, getTail(*headRef));
    return;
}

void quickSort_asc(Node** head) {
    cout << "(PLAYLIST SEBELUM DIURUTKAN)" << endl;
    tampilkan_playlist(*head);
    quickSort(head);
    cout << "\n(PLAYLIST SETELAH DIURUTKAN BERDASARKAN JUDUL ASC)" << endl << endl;
    tampilkan_playlist(*head);
    cout << "\nTekan Enter untuk kembali ke menu";
    cin.ignore();
    cin.get();
    Sleep(1000);
}

void split(Node* source, Node** frontRef, Node** backRef) {
    Node* fast;
    Node* slow;
    slow = source;
    fast = source->next;

    while (fast != nullptr) {
        fast = fast->next;
        if (fast != nullptr) {
            slow = slow->next;
            fast = fast->next;
        }
    }

    *frontRef = source;
    *backRef = slow->next;
    slow->next = nullptr;
}

Node* sortedMerge(Node* a, Node* b) {
    Node* result = nullptr;

    if (a == nullptr)
        return b;
    else if (b == nullptr)
        return a;

    if (a->data.lagu.judul >= b->data.lagu.judul) {
        result = a;
        result->next = sortedMerge(a->next, b);
    } else {
        result = b;
        result->next = sortedMerge(a, b->next);
    }
    return result;
}

void mergeSort(Node** headRef) {
    Node* head = *headRef;
    Node* a;
    Node* b;

    if ((head == nullptr) || (head->next == nullptr)) {
        return;
    }

    split(head, &a, &b);

    mergeSort(&a);
    mergeSort(&b);

    *headRef = sortedMerge(a, b);
}

void mergeSort_desc(Node** head) {
    cout << "(PLAYLIST SEBELUM DIURUTKAN)" << endl;
    tampilkan_playlist(*head);
    mergeSort(head);
    cout << "\n(PLAYLIST SETELAH DIURUTKAN BERDASARKAN JUDUL DESC)" << endl << endl;
    tampilkan_playlist(*head);
    cout << "\nTekan Enter untuk kembali ke menu";
    cin.ignore();
    cin.get();
    Sleep(1000);
}

void menu_stack(Node** head) {
    string pilihan;
    while (true) {
        system("cls");
        cout << "                STACK MENU" << endl;
        cout << "===========================================" << endl;
        cout << "|| [1] Tampilkan Playlist Musik          ||" << endl;
        cout << "|| [2] Push (Tambah Musik di Awal)       ||" << endl;
        cout << "|| [3] Pop (Hapus Musik di Awal)         ||" << endl;
        cout << "|| [4] Ubah Data Playlist Musik          ||" << endl;
        cout << "|| [5] Urutkan Playlist (Quick Sort ASC) ||" << endl;
        cout << "|| [6] Urutkan Playlist (Merge Sort DESC)||" << endl;
        cout << "|| [7] Kembali ke Main Menu              ||" << endl;
        cout << "===========================================" << endl;
        cout << "Pilih Menu : ";
        cin >> pilihan;
        system("cls");
        if (pilihan == "1") {
            tampilkan_playlist(*head);
            cout << "\nTekan Enter untuk kembali ke menu";
            cin.ignore();
            cin.get();
        } 
        else if (pilihan == "2") {
            push(head);
        } 
        else if (pilihan == "3") {
            pop(head);
        } 
        else if (pilihan == "4") {
            ubahdata_playlist(head);
        } 
        else if (pilihan == "5") {
            quickSort_asc(head);
        } 
        else if (pilihan == "6") {
            mergeSort_desc(head);
        }
        else if (pilihan == "7") {
            break;
        }
    }
}

void menu_queue(Node** head, Node** tail) {
    string pilihan;
    while (true) {
        system("cls");
        cout << "                QUEUE MENU" << endl;
        cout << "===========================================" << endl;
        cout << "|| [1] Tampilkan Playlist Musik          ||" << endl;
        cout << "|| [2] Enqueue (Tambah Musik di Akhir)   ||" << endl;
        cout << "|| [3] Dequeue (Hapus Musik di Awal)     ||" << endl;
        cout << "|| [4] Ubah Data Playlist Musik          ||" << endl;
        cout << "|| [5] Urutkan Playlist (Quick Sort ASC) ||" << endl;
        cout << "|| [6] Urutkan Playlist (Merge Sort DESC)||" << endl;
        cout << "|| [7] Kembali ke Main Menu              ||" << endl;
        cout << "===========================================" << endl;
        cout << "Pilih Menu : ";
        cin >> pilihan;
        system("cls");
        if (pilihan == "1") {
            tampilkan_playlist(*head);
            cout << "\nTekan Enter untuk kembali ke menu";
            cin.ignore();
            cin.get();
        } 
        else if (pilihan == "2") {
            enqueue(head, tail);
        } 
        else if (pilihan == "3") {
            dequeue(head);
        } 
        else if (pilihan == "4") {
            ubahdata_playlist(head);
        } 
        else if (pilihan == "5") {
            quickSort_asc(head);
        } 
        else if (pilihan == "6") {
            mergeSort_desc(head);
        }
        else if (pilihan == "7") {
            break;
        }
    }
}

int main() {
    Node* head = nullptr;
    Node* tail = nullptr;
    string pilihan;

    // Inisialisasi data awal
    Node* newNode = new Node;
    newNode->data.lagu.judul = "Viva La Vida"; newNode->data.lagu.artist = "Coldplay"; newNode->data.durasi = 242; newNode->data.genre = "Alternative Rock"; newNode->data.tahunrilis = 2008; newNode->next = nullptr;
    head = tail = newNode;
    newNode = new Node; newNode->data.lagu.judul = "Talking to the Moon"; newNode->data.lagu.artist = "Bruno Mars"; newNode->data.durasi = 217; newNode->data.genre = "Pop"; newNode->data.tahunrilis = 2010; newNode->next = nullptr;
    tail->next = newNode; tail = newNode;

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
            menu_stack(&head);
        } 
        else if (pilihan == "2") {
            menu_queue(&head, &tail);
        } 
        else if (pilihan == "3") {
            break;
        }
    }
    system("cls");
    cout << "Anda Telah Keluar dari Program" << endl;
    return 0;
}