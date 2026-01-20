#include <iostream>
#include <vector>
#include <climits>
using namespace std;

// 1D array prefix sum to find the interval with the maximum sum over m queries

int main() {
    int n;
    cin >> n;

    vector<long long> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    vector<long long> pref(n + 1, 0);
    for (int i = 1; i <= n; i++)
        pref[i] = pref[i - 1] + arr[i - 1];

    int m;
    cin >> m;

    long long maxS = LLONG_MIN;

    for (int k = 0; k < m; k++) {
        int i, j;
        cin >> i >> j;

        long long S = pref[max(i, j)] - pref[min(i, j) - 1];
        if (S > maxS) maxS = S;
    }
    cout << maxS;
    return 0;
}
