#include <iostream>
using namespace std;

int suma(int v[], int st, int dr) {
    if (st == dr) return v[st];

    int m = (st + dr) / 2;

    return (suma(v, st, m) + suma(v, m+1, dr));
}

int main () {
    int v[1001];
    int n;
    cin >> n;
    for (int i =0; i<n; i++)
        	cin >> v[i];

    cout << suma(v, 0, n - 1);
}
