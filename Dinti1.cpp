#include <iostream>

using namespace std;

long long dinti(int n)
{
    if (n == 0)
    {
        return 0;
    }
    return 2 * dinti(n - 1) + n;
}

int main()
{
    int n;
    cin >> n;
    cout << dinti(n) << "\n";
    return 0;
}
