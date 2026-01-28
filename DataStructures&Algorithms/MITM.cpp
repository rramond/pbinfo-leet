// MITM = Meet In The Middle
// Este un algoritm utilizat pentru a rezolva probleme de combinatorică și optimizare
// prin împărțirea problemei în două părți mai mici, rezolvarea fiecărei părți
// separat și combinarea rezultatelor pentru a obține soluția finală.

// exemplu: gasirea subsirului cu cea mai mare suma, mai mica decat o valoara data s (pb 4266)
// Împărțim șirul în două jumătăți:

// prima jumătate: ~ n/2 elemente

// a doua jumătate: restul

// Pentru fiecare jumătate:
//  -> generăm toate sumele posibile (2^(n/2) ≈ 2^20 ≈ 1.000.000 → OK)
// Apoi:
//  -> sortăm sumele din a doua jumătate
//  -> pentru fiecare sumă din prima jumătate, căutăm (binary search) cea mai mare sumă din a doua astfel încât:
//      [sum1 + sum2 ≤ s]
// La final, luăm maximul.

// Timp: O(2^(n/2) log 2^(n/2))
// Memorie: O(2^(n/2)) 

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n;
    long long s;
    cin >> n >> s;

    vector<long long> a(n);
    for(int i = 0; i < n; i++)
        cin >> a[i];

    int m = n / 2;

    vector<long long> left, right;

    // sume prima jumătate
    for(int mask = 0; mask < (1 << m); mask++) {
        long long sum = 0;
        for(int i = 0; i < m; i++)
            if(mask & (1 << i))
                sum += a[i];
        if(sum <= s) left.push_back(sum);
    }

    // sume a doua jumătate
    for(int mask = 0; mask < (1 << (n - m)); mask++) {
        long long sum = 0;
        for(int i = 0; i < n - m; i++)
            if(mask & (1 << i))
                sum += a[m + i];
        if(sum <= s) right.push_back(sum);
    }

    sort(right.begin(), right.end());

    long long best = 0;

    for(long long x : left) {
        long long need = s - x;
        auto it = upper_bound(right.begin(), right.end(), need);
        if(it != right.begin()) {
            --it;
            best = max(best, x + *it);
        }
    }

    cout << best;
}

// Se poate generaliza pentru alte probleme de tip optimizare unde putem împărți problema în două părți independente
// și putem combina soluțiile parțiale pentru a obține soluția globală.
// Exemple includ probleme de tip knapsack, probleme de grafuri și altele.
// Pașii generali sunt:
// 1. Împărțirea problemei în două părți independente.
// 2. Generarea tuturor soluțiilor posibile pentru fiecare parte.
// 3. Stocarea și sortarea soluțiilor pentru una dintre părți.
// 4. Combinarea soluțiilor folosind tehnici eficiente (de exemplu căutare binară) pentru a găsi soluția optimă globală.

// Această tehnică este deosebit de utilă atunci când dimensiunea problemei este prea mare pentru a fi rezolvată
// prin metode brute-force directe, dar poate fi redusă semnificativ prin împărțirea în două părți.
// Timpul de execuție și utilizarea memoriei depind de natura specifică a problemei și de modul în care sunt generate
// și combinate soluțiile parțiale.

// Complexitatea tipică este O(2^(n/2) * log(2^(n/2))) pentru timpul de execuție și O(2^(n/2)) pentru memorie.
// Aceasta face ca tehnica Meet In The Middle să fie fezabilă pentru valori de n până la aproximativ 40,
// unde metodele brute-force directe ar fi ineficiente.

// Notă: Este important să se asigure că cele două părți ale problemei sunt independente,
// astfel încât soluțiile generate pentru fiecare parte să poată fi combinate corect.