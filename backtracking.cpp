#include <iostream>
using namespace std;

#define BARIS 5
#define KOLOM 5

int labirin[BARIS][KOLOM] = {
    {1, 1, 0, 0, 0},
    {1, 0, 0, 0, 0},
    {1, 1, 1, 0, 0},
    {0, 0, 1, 1, 0},
    {0, 0, 1, 1, 1}
};

int jalur[BARIS][KOLOM] = {0};

// Mengecek apakah posisi bisa dilewati
bool cekPosisi(int x, int y)
{
    return (x >= 0 && x < BARIS &&
            y >= 0 && y < KOLOM &&
            labirin[x][y] == 1);
}

// Fungsi pencarian jalur dengan backtracking
bool cariJalur(int x, int y)
{
    // Jika sudah sampai tujuan
    if (x == BARIS - 1 && y == KOLOM - 1)
    {
        jalur[x][y] = 1;
        return true;
    }

    if (cekPosisi(x, y))
    {
        // Hindari mengunjungi posisi yang sama
        if (jalur[x][y] == 1)
            return false;

        jalur[x][y] = 1;

        // Coba bergerak ke bawah
        if (cariJalur(x + 1, y))
            return true;

        // Coba bergerak ke kanan
        if (cariJalur(x, y + 1))
            return true;

        // Coba bergerak ke atas
        if (cariJalur(x - 1, y))
            return true;

        // Coba bergerak ke kiri
        if (cariJalur(x, y - 1))
            return true;

        // Jika gagal, kembali (backtrack)
        jalur[x][y] = 0;
    }

    return false;
}

// Menampilkan hasil jalur yang ditemukan
void tampilkanJalur()
{
    cout << "\nMatriks Jalur Solusi:\n\n";

    for (int i = 0; i < BARIS; i++)
    {
        for (int j = 0; j < KOLOM; j++)
        {
            cout << jalur[i][j] << " ";
        }
        cout << endl;
    }
}

int main()
{
    cout << "Program Rat in a Maze Menggunakan Backtracking\n";

    if (cariJalur(0, 0))
    {
        tampilkanJalur();
    }
    else
    {
        cout << "Jalur menuju tujuan tidak ditemukan." << endl;
    }

    return 0;
}