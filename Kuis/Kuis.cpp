/*  NAMA    : AL JAUZI ABDURROHMAN
    NIM     : 123200106, IF-D     */

#include <iostream>
using namespace std;

int n1, n2, pangkat;
int x, y;
char cobalagi;

bool found;

int perpangkatan(int n1, int n2)
{
	if (n2 == 0)
	{
		return 1;
	}

	else
	{
		return perpangkatan(n1, n2-1)*n1;
	}
}

int searching()
{
	string carinama, caribulan;
	int banyakmhw, caritahun, cari;

	typedef struct // STRUCT MAHASISWA
	{
		string nama, bulan;
		int tanggal, tahun;
	} mahasiswa;

	mahasiswa mhw[99];

	cout << "\nMasukkan banyak mahasiswa : "; cin >> banyakmhw;

	for (int i = 0; i < banyakmhw; i++)
	{
		cout << "\nMahasiswa " << i+1;
		cout << "\n\tNama : "; cin >> mhw[i].nama;
		cout << "\t" << mhw[i].nama << " lahir pada : " << endl;
		cout << "\t\tContoh\t: 6 Oktober 2002" << endl;

			cout << "\t\tTanggal\t: ";
			cin >> mhw[i].tanggal;
			cout << "\t\tBulan\t: ";
			cin >> mhw[i].bulan;
			cout << "\t\tTahun\t: ";
			cin >> mhw[i].tahun;

	}

	cout << "\nSearching Data\n\n";
	START:
	cout << "Pencarian data berdasarkan" << endl;
	cout << "1. Nama\n2. Bulan Lahir\n3. Tahun Lahir" << endl;
	cout << "Pencarian\t: "; cin >> cari;

	if (cari == 1)
	{
		cout << "\nNama yang dicari\t: "; cin >> carinama;
		found = false;

		int i = 0;
		while ((i < banyakmhw) && (!found))
        {
            if (mhw[i].nama == carinama)
            {
                found = true;
                cout << "\nMahasiswa " << i+1 << endl;
				cout << "\t" << mhw[i].nama << " terlahir pada" << endl;
				cout << "\t\tTanggal\t: "<< mhw[i].tanggal << endl;
				cout << "\t\tBulan\t: "<< mhw[i].bulan << endl;
				cout << "\t\tTahun\t: "<< mhw[i].tahun << endl;
            }
            else
            {
                i++;
            }
        }

        if(found)
        {
            cout << "Data ditemukan" << endl;
        }

        else
        {
            cout << "Data tidak ditemukan" << endl;
        }
	}

	if (cari == 2)
	{
		cout << "\nBulan lahir yang dicari\t: "; cin >> caribulan;
		found = false;

		int i = 0;
		while ((i < banyakmhw) && (!found))
        {
            if (mhw[i].bulan == caribulan)
            {
                found = true;
                cout << "\nMahasiswa " << i+1 << endl;
				cout << "\t" << mhw[i].nama << " terlahir pada" << endl;
				cout << "\t\tTanggal\t: "<< mhw[i].tanggal << endl;
				cout << "\t\tBulan\t: "<< mhw[i].bulan << endl;
				cout << "\t\tTahun\t: "<< mhw[i].tahun << endl;
            }
            else
            {
                i++;
            }
        }

        if(found)
        {
            cout << "Data ditemukan" << endl;
        }

        else
        {
            cout << "Data tidak ditemukan" << endl;
        }
	}

	if (cari == 3)
	{
		cout << "\nTahun lahir yang dicari\t: "; cin >> caritahun;
		found = false;

		int i = 0;
		while ((i < banyakmhw) && (!found))
        {
            if (mhw[i].tahun == caritahun)
            {
                found = true;
                cout << "\nMahasiswa " << i+1 << endl;
				cout << "\t" << mhw[i].nama << " terlahir pada" << endl;
				cout << "\t\tTanggal\t: "<< mhw[i].tanggal << endl;
				cout << "\t\tBulan\t: "<< mhw[i].bulan << endl;
				cout << "\t\tTahun\t: "<< mhw[i].tahun << endl;
            }
            else
            {
                i++;
            }
        }

        if(found)
        {
            cout << "Data ditemukan" << endl;
        }

        else
        {
            cout << "Data tidak ditemukan" << endl;
        }
    }

    cout << "Coba lagi? (y/n) ";
    cin >> cobalagi;
    if (cobalagi == 'y')
    {
        system("cls");
        goto START;
    }

    else
    {
        return 0;
    }
}

int matriks(int x, int y)
{
	int elemen[99][99];
	int top, bottom, left, right;

	cout << "Matriks Spiral\n\n";
	cout << "Jumlah Baris : "; cin >> x;
	cout << "Jumlah Kolom : "; cin >> y;
	cout << endl;

	for (int i = 0; i < x; i++)
	{
		for (int j = 0; j < y; j++)
		{
			cout << "Elemen[" << i+1 << "][" << j+1 << "] = ";
			cin >> elemen[i][j];
		}
	}

	cout << "\nMATRIKS\n\n";
	for (int i = 0; i < x; i++)
	{
		for (int j = 0; j < y; j++)
		{
			cout << elemen[i][j] << " ";
		}
		cout << endl;
	}

	top = 0;
	bottom = x;
	left = 0;
	right = y;

	cout << "\nMATRIKS SPIRAL\n\n";

	while ((top < bottom) && (left < right))
	{
		for (int i = left; i < right; ++i)
		{
			cout << elemen[top][i] << " ";
		}
		top++;

		for (int i = top; i < bottom; ++i)
		{
			cout << elemen[i][right-1] << " ";
		}
		right--;

		if (top < bottom)
		{
			for (int i = right-1; i >= left; --i)
			{
				cout << elemen[bottom-1][i] << " ";
			}
			bottom--;
		}

		if (left < right)
		{
			for (int i = bottom-1; i >= top; --i)
			{
				cout << elemen[i][left] << " ";
			}
			left++;
		}
	}
	return 0;
}

int main()
{
	START:
	int jawab;

	cout << "=== MAIN MENU ====" << endl;
	cout << "1. Aplikasi Perpangkatan" << endl;
	cout << "2. Program Searching" << endl;
	cout << "3. Program Matriks" << endl;
	cout << "0. Keluar" << endl;
	cout << "Jawab : "; cin >> jawab;

	switch (jawab)
	{
		case 1:
            cout << "\nAplikasi Perpangkatan" << endl;
            cout << "\nMasukkan nilai pertama	: "; cin >> n1;
            cout << "Masukkan nilai kedua	: "; cin >> n2;
            pangkat = perpangkatan(n1,n2);
            cout << "Hasilnya adalah " << pangkat << endl;
            break;

		case 2:
            searching();
            break;

		case 3:
            matriks(x, y);
            break;

		default:
            break;
	}

	cout << "\nApakah anda ingin mencoba lagi (y/n)? ";
	cin >> cobalagi;

	if (cobalagi == 'y')
    {
        system("cls");
        goto START;
    }

    else
    {
        return 0;
    }
}
