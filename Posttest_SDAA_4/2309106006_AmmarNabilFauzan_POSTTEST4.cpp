#include <iostream>
#include <cstdlib>
using namespace std;

struct menu{
    string nama_menu;
    int harga;
    int stok;
};

struct antrean{
    string nama;
    int umur;
};

struct node {
    antrean orang;
    menu makanan;
    node *next;
    node *prev;
};

node *head = NULL;
node *last = NULL;

bool kosong() {
    return head == NULL;
}

void masuk_antrean(){
    antrean orang;
    cout << "" << endl;
    cout << "Masukkan nama : ";
    getline(cin >> ws, orang.nama);
    cout << "Masukkan umur : ";
    cin >> orang.umur;

    if (kosong()) {
        node *baru = new node;
        baru->orang = orang;
        baru->next = NULL;
        baru->prev = NULL;
        head = baru;
        last = baru;
    } else {
        node *baru = new node;
        baru->orang = orang;
        baru->prev = last;
        last->next = baru;
        baru->next = NULL;
        last = baru;
    }
}

void cancel_antrean(){
    if (kosong()) {
        cout << "Queue Underflow !!" << endl;
        return;
    } else if (head == last) {
        delete head;
        head = NULL;
        last = NULL;
        cout << "Antrean sudah kosong" << endl;
    } else {
        node *temp = head;
        head = head->next;
        head->prev = NULL;
        delete temp;
        cout << "Antrean dibatalkan" << endl;
    }
}

void show() {
    if (kosong()) {
        cout << "Queue Underflow !!" << endl;
        return;
    }
    node *temp = head;
    while (temp != NULL) {
        cout << "Nama : " << temp->orang.nama << endl;
        cout << "Umur : " << temp->orang.umur << endl;
        cout << "" << endl;
        temp = temp->next;
    }
}

node* tambah_menu() {
    cout << "" << endl;
    node *baru = new node;
    cout << "Masukkan nama menu : ";
    getline(cin >> ws, baru->makanan.nama_menu);
    cout << "Masukkan harga : ";
    cin >> baru->makanan.harga;
    cout << "Masukkan stok : ";
    cin >> baru->makanan.stok;
    baru->next = NULL;
    baru->prev = NULL;
    return baru;
}

void push_menu(node** top) {
    node *baru = tambah_menu();
    if (*top == NULL) {
        *top = baru;
    } else {
        baru->next = *top;
        (*top)->prev = baru;
        *top = baru;
    }
}

void pop_menu(node** top) {
    if (*top == NULL) {
        cout << "Stack Underflow !!" << endl;
        return;
    } else if ((*top)->next == NULL) {
        delete *top;
        *top = NULL;
    } else {
        node *temp = *top;
        *top = (*top)->next;
        (*top)->prev = NULL;
        delete temp;
    }
}

void peek_menu(node* top) {
    if (top == NULL || top->next == NULL) {
        cout << "Stack Underflow !!" << endl;
        return;
    }
    while (top != NULL) {
        cout << "" << endl;
        cout << "Nama menu : " << top->makanan.nama_menu << endl;
        cout << "Harga : " << top->makanan.harga << endl;
        cout << "Stok : " << top->makanan.stok << endl;
        top = top->next;

    }
}

int main(){
    node *top = NULL;
    int pilihan;

        while (true) {
            cout << "" << endl;
            cout << "1. Tambah antrean" << endl;
            cout << "2. Batal antrean" << endl;
            cout << "3. Lihat antrean" << endl;
            cout << "4. Tambah menu" << endl;
            cout << "5. Hapus menu" << endl;
            cout << "6. Lihat menu" << endl;
            cout << "7. Keluar" << endl;
            cout << "" << endl;
            cout << "Masukkan pilihan : ";
            cin >> pilihan;

            switch (pilihan){
                case 1: 
                    masuk_antrean();
                    break;
                case 2:
                    cancel_antrean();
                    break;
                case 3:
                    show();
                    break;
                case 4:
                    push_menu(&top);
                    break;
                case 5:
                    pop_menu(&top);
                    break;
                case 6:
                    peek_menu(top);
                    break;
                case 7:
                    exit(0);
                    break;
            }    
    }

    return 0;
}

