#include <iostream>
#include <climits>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    unsigned long long needSword = 0;
    unsigned long long needArmor = 0;

    for (int i = 0; i < n; ++i) {
        unsigned long long res, pow;
        cin >> res >> pow;
        needSword += res;
        needArmor += pow;
    }

    int m;
    cin >> m;

    unsigned long long answer = ULLONG_MAX;

    for (int i = 0; i < m; ++i) {
        unsigned long long armor, sword, price;
        cin >> armor >> sword >> price;

        if (armor >= needArmor && sword >= needSword) {
            answer = min(answer, price);
        }
    }

    if (answer == ULLONG_MAX)
        cout << -1;
    else
        cout << answer;

    return 0;
}
