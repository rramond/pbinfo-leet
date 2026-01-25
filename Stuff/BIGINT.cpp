#include <iostream>
#include <vector>
using namespace std;
 
 
 // Hardware can only store numbers so big (int - 9 digits, long long - 18 digits), but for problems that require handling of really big numbers (factorials, combinatorics, etc.), we need to implement our own BIGINT class that can handle arbitrarily large integers by storing them in arrays or strings and implementing arithmetic operations manually.

// Addition -> O(n) where n is the number of digits in the larger number
vector<int> add(vector<int> a, vector<int> b) {
    vector<int> res;
    int carry = 0;

    for (int i = 0; i < max(a.size(), b.size()) || carry; i++) {
        int sum = carry;
        if (i < a.size()) sum += a[i];
        if (i < b.size()) sum += b[i];
        res.push_back(sum % 10);
        carry = sum / 10;
    }
    return res;
}

// Subtraction -> O(n) assuming a >= b, , MUST STRIP LEADING ZEROS BEFORE USING
vector<int> subtract(vector<int> a, vector<int> b) {
    int borrow = 0;
    for (int i = 0; i < a.size(); i++) {
        int cur = a[i] - borrow - (i < b.size() ? b[i] : 0);
        if (cur < 0) {
            cur += 10;
            borrow = 1;
        } else {
            borrow = 0;
        }
        a[i] = cur;
    }

    while (a.size() > 1 && a.back() == 0)
        a.pop_back();

    return a;
}

// Multiplication -> O(n*m) where n and m are the number of digits in a and b respectively
// Can be optimized using Karatsuba algorithm to O(n^log2(3)) ~ O(n^1.585)
vector<int> multiply(vector<int> a, vector<int> b) {
    vector<int> res(a.size() + b.size(), 0);

    for (int i = 0; i < a.size(); i++) {
        int carry = 0;
        for (int j = 0; j < b.size() || carry; j++) {
            long long cur = res[i + j] + a[i] * 1LL * (j < b.size() ? b[j] : 0) + carry;
            res[i + j] = cur % 10;
            carry = cur / 10;
        }
    }

    while (res.size() > 1 && res.back() == 0)
        res.pop_back();

    return res;
}

// Division -> O(n^2) where n is the number of digits in a
vector<int> divide(vector<int> a, int b) {
    vector<int> res(a.size());
    long long rem = 0;

    for (int i = a.size() - 1; i >= 0; i--) {
        rem = rem * 10 + a[i];
        res[i] = rem / b;
        rem %= b;
    }

    while (res.size() > 1 && res.back() == 0)
        res.pop_back();

    return res;
}

