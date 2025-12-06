#include <iostream>

using namespace std;

void baza_16(int n)
{
    if (n == 0)
    {
        return;
    }
    baza_16(n / 16);
    if (n % 16 < 10)
    {
        cout << n % 16;
    }
    else
    {
        cout << (char)(n % 16 - 10 + 'A');
    }
}

int main()
{
    int n;
    cin >> n;
    baza_16(n);
    return 0;
}
