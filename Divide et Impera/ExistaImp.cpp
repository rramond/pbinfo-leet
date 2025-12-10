#include <iostream>
using namespace std;

bool existaImpare (int v[], int st, int dr) {
    if (st == dr) {
        return v[st] % 2 != 0;
    }
    int m = (st + dr) / 2;
    return (existaImpare(v, st, m) || existaImpare(v, m + 1, dr));
}

int main () {
    int n; cin >> n;
    int v[1001];
    for (int i = 0; i < n; i++) {  
        cin >> v[i];
    }
    cout << (existaImpare(v, 0, n - 1) ? "DA\n" : "NU\n");
    return 0;
}