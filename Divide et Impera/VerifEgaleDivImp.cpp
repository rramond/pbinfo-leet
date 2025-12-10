#include <iostream>
using namespace std;

bool toateEgale (int v[], int st, int dr) {
    if (st == dr) {
        return true;
    }
    int m = (st + dr) / 2;
    return (toateEgale(v, st, m) && toateEgale(v, m + 1, dr) && v[st] == v[dr]);
}

int main () {
    int n; cin >> n;
    int v[1001];
    for (int i = 0; i < n; i++) {  
        cin >> v[i];
    }
    cout << (toateEgale(v, 0, n - 1) ? "DA\n" : "NU\n");
    return 0;
}