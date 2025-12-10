#include <iostream>
using namespace std;

int maxim(int v[], int st, int dr) {
    if (st == dr) return v[st];

    int m = (st + dr) / 2;

    return max(maxim(v, st, m), maxim(v, m+1, dr));
}

int main () {
    int v[1001];
    int n;
    cin >> n;
    for (int i =0; i<n; i++)
        	cin >> v[i];

    cout << maxim(v, 0, n - 1);
}
