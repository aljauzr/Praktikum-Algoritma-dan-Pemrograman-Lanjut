/*  NAMA    : AL JAUZI ABDURROHMAN
    NIM     : 123200106             */

#include <iostream>
#include <fstream>
#include <iomanip>
#include <limits>
using namespace std;

string nama;
int tanggal, bulan, tahun;
int banyak;
bool found;

typedef struct // STRUCT KEGIATAN
{
    string nama;
    int tanggal, bulan, tahun;
}kegiatan;

kegiatan keg[99];

void swap(string *x, string *y){
 	string temp;
	temp = *x;
	*x = *y;
	*y = temp;
}

void input()
{
    ofstream myFile;
    myFile.open("kegiatan.txt",ios::out);
    cout << "Masukkan banyak kegiatan\t= "; cin >> banyak; cin.ignore();

    for(int i = 0; i < banyak; i++)
    {
        cout << "\tKegiatan " << i+1 << endl;
        cout << "\t\tNama Kegiatan\t\t: "; getline(cin,keg[i].nama);
        cout << "\t\tTanggal\t\t\t: "; cin >> keg[i].tanggal;
        cout << "\t\tBulan (dalam angka)\t: "; cin >> keg[i].bulan;
        cout << "\t\tTahun\t\t\t: "; cin >> keg[i].tahun; cin.ignore();
        cout << endl;

        myFile << keg[i].nama << endl;
        myFile << keg[i].tanggal << endl;
        myFile << keg[i].bulan << endl;
        myFile << keg[i].tahun << endl;
    }
    myFile.close();
}

void selectsort() //SORTING DENGAN METODE SELECTION
{
		for(int i = 0;i < banyak-1;i++)
        {
            for(int j = 0;j < banyak-i-1;j++)
            {
                if(keg[j].tahun < keg[j+1].tahun)
                {
                    swap(keg[j], keg[j+1]);
                }
                else if(keg[j].tahun == keg[j+1].tahun)
                {
                	if(keg[j].bulan < keg[j+1].bulan)
                	{
                		swap(keg[j], keg[j+1]);
					}
					else if(keg[j].bulan == keg[j+1].bulan)
					{
						if(keg[j].tanggal < keg[j+1].tanggal)
						{
							swap(keg[j], keg[j+1]);
						}
					}
				}
            }
		}
}

void output()
{
    ifstream myFile;
    myFile.open("kegiatan.txt");

    int i = 0;
	while(getline(myFile,nama))
    {
		myFile >> tanggal;
		myFile >> bulan;
		myFile >> tahun;
        myFile.ignore(numeric_limits<streamsize>::max(),'\n');
		keg[i].nama = nama;
		keg[i].tanggal = tanggal;
		keg[i].bulan = bulan;
		keg[i].tahun = tahun;
		i++;
		banyak++;
    }

    selectsort();
    cout << endl;
    cout << "Daftar Kegiatan = " << endl << endl;

    for(int j = 0; j < banyak; j++)
    {
        cout << "\tKegiatan ke-" << j+1 << endl;
        cout << "\tNama\t= "<< keg[j].nama << endl;
        cout << "\tTanggal\t= " << keg[j].tanggal << endl;
        cout << "\tBulan\t= " << keg[j].bulan << endl;
        cout << "\tTahun\t= " << keg[j].tahun << endl << endl;
    }
}

void cari() //MENCARI DATA DENGAN METODE SEQUENTIAL
{
    START:
    int cariTgl, cariBln, cariThn;
    char carilagi;
    cout << "Masukkan Tanggal\t\t = "; cin >> cariTgl;
    cout << "Masukkan Bulan (dalam angka)\t = "; cin >> cariBln;
    cout << "Masukkan Tahun\t\t\t = "; cin >> cariThn;
    found = false;

    int i = 0;
    while ((i < banyak) && (!found))
    {
        if(keg[i].tanggal == cariTgl)
        {
            if(keg[i].bulan == cariBln)
            {
                if(keg[i].tahun == cariThn)
                {
                    found = true;
                    cout << endl;
                    cout << "NAMA\t= " << keg[i].nama << endl;
                    cout << "TANGGAL\t= " << keg[i].tanggal << endl;
                    cout << "BULAN\t= " << keg[i].bulan << endl;
                    cout << "TAHUN\t= " << keg[i].tahun << endl;
                }
                else
                {
                    i++;
                }
            }
        }
    }
     if(found)
	        {
	            cout << "\nData ditemukan." << endl;
	            cout << "Cari lagi? (y/n) "; cin >> carilagi;

                if (carilagi == 'y'  || carilagi == 'Y')
                {
                    system("cls");
                    goto START;
                }

                else
                {
                    system("cls");
                }
	        }

	        else
	        {
	            cout << "\nData tidak ditemukan.";
	            cout << "\nCari lagi? (y/n) "; cin >> carilagi;

                if (carilagi == 'y')
                {
                    system("cls");
                    goto START;
                }

                else
                {
                    system("cls");;
                }
	        }
}

int main()
{
    int pilih;
    char kembali;

    cout << "1. Input Kegiatan" << endl;
    cout << "2. Output Kegiatan" << endl;
    cout << "3. Cari Kegiatan" << endl;
    cout << "Pilih = "; cin >> pilih;
    system("cls");

    switch(pilih)
    {
        case 1 :
            input();
        break;

        case 2:
            output();
        break;

        case 3 :
            cari();
        break;

        default:
            cout << "Input salah!" << endl;
        break;
    }

    cout << "\nKembali? (y/n) "; cin  >> kembali;
        if (kembali == 'y' || kembali == 'Y')
        {
            system("cls");
            main();
        }
        else
        {
            return 0;
        }
    return 0;
}
