#include <iostream>

using namespace std;

void hanoi(int n, char sursa, char dest, char aux)
{
    if (n == 1)
    {
        cout << sursa << "->" << dest << "\n";
        return;
    }
    hanoi(n - 1, sursa, aux, dest);
    hanoi(1, sursa, dest, aux);
    hanoi(n - 1, aux, dest, sursa);
}

int main()
{
    int n;
    cin >> n;
    cout << (1 << n) - 1 << "\n";
    hanoi(n, 'A', 'C', 'B');
    return 0;
}

