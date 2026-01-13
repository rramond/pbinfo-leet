#include <iostream>
#include <vector>
using namespace std;

// 60% 2 fatal signal 11 work in progress


vector<int> memo;

int Fib(int n) {
    if (n <= 2) return 1;
    if (memo[n] != -1) return memo[n];
    
    memo[n] = (Fib(n-1) + Fib(n-2)) % 666013;
    return memo[n];
}

int main() {
    int n;
    cin >> n;
    
    memo.assign(n + 1, -1);
    
    cout << Fib(n);
    
    return 0;
}