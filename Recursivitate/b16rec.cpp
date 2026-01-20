#include <iostream>
#include <cstring>
using namespace std;

long long val(char c) {
    if (c >= '0' && c <= '9')
        return c - '0';
    return c - 'A' + 10;
}

long long baza16(char s[], int n) {
    if (n == 0)
        return 0;
    return baza16(s, n - 1) * 16 + val(s[n - 1]);
}

int main() {
    char n[25];
    cin >> n;
    cout << baza16(n, strlen(n));
    return 0;
}
