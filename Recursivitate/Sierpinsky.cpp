#include <iostream>
#include <fstream>
#include <cmath>
#include <bitset>
using namespace std;

ifstream fin("sierpinski.in");
ofstream fout("sierpinski.out");

const short int N = 729; // 3^6

const int ND = 9; // nr de deplasari
//vestori de deplasari
const int DL[ND] = {0, -1, -1, -1,  1, 1, 1, 0, 0};
const int DC[ND] = {0, -1,  0,  1, -1, 0, 1, -1, 1};

//bool a[N][N];
bitset<N> a[N];


void Sierpinski(int l, int c, int lat, bool plin)
{
    // Cazul de baza
    if (lat == 1)
    {
        a[l][c] = plin;
        return;
    }
    lat /= 3;

    for(int i = 0; i < ND; i++) {
        if (i == 0){
            Sierpinski(l + DL[i] * lat, c + DC[i] * lat, lat, true);
            continue;
        }
        Sierpinski(l + DL[i] * lat, c + DC[i] * lat, lat, plin);
    }
}


int main () {  
    int n;
    fin >> n;
    int lat = pow(3, n);
    Sierpinski(lat/2, lat/2, lat, false);
    for (int i = 0; i < lat; i++)
    {
        for (int j = 0; j < lat; j++)
        {
            fout << a[i][j] << " ";
        }
        fout << "\n";
    }

    fin.close();
    fout.close();
    return 0;
}