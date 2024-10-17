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


void tukar_menu(node *a, node *b){
    menu temp = a->makanan;
    a->makanan = b->makanan;
    b->makanan = temp;
}

node *partition_harga(node* low, node* high){
    int pivot = high->makanan.harga;
    node *i = low->prev;
    for (node *j = low; j != high; j = j->next){
        if (j->makanan.harga < pivot){
            i = (i == NULL) ? low : i->next;
            tukar_menu(i, j);
        }
    }
    i = (i == NULL) ? low : i->next;
    tukar_menu(i, high);
    return i;
}

void quickSort_harga(node* low, node* high){
    if (high != NULL && low != high && low != high->next){
        node *pi = partition_harga(low, high);
        quickSort_harga(low, pi->prev);
        quickSort_harga(pi->next, high);
    }
}

void tukar_antrean(node *front, node *rear){
    antrean temp = front->orang;
    front->orang = rear->orang;
    rear->orang = temp;
}

void shellSort_umur(node *front, int n){
    for (int gap = n/2; gap > 0; gap /= 2){
        for (node *i = front; i != NULL; i = i->next){
            for (node *j = i->next; j != NULL; j = j->next){
                if (i->orang.umur < j->orang.umur){
                    tukar_antrean(i, j);
                }
            }
        }
    }
}

node* tambah_antrean(){
    antrean orang;
    cout << "" << endl;
    cout << "Masukkan nama : ";
    getline(cin >> ws, orang.nama);
    cout << "Masukkan umur : ";
    cin >> orang.umur;

    node *baru = new node;
    baru->orang = orang;
    baru->next = NULL;
    baru->prev = NULL;
    return baru;
}

void masuk_antrean(node** front, node** rear){
    node *baru = tambah_antrean();
    if (*front == NULL) {
        *front = baru;
        *rear = baru;
    } else {
        baru->prev = *rear;
        (*rear)->next = baru;
        *rear = baru;
    }
}

void cancel_antrean(node** front, node** rear){
    if (*front == NULL) {
        cout << "Queue Underflow !!" << endl;
        return;
    } else if ((*front)->next == NULL) {
        delete *front;
        *front = NULL;
        *rear = NULL;
    } else {
        node *temp = *front;
        *front = (*front)->next;
        (*front)->prev = NULL;
        delete temp;
    }
}

void show(node* front){
    if (front == NULL) {
        cout << "Queue Underflow !!" << endl;
        return;
    }
    while (front != NULL) {
        cout << "" << endl;
        cout << "Nama : " << front->orang.nama << endl;
        cout << "Umur : " << front->orang.umur << endl;
        front = front->next;
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

int hitung_perulangan(node* top){
    int hitung = 0;
    while (top != NULL) {
        hitung++;
        top = top->next;
    }
    return hitung;
}

int hitung_perulangan2(node* front){
    int hitung = 0;
    while (front != NULL) {
        hitung++;
        front = front->next;
    }
    return hitung;
}

int main(){
    node *top = NULL;
    node *front = NULL;
    node *rear = NULL;
    int pilihan;
    

        while (true) {


            cout << "" << endl;
            cout << "1. Tambah antrean" << endl;
            cout << "2. Batal antrean" << endl;
            cout << "3. Lihat antrean" << endl;
            cout << "4. Tambah menu" << endl;
            cout << "5. Hapus menu" << endl;
            cout << "6. Lihat menu" << endl;
            cout << "7. Urutkan menu dari harga (asc)" << endl;    
            cout << "8. Urutkan antrean dari umur (desc)" << endl;
            cout << "9. Keluar" << endl;
            cout << "" << endl;
            cout << "Masukkan pilihan : ";
            cin >> pilihan;

            switch (pilihan){
                case 1: 
                    masuk_antrean(&front, &rear);
                    break;
                case 2:
                    cancel_antrean(&front, &rear);
                    break;
                case 3:
                    show(front);
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
                {
                    node* last = top;
                    while (last->next != NULL) {
                        last = last->next;
                    }
                    quickSort_harga(top, last);
                    if (top != NULL) {
                        peek_menu(top);
                    }
                    else {
                        cout << "Tidak ada menu" << endl;
                    }
                }                
                break;
                case 8:
                {
                    int n = hitung_perulangan2(front);
                    if (n > 0) {
                        shellSort_umur(front, n);
                        show(front);
                    }
                    else {
                        cout << "Tidak ada antrean" << endl;
                    }
                }
                break;

                case 9:
                    exit(0);
                    break;
            }    
    }

    return 0;
}

