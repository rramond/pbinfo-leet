#include <iostream>

using namespace std;

int putere(int a, int n, int p)
{
    if (n == 1)
    {
        return a;
    }
    int r = putere((long long)a * a % p, n / 2, p);
    if (n % 2 != 0)
    {
        r = (long long)r * a % p;
    }
    return r;
}

int main()
{
    int a, n, k;
    cin >> a >> n >> k;
    int p = 1;
    for (int i = 0; i < k; i++)
    {
        p *= 10;
    }
    cout << putere(a, n, p) << "\n";
    return 0;
}
