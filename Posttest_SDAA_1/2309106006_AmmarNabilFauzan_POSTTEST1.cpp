// SEGITIGA PASCAL
// Nama: Ammar Nabil Fauzan
// NIM: 2309106006

#include <iostream>
using namespace std;

// fungsi rekursif dengan rumus untuk menghitung segitiga pascal
int pascal(int baris, int kolom) {
    if (kolom == 0 || kolom == baris) {
        return 1;
    } else {
        return pascal(baris - 1, kolom - 1) + pascal(baris - 1, kolom);
    }
}

// fungsi untuk mencetak segitiga pascal
void cetakSegitigaPascal(int baris) {
    cout << "SEGITIGA PASCAL" << endl;

    // ini looping untuk menampilkan segitiga pascal
    for (int i = 0; i < baris; i++) {
        for (int j = 0; j <= i; j++) {
            cout << pascal(i, j) << " ";
        }
        cout << endl;
    }
}

int main() {
    int baris = 3;
    cetakSegitigaPascal(baris);

    return 0;
}
