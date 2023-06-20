/*  NAMA    : AL JAUZI ABDURROHMAN
    NIM     : 1232000106 */
#include <iostream>
using namespace std;

int fibonacci(int n) // FUNGSI FIBONACCI
{
    if ((n==1) or (n==2))
    {
        return 1;
    } // JIKA INPUT BERNILAI 1 ATAU 2 (DERET KE 1 ATAU 2) MAKA HASILNYA ADALAH 1

    else
    {
        return (fibonacci(n-1)+fibonacci(n-2));
    } /* JIKA INPUT =/= 1 ATAU 2, MAKA AKAN MEMANGGIL FUNGSI INI LAGI DAN
        DILAKUKAN OPERASI BILANGAN SEBELUMNYA DITAMBAH 2 BILANGAN SEBELUMNYA */
}

int main()
{
    int n;
    cout << "Masukkan deret fibonacci ke-: "; cin >> n; // INPUT DERET KE-N YANG INGIN DITAMPILKAN
    cout << "\nHasil fibonacci: " << endl << "Sf(" << n << ") = " << fibonacci(n); // MENAMPILKAN DERET KE-N DERET FIBONACCI
    cout << endl << endl;

    system("pause");
    return 0;
}
