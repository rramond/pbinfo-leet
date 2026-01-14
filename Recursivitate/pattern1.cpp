#include <iostream>
using namespace std;

const int N = 512;

const int ND = 4; // nr de deplasari
const int DL[ND] = {-1, -1, 1, 1};
const int DC[ND] = {-1, 1, -1, 1};

int a[N][N];

void pattern1(int l , int c, int n) {
    
    if(n == 0) {
        return;
    }
    // caz de baza
    a[l][c] = n--;
    int dist = 1 << (n-1);
    
//     //stanga sus
//     pattern1(l-dist, c-dist, n);
//     //dreapta sus
//     pattern1(l-dist, c + dist, n);
//     //stanga jos
//     pattern1(l + dist, c-dist, n);
//     //dreapta jos
//     pattern1(l + dist, c + dist, n);
// 


//Modalitate cu apeluri in for

    for(int d = 0; d < ND; d++) {
        pattern1(l + DL[d] * dist, c + DC[d] * dist, n);
    }
}
// ia valoarea x-- inseamna ca ia val x si apoi decrementeaza x, iar --x decrementeaza x si apoi ia valoarea

int main() {
    int n;
    cin >> n;
    int dim = (1 << n) - 1; // 2^n - 1
    pattern1(dim/2, dim/2, n);

    for(int i = 0; i < dim; i++) {
        for(int j = 0; j < dim; j++) {
            cout << a[i][j] << " "; 
        }
        cout << "\n";
    }

    return 0;
}