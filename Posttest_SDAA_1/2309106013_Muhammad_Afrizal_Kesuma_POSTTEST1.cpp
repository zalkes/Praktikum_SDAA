#include <iostream>
using namespace std;

void menara_hanoi(int banyak_piringan, string asal, string tujuan, string sementara) {
    if (banyak_piringan == 1) {
        cout << "\nPindahkan piringan 1 dari menara " << asal << " ke menara " << tujuan << endl;
        return;
    }
    menara_hanoi(banyak_piringan - 1, asal, sementara, tujuan);
    cout << "\nPindahkan piringan " << banyak_piringan << " dari menara " << asal << " ke menara " << tujuan << endl;
    menara_hanoi(banyak_piringan - 1, sementara, tujuan, asal);
}

int main() {
    int banyak_piringan = 3;
    cout << "============================================================" << endl;
    cout << "              Nama : Muhammad Afrizal Kesuma" << endl;
    cout << "              NIM  : 2309106013" << endl;
    cout << "              Kelas: A1'23" << endl;
    cout << "------------------------------------------------------------" << endl;
    cout << "                POSTTEST 1 STRUKTUR DATA" << endl;
    cout << "                  PROGRAM MENARA HANOI" << endl;
    cout << "============================================================" << endl;
    cout << "Langkah-langkah memindahkan " << banyak_piringan << " piringan Menara Hanoi:" << endl;
    menara_hanoi(banyak_piringan, "asal", "tujuan", "sementara");
    cout << "============================================================" << endl;
    return 0;
}