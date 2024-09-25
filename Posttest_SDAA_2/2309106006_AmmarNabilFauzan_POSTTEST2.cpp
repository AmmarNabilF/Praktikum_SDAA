#include <iostream>
#include <cstdlib>
using namespace std;

struct menu{
    string nama_menu;
    int harga;
    int stok;
};

struct maks_data{
    struct menu data_menu[10];
};

maks_data menu;
int jumlah_menu = 0;
int menu_terhapus = 0;

void tambah_menu(){
    cout << "\nMasukkan jumlah menu yang ingin ditambah: ";
    cin >> jumlah_menu;

    if (jumlah_menu > 10){
        cout << "\nMaaf. Anda telah melebihi batas maksimal dari jumlah menu yang ingin ditambah\n" << endl;
        return;
    }
    else{
        for (int i = 0; i < jumlah_menu; ++i){
            cout << "Menu ke-" << i + 1 << endl;
            cin.ignore();
            cout << "Nama Menu: ";
            getline(cin, menu.data_menu[i].nama_menu);
            cout << "Harga: ";
            cin >> menu.data_menu[i].harga;
            cout << "Stok: ";
            cin >> menu.data_menu[i].stok;
            cout << " " << endl;
        }
    }
}

int jumlah_data(int *jumlah){
    *jumlah = jumlah_menu;
    return *jumlah;
}

int jumlah_menu_dihapus(int &terhapus){
    return terhapus = menu_terhapus;
}

void tampilkan_data_menu(){
    if (jumlah_menu == 0) {
        cout << "Belum ada data untuk ditampilkan" << endl;
        cout << " " << endl;
        return;
    }
    for (int i = 0; i < jumlah_menu; ++i){
        cout << i << ")Nama Menu: " << menu.data_menu[i].nama_menu << endl;
        cout << "Harga: " << menu.data_menu[i].harga << endl;
        cout << "Stok: " << menu.data_menu[i].stok << endl;
        cout << " " << endl;
    }
}

void update_data_buku(){
    if (jumlah_menu == 0) {
        cout << "Belum ada data untuk diperbarui" << endl;
        cout << " " << endl;
        return;
    }

    tampilkan_data_menu();

    cout << "Perbarui Data";
    cout << " " << endl;
    int pilih;
    cout << "\nSilahkan pilih sesuai nomor urut: ";
    cin >> pilih;

    if (pilih >= 0 && pilih < jumlah_menu){
        cout << "\nBerikut data menu yang anda pilih\n: " << endl;
        cout << "Nama Menu: " << menu.data_menu[pilih].nama_menu << endl;
        cout << "Harga: " << menu.data_menu[pilih].harga << endl;
        cout << "Stok: " << menu.data_menu[pilih].stok << endl;

        cout << "\nMasukkan data baru untuk menu ke-" << pilih + 1 << endl;
        cin.ignore();
        cout << "Perbaikan nama menu: ";
        getline(cin, menu.data_menu[pilih].nama_menu);
        cout << "Perbaikan harga: ";
        cin >> menu.data_menu[pilih].harga;
        cout << "Perbaikan stok: ";
        cin >> menu.data_menu[pilih].stok;
        cout << "Data menu berhasil diperbarui ! ! !" << endl;
        cout << " " << endl;
    }
    else {
        cout << "Angka yang dimasukkan tidak benar (X)\n" << endl;
        cout << " " << endl;
    }
}

void drop_data_menu(){
    if (jumlah_menu == 0) {
        cout << "Belum ada data untuk dihapus" << endl;
        cout << " " << endl;
        return;
    }

    tampilkan_data_menu();

    cout << "Hapus Data";
    cout << " " << endl;
    int pilih;
    cout << "\nSilahkan pilih sesuai nomor urut: ";
    cin >> pilih;

    if (pilih >= 0 && pilih < jumlah_menu){
        for (int i = pilih; i < jumlah_menu - 1; ++i){
            menu.data_menu[i] = menu.data_menu[i + 1];
        }

        jumlah_menu--;
        menu_terhapus++;

        cout << "Data menu ke-" << pilih+1 << " " << "Telah dihapus" << endl;
        cout << " " << endl;
    }
    else {
        cout << "Angka yang anda masukkan tidak valid (X)" << endl;
        cout << " " << endl;
    }
}

void crud_menu(){
    int pilih;
    do{
        cout << "Menu Utama" << endl;
        cout << "1. Tambah Data Menu" << endl;
        cout << "2. Tampilkan Data Menu" << endl;
        cout << "3. Perbarui Data Menu" << endl;
        cout << "4. Hapus Data Menu" << endl;
        cout << "5. Jumlah Data Menu" << endl;
        cout << "6. Jumlah Data Menu yang Dihapus" << endl;
        cout << "7. Keluar" << endl;
        cout << "Pilih: ";
        cin >> pilih;

        switch(pilih){
            case 1:
                tambah_menu();
                break;
            case 2:
                tampilkan_data_menu();
                break;
            case 3:
                update_data_buku();
                break;
            case 4:
                drop_data_menu();
                break;
            case 5:
                jumlah_data(&jumlah_menu);
                cout << "Jumlah data menu: " << jumlah_menu << endl;
                break;
            case 6:
                cout << "Jumlah data menu yang dihapus: " << jumlah_menu_dihapus(menu_terhapus) << endl;
                break;
            case 7:
                cout << "Terima kasih telah menggunakan program ini" << endl;
                break;
            default:
                cout << "Pilihan tidak valid" << endl;
                break;
        }
    } while(pilih != 7);
}

int main(){
    crud_menu();
    return 0;
}