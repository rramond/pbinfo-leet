// cfira de control se obtine prin calcularea sumei cifrelor unui numar, apoi a numarului format s.a.m.d pana se ajunge la un nr de o singura cifra.

// restul impartirii unui nr la 9 este egal cu suma cifrelor acelui nr impartit la 0


#include <iostream>
using namespace std;

int main() {
    long long n;
    cin >> n;

    if (n == 0) cout << 0;
    else cout << 1 + (n - 1) % 9;

    return 0;
}