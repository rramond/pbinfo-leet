#include <iostream>
#include <vector>
using namespace std;

//Se citește un număr natural n (n<16). Afișați în ordine lexicografică toate permutările mulțimii {1,2,…,n} în care elementele pare sunt puncte fixe (nu își schimbă poziția).

//Prima solutie a fost un brute-force. aveam un pct = 0 care era incrementat cu 1 de fiecare data cand gasea un punct fix in permutare. Apoi, daca pct == n/2, afisam permutarea. Raspunsurile erau corecte, dar generam toate n! permutari, ceea ce era ineficient pentru n=15 (15! = 1.3e12).

//Cu metoda curenta, stiind ca toate punctele fixe sunt elemente pare, putem sa le plasam direct in permutare, iar apoi sa generam doar permutarile pentru elementele impare. Astfel, vom genera doar (n/2)! permutari, ceea ce este mult mai eficient.

//eg. pt n = 16, cu 16! e 20 trilioane, dar (n/2)! = 8! = 40320, deci o diferenta astronomica.

int n;
vector<int> perm; //permutarea finala cu elementele pare deja plasate
vector<int> odds;  //vector cu elementele impare care trebuie permutate {1, 3, 5, ...}
vector<bool> used;

void afis() {
    for (int x : perm)
        cout << x << ' ';
    cout << '\n';
}

//slot reprezinta pozitia curenta in care trebuie sa punem un element impar = ce pozitie para umplem acm (0, 2, 4, ...)
void BKT(int slot) {
    if (slot >= n) { 
        afis();
        return;
    }
    for (int i = 0; i < (int)odds.size(); i++) {
        if (!used[i]) {
            used[i] = true;
            perm[slot] = odds[i]; //bagam elementul impar in slotul curent
            BKT(slot + 2);
            used[i] = false;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    perm.resize(n);

for (int i = 1; i < n; i += 2)
    perm[i] = i + 1; 

for (int i = 0; i < n; i += 2)
    odds.push_back(i + 1); 

    used.assign(odds.size(), false);

    BKT(0); 

    return 0;
}