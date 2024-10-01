#include <iostream>
#include <cstdlib>
using namespace std;

struct menu{
    string nama_menu;
    int harga;
    int stok;
    menu *next;
};

menu *head = nullptr;

void tambah_first_menu(string nama_menu, int harga, int stok){
    menu *baru = new menu;
    baru->nama_menu = nama_menu;
    baru->harga = harga;
    baru->stok = stok;
    baru->next = head;
    head = baru;
}

void tambah_last_menu(string nama_menu, int harga, int stok){
    menu *baru = new menu;
    baru->nama_menu = nama_menu;
    baru->harga = harga;
    baru->stok = stok;
    baru->next = nullptr;
    if(head == nullptr){
        head = baru;
    }else{
        menu *temp = head;
        while(temp->next != nullptr){
            temp = temp->next;
        }
        temp->next = baru;
    }
}

void hapus_menu_first(){
    if(head == nullptr){
        cout << "Data kosong" << endl;
    }else{
        menu *temp = head;
        head = head->next;
        delete temp;
    }
}

void hapus_menu_last(){
    if(head == nullptr){
        cout << "Data kosong" << endl;
    }else if(head->next == nullptr){
        delete head;
        head = nullptr;
    }else{
        menu *temp = head;
        while(temp->next->next != nullptr){
            temp = temp->next;
        }
        delete temp->next;
        temp->next = nullptr;
    }
}

void tampilkan_menu(){
    if(head == nullptr){
        cout << "Data kosong" << endl;
    }else{
        menu *temp = head;
        while(temp != nullptr){
            cout << "Nama Menu: " << temp->nama_menu << endl;
            cout << "Harga: " << temp->harga << endl;
            cout << "Stok: " << temp->stok << endl;
            cout << endl;
            temp = temp->next;
        }
    }
}

void perbarukan_menu(string nama_menu, int harga, int stok){
    if(head == nullptr){
        cout << "Data kosong" << endl;
    }else{
        menu *temp = head;
        while(temp != nullptr){
            if(temp->nama_menu == nama_menu){
                temp->harga = harga;
                temp->stok = stok;
                break;
            }
            temp = temp->next;
        }
    }
}

void menu_toko(){
    cout << "Menu Toko" << endl;
    cout << "1. Tambah Menu Awal" << endl;
    cout << "2. Tambah Menu Akhir" << endl;
    cout << "3. Hapus Menu Awal" << endl;
    cout << "4. Hapus Menu Akhir" << endl;
    cout << "5. Tampilkan Menu" << endl;
    cout << "6. Perbarukan Menu" << endl;
    cout << "7. Keluar" << endl;
    cout << "Pilih Menu: ";

    int pilih;
    cin >> pilih;
    switch(pilih){
        case 1:
            {
                string nama_menu;
                int harga, stok;
                cout << "Nama Menu: ";
                cin >> nama_menu;
                cout << "Harga: ";
                cin >> harga;
                cout << "Stok: ";
                cin >> stok;
                tambah_first_menu(nama_menu, harga, stok);
                break;
            }
        case 2:
            {
                string nama_menu;
                int harga, stok;
                cout << "Nama Menu: ";
                cin >> nama_menu;
                cout << "Harga: ";
                cin >> harga;
                cout << "Stok: ";
                cin >> stok;
                tambah_last_menu(nama_menu, harga, stok);
                break;
            }
        case 3:
            hapus_menu_first();
            break;
        case 4:
            hapus_menu_last();
            break;
        case 5:
            tampilkan_menu();
            break;
        case 6:
            {
                string nama_menu;
                int harga, stok;
                cout << "Nama Menu: ";
                cin >> nama_menu;
                cout << "Harga: ";
                cin >> harga;
                cout << "Stok: ";
                cin >> stok;
                perbarukan_menu(nama_menu, harga, stok);
                break;
            }
        case 7:
            exit(0);
            break;
        default:
            cout << "Menu tidak tersedia" << endl;
            break;
    }
}

int main(){
    while(true){
        menu_toko();
    }
    return 0;
}




