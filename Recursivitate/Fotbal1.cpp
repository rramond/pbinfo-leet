#include <iostream>

using namespace std;

const int N = 1000;

long long nr_s[N][N];

int nr_scor(int a, int b)
{
    if (nr_s[a][b] != 0)
    {
        return nr_s[a][b];
    }
    if (a == 0 || b == 0)
    {
        nr_s[a][b] = 1;
        return nr_s[a][b];
    }
    nr_s[a][b] = nr_scor(a - 1, b) + nr_scor(a, b - 1);
    return nr_s[a][b];
}

int main()
{
    int x, y;
    cin >> x >> y;
    cout << nr_scor(x, y) << "\n";
    return 0;
}
