/*  NAMA    : AL JAUZI ABDURROHMAN
    NIM     : 123200106, IF-D     */

#include <iostream>
#include <stdlib.h>
#include <conio.h>
using namespace std;

void pindah(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void bubble(int data[], int n)
{
    int i, j;
    for (i = 0; i < n-1; i++)
    {
	    for (j = 0; j < n-i-1; j++)
	    {
	        if (data[j] > data[j+1])
	        {
	        	pindah(&data[j], &data[j+1]);
	        }
	    }
	}
}

void printBubble(int data[], int size)
{
    int i;
    for (i = 0; i < size; i++)
    {
        cout << data[i] << " ";
    }
    cout << endl;
}

void insertion(int data[], int n)
{
    int i, kunci, j;
    for (i = 1; i < n; i++)
    {
        kunci = data[i];
        j = i - 1;

        /* memindahkan elemen array yang lebih besar
        daripada kunci ke satu posisi di depan posisi yg sekarang */
        while (j >= 0 && data[j] > kunci)
        {
            data[j + 1] = data[j];
            j = j - 1;
        }
        data[j + 1] = kunci;
    }
}

void printInsertion(int data[], int n)
{
    int i;
    for (i = 0; i < n; i++)
    {
        cout << data[i] << " ";
    }
    cout << endl;
}


void selection(int data[], int n)
{
    int i, j, min_idx;

    for (i = 0; i < n-1; i++)
    {
        // cari elemen array yg terkecil yg belumn diurutkan
        min_idx = i;
        for (j = i+1; j < n; j++)
        if (data[j] < data[min_idx])
            min_idx = j;

        // pindahkan elemen terkecil dengan elemen pertama
        pindah(&data[min_idx], &data[i]);
    }
}

void printSelection(int data[], int size)
{
    int i;
    for (i=0; i < size; i++)
    {
        cout << data[i] << " ";
    }
    cout << endl;
}

int main()
{
	START:
	int data[25] = {6, 1, 9, 3, 4, 10, 13, 11, 5, 7,
				2, 9, 15, 14, 15, 40, 4, 17, 20, 12,
				42, 22, 2, 4, 5};

	int i, pilih;
	char coba;

	int n = sizeof(data)/sizeof(data[0]);

	cout << "Data sebelum diurutkan:\n";

	for(int i = 0; i < 20; i++)
	{
		cout << data[i] << " ";
	}
	cout << "\n\n";

	PILIH:
	cout << "Pilih metode sorting:\n\n";
	cout << "\t1. Bubble Sort\n";
	cout << "\t2. Insertion Sort\n";
	cout << "\t3. Selection Sort\n";
	cout << "\tPilih: "; cin >> pilih;

	switch(pilih)
	{
		case 1:
	    bubble(data, n);
	    cout << "\nData setelah diurutkan:\n";
	    printBubble(data, n);
	    cout << endl;
		break;

		case 2:
	    insertion(data, n);
	    cout << "\nData setelah diurutkan:\n";
	    printInsertion(data, n);
	    cout << endl;
		break;

		case 3:
		selection(data, n);
	    cout << "\nData setelah diurutkan:\n";
	    printSelection(data, n);
	    cout << endl;
		break;

		default:
		cout << "\n\tSalah input.\n\n";
		goto PILIH;
		break;
	}

	cout << "Coba lagi? (y/n)"; cin >> coba;

	if (coba == 'y')
	{
		system("cls");
		goto START;
	}

	else
	{
		cout << endl;
    	system("pause");
		return 0;
	}
}
