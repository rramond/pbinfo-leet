// algoritmul lui Lee pentru gasirea celui mai scurt drum intr-o matrice 
#include <iostream>
#include <queue>
using namespace std;

// Dacă pentru fiecare k parcurgem toate elementele matricei labirint pentru a identifica elementele egale cu k, algoritmul de mai sus este neeficient.

// O soluție mult mai bună este să folosim o coadă:

// marcăm poziția de început cu 1 și o adăugăm în coadă
// expandăm coada. Cât timp coada este nevidă:
// scoatem din coadă un element, cu coordonatele (i,j)
// analizăm vecinii acestuia:
// dacă vecinul curent (iv,jv) este liber și nemarcat, îl marcăm în matrice cu o valoare mai mare cu 1 decât elementul (i,j) – A[iv][jv] = A[i][j] + 1; – și îl adăugăm în coadă.

int A[101][101], n, m;
int di[] = {-1, 0, 1, 0}; // deplasari pe linie
int dj[] = {0, 1, 0, -1}; // deplasari pe coloana

void Lee(int istart ,int jstart)
{
    queue<pair<int,int>> Q;
    //initializare coada
    Q.push(make_pair(istart , jstart));
    //marcare pozitie de start
    A[istart][jstart] = 1;
    while(! Q.empty()) // cat timp coada este nevida
    {   
        int i = Q.front().first, j = Q.front().second; // determinam elementul de la inceputul cozii
        for(int k = 0 ; k < 4 ; k ++)
        {
            int iv = i + di[k], jv = j + dj[k]; // coordonatele vecinului
            if(iv >= 1 && iv <= n && jv >= 1 && jv <= m // element în matrice
                && A[iv][jv] == 0) // element liber si nemarcat
            {
                // marcam elementul vecin cu o valoare mai mare
                A[iv][jv] = A[i][j] + 1;
                // il adaugam in coada
                Q.push(make_pair(iv , jv));
            }
        }
        Q.pop(); // eliminam din coada
    }
}

// Reconstruirea drumului

// În unele probleme se dau două poziții în matricea labirint, (istart,jstart) și (istop,jstop) și se cere determinarea celui mai scurt traseu de la poziția (istart,jstart) la poziția (istop,jstop).

// Operația se va realiza începând de la poziția finală spre cea inițială. Dacă poziția curentă a traseului are coordonatele (i,j), atunci poziția de dinainte va fi acel vecin (iv,jv) pentru care A[i][j] == A[iv][jv] + 1. Dacă sunt mai mulți asemenea vecini, oricare dintre ei este corect.

// Solutie 1:  Recursiv
void Traseu(int i, int j , int lg)
{
    if(A[i][j] == 1)
    {
        cout << lg << "\n";
        cout << i << " " << j << "\n";
    }
    else
    {
        int p = -1;
        for(int k = 0 ; k < 4 && p == -1 ; k ++)
            if(A[i][j] == A[i+di[k]][j+dj[k]] + 1)
                p = k;
        Traseu(i + di[p] , j + dj[p] , lg + 1);
        cout << i << " " << j << "\n";
    }
}

// Solutie 2: Iterativ

void Traseu2(int istop, int jstop)
{
    vector<pair<int,int>> V;
    int i = istop , j = jstop;
    V.push_back(make_pair(i , j));
    do
    {
        int p = -1;
        for(int k = 0 ; k < 4 && p == -1 ; k ++)
            if(A[i][j] == A[i+di[k]][j+dj[k]] + 1)
                p = k;
        i = i + di[p] , j = j + dj[p];
        V.push_back(make_pair(i , j));
    }
    while(A[i][j] != 1);
    cout << V.size() << '\n';
    for(vector<pair<int,int>>::reverse_iterator I = V.rbegin() ; I != V.rend() ; I ++)  // parcurgem vectorul invers
        cout << I->first << " " << I->second << '\n';
}