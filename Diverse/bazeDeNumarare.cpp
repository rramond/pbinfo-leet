#include <iostream>
#include <string>
using namespace std;
// bazam numeratie b, b>10 => folosim cifrele 0, 1, ... b;

//daca baza de numeratie b, este b > 10, trebuie sa facem o conventie pentru cifrele >= 10
//eg: A=10, B=11, ....

// baza 10 | baza 2 | baza 3
//    0        0        0
//    1        1        1
//    2       10        2
//    3       11       10
//    4      100       11
//    5      101       12
//    6      110       20
//    7      111       21
//    8      1000      22
//    9      1001      100
//   10      1010      101


// succesor x -> parsare dreapta-stanga, cautand cel mai mic i cu Ci < b-1
// daca exista, incrementam Ci si setam toate Cj cu j>i la 0
// daca nu exista, atunci x este de forma b-1, b-1, ..., b-1 => succesorul este 1, 0, 0, ..., 0 (cu n+1 cifre)

// eg: x = 3125555 (b=6)
//     x+1 = 3130000 (b=6)

// eg2: x = 55555 (b=6)
//      x+1 = 100000 (b=6)


//npredecsor x -> parsare dreapta-stanga, cautand cel mai mic i cu Ci > 0
// daca exista, decrementam Ci si setam toate Cj cu j>i la b-1
// daca nu exista, atunci x este de forma 0, 0, ..., 0 => nu are predecesor

// exemplu: cifrele lui x sunt in c[0..n-1], c[0] = cifra cea mai semnificativa
// eg: x = 3125555 (b=6) -> c = {3,1,2,5,5,5,5}, n = 7

void succesor(int c[], int &n, int b) {
    int i = n - 1;
    while (i >= 0 && c[i] == b - 1)
        c[i--] = 0;                 // cifrele b-1 devin 0 (transport)
    if (i >= 0)
        c[i]++;
    else {                          // x = b-1 b-1 ... b-1 => 1 0 0 ... 0
        for (int j = n; j > 0; j--) c[j] = 0;
        c[0] = 1;
        n++;
    }
}

bool predecesor(int c[], int &n, int b) {
    int i = n - 1;
    while (i >= 0 && c[i] == 0)
        c[i--] = b - 1;             // cifrele 0 devin b-1 (imprumut)
    if (i < 0) return false;        // x = 0 => nu are predecesor
    c[i]--;
    if (c[0] == 0 && n > 1) {       // eg: 1000 (b=2) -> 0111 => eliminam zeroul din fata
        for (int j = 0; j < n - 1; j++) c[j] = c[j + 1];
        n--;
    }
    return true;
}

//douaebaze pb#946
// orice nr de 2 cifre in baza 2 (orice grup de 2 cifre binare pe pozitii consecutive) corespunde unei cifre din baza 4
//  00 -> 0
//  01 -> 1
//  10 -> 2
//  11 -> 3

void doubabaze(string& sb2){
    int nrCif = (int)sb2.length();
    int pc = 0;
    if(nrCif % 2 != 0){
        cout << sb2[0];
        pc++;
    }
    for(int i = pc; i < nrCif; i += 2){
        int cif4 = 0;
        if(sb2[i] == '1') cif4 += 2;
        if(sb2[i+1] == '1') cif4 += 1;
        cout << cif4;
    }
}





