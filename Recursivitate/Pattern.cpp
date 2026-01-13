#include <iostream>

using namespace std;

const int N = 1024;
// Matricea pentru pattern
bool a[N][N];

void pattern(int l, int c, int lat, bool plin)
{
    // Cazul de baza
    if (lat == 1)
    {
        a[l][c] = plin;
        return;
    }
    lat /= 2;
    // Partea centrala este goala
    pattern(l, c, lat, true);
    // Celelalte 3 parti sunt pline
    pattern(l, c + lat, lat, plin);
    pattern(l + lat, c, lat, plin);
    pattern(l + lat, c + lat, lat, plin);
}

int main()
{
    int n;
    cin >> n;
    int lat = 1 << n;
    pattern(0, 0, lat, false);
    for (int i = 0; i < lat; i++)
    {
        for (int j = 0; j < lat; j++)
        {
            cout << a[i][j] << " ";
        }
        cout << "\n";
    }
    return 0;
}
