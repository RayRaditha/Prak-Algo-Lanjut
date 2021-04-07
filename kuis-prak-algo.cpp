#include <iostream>
#include <iomanip>
#include <string.h>
#include <string>
using namespace std;

typedef struct {
    char namaBarang[100];
    int jumlahBarang;
    int hargaBarang;
    char statusBarang[100];
    int total;
} dataBarang;

dataBarang produk[50];

int pilihMenu, jumlahData, i, j;
char pilihan;
char namaCari[20];

void inputData();
void cariData();
void tampilData();

int main()
{
	bool y = true;
	char ulang;
	
    do
    {
        cout << " Toko Sembako Maju Bersama " << endl;
        cout << "===========================" << endl;
        cout << "Menu" << endl;
        cout << "1. Input Data " << endl;
        cout << "2. Pencarian Data " << endl;
        cout << "3. Penampilan Data " << endl;
        cout << "4. Keluar " << endl;
        cout << "Silahkan Pilih angka : ";
        cin >> pilihMenu;
        
        switch (pilihMenu) {
			case 1:
				inputData();
				break;
			
			case 2:
				cariData();
				break;
				
			case 3:
				tampilData();
				break;
				
			case 4:
				break;
				
			default:
				cout << "Pilihan Anda Salah !" << endl;
				cout << "Silahkan Mengulang " << endl;
				break;
		}

        if (pilihMenu == 4) {
			y = false;		
			cout << "\nTerima kasih . . ." << endl;
		} else {
			cout << endl << endl;
			cout << "Kembali ke Menu (y/n): "; cin >> ulang;
			if (ulang=='y' || ulang=='Y') {
				system("cls");
			} 
		}
		
    } while (y==true);
}

void inputData()
{
    cout << "\nInput Data " << endl;
    cout << "Masukkan Jumlah Data = ";
    cin >> jumlahData;
    cin.ignore();
    
    for (i = 0; i < jumlahData; i++) {
        cout << "\nData ke " << i + 1 << endl;
        cout << "------------------------" << endl;
        cout << "Nama Barang        : "; 
        cin.getline(produk[i].namaBarang, sizeof(produk[i].namaBarang));
        cout << "Jumlah Barang      : "; cin >> produk[i].jumlahBarang;
        cout << "Harga Barang       : "; cin >> produk[i].hargaBarang;
        cout << "Status (Baru/Lama) : "; cin.ignore(); 
        cin.getline(produk[i].statusBarang, sizeof(produk[i].statusBarang));
        produk[i].total = produk[i].jumlahBarang * produk[i].hargaBarang;
        cout << "Total Harga        : " << produk[i].total;
        cout << endl;
    }
}

void cariData()
{
    dataBarang dataBarangCari;
    bool barang = false;
    cout << "\nPencarian Data " << endl;
    cout << "Masukkan Nama Barang yang akan dicari : ";
    cin >> namaCari;

    for (i = 0; i < jumlahData; i++)
    {
        if (strcmp(produk[i].namaBarang, namaCari) == 0)
        {
            dataBarangCari = produk[i];
            barang = true;
        }
        else
        {
            
        }
    }

    if (barang==true) {
        
        cout << "Stok " << dataBarangCari.namaBarang << " Tersedia" << endl;
    }
    else {
        cout << "Barang Tidak Ada" << endl;
    }
}

void tampilData()
{
    cout << "\nPenampilan Data " << endl;
    cout << "+-----------------------------------------------------------------------------------------+" << endl;
    cout << "| No. |       Nama Produk       |  Jumlah  |   Harga   |   Status   |     Total Harga     |" << endl;
    cout << "+-----------------------------------------------------------------------------------------+" << endl;
    
    for (i = 0; i < jumlahData; i++)
    {
		cout << "| " << setw(3) << i + 1 << " | ";
		cout << setw(23) << produk[i].namaBarang <<" | ";
		cout << setw(8) << produk[i].jumlahBarang << " | ";
		cout << setw(9) << produk[i].hargaBarang << " | ";
		cout << setw(10) << produk[i].statusBarang << " | ";
		cout << setw(19) << produk[i].total << " |" << endl;
    }
    
    cout << "+-----------------------------------------------------------------------------------------+" << endl;
}
