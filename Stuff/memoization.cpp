// memoization is a technique used to optimize functions by caching the results of expensive function calls
// and returning the cached result when the same inputs occur again.

// problem examples:

// 1. staircase problem: Given n stairs, find the number of distinct ways to reach the top,
//    taking either 1 or 2 steps at a time.

#include <iostream>
#include <vector>
using namespace std;

int climbStairs(int n, vector<int>& memo) {
    if (n <= 1) return 1; // base case

    if (memo[n] != -1) return memo[n]; // return cached result if exists

    // compute and cache the result
    memo[n] = climbStairs(n - 1, memo) + climbStairs(n - 2, memo);
    return memo[n];
}

int main() {
    int n;
    cout << "Enter number of stairs: ";
    cin >> n;
    vector<int> memo(n + 1, -1); // initialize memo with -1
    cout << "Number of ways to climb " << n << " stairs: " << climbStairs(n, memo) << endl;
    return 0;
}

// 2. The egg dropping problem: Given n eggs and k floors, find the minimum number of attempts
//    needed in the worst case to find the highest floor from which an egg can be dropped without breaking.
//    an egg breaks if it falls from a certain floor or higher.
//    if an egg doesn't break when dropped from a floor, it will not break from any floor below that.

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int eggDrop(int n, int k, vector<vector<int>>& memo) {
    if (k == 0 || k == 1) return k; // base cases
    if (n == 1) return k; // if only one egg, need to try all floors

    if (memo[n][k] != -1) return memo[n][k]; // return cached result if exists

    int minAttempts = INT_MAX;

    for (int x = 1; x <= k; x++) {
        int breaks = eggDrop(n - 1, x - 1, memo); // egg breaks
        int survives = eggDrop(n, k - x, memo);   // egg survives
        int worstCase = 1 + max(breaks, survives); // worst case attempts

        minAttempts = min(minAttempts, worstCase);
    }

    memo[n][k] = minAttempts; // cache the result
    return minAttempts;
}

int main() {
    int n, k;
    cout << "Enter number of eggs: ";
    cin >> n;
    cout << "Enter number of floors: ";
    cin >> k;

    vector<vector<int>> memo(n + 1, vector<int>(k + 1, -1)); // initialize memo with -1
    cout << "Minimum number of attempts in worst case: " << eggDrop(n, k, memo) << endl;
    return 0;
}

// 3. longest common subsequence (LCS) problem: Given two strings, find the length of their longest common subsequence.
#include <iostream>
#include <vector>
#include <string>
using namespace std;

int lcs(const string& X, const string& Y, int m, int n, vector<vector<int>>& memo) {
    if (m == 0 || n == 0) return 0; // base case

    if (memo[m][n] != -1) return memo[m][n]; // return cached result if exists

    if (X[m - 1] == Y[n - 1]) {
        memo[m][n] = 1 + lcs(X, Y, m - 1, n - 1, memo); // characters match
    } else {
        memo[m][n] = max(lcs(X, Y, m, n - 1, memo), lcs(X, Y, m - 1, n, memo)); // characters don't match
    }

    return memo[m][n];
}

int main() {
    string X, Y;
    cout << "Enter first string: ";
    cin >> X;
    cout << "Enter second string: ";
    cin >> Y;

    int m = X.length();
    int n = Y.length();
    vector<vector<int>> memo(m + 1, vector<int>(n + 1, -1)); // initialize memo with -1

    cout << "Length of Longest Common Subsequence: " << lcs(X, Y, m, n, memo) << endl;
    return 0;
}