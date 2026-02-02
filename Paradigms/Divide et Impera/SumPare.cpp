#include <iostream>
using namespace std;

int sumPare(int v[], int st, int dr) {
    if (st == dr)
        if(v[st]%2==0) return v[st];
        else return 0;

    int m = (st + dr) / 2;

        return sumPare(v, st, m) + sumPare(v, m+1, dr);
}

int main () {
    int v[1001];
    int n;
    cin >> n;
    for (int i =0; i<n; i++)
        	cin >> v[i];

    cout << sumPare(v, 0, n - 1);
}
