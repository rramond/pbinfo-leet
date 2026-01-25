// Karatsuba Big Integer Multiplication in C++

#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

// Algorithm explanation:
// The Karatsuba algorithm is a divide-and-conquer algorithm for multiplying large integers. It reduces the multiplication of two n-digit numbers to at most three multiplications of n/2-digit numbers, which is more efficient than the traditional O(n^2) multiplication method.
// The basic idea is to split each number into two halves and use the following formula:
// Let x = a * 10^m + b
// Let y = c * 10^m + d
// Then, x * y = ac * 10^(2m) + ((a + b)(c + d) - ac - bd) * 10^m + bd
// This reduces the number of multiplications needed.
// The time complexity of the Karatsuba algorithm is O(n^log2(3)) which is approximately O(n^1.585).

// Implementation of Karatsuba algorithm

vector<int> add(const vector<int>& a, const vector<int>& b) {
    vector<int> res(max(a.size(), b.size()) + 1, 0);
    int carry = 0;
    for (int i = 0; i < res.size(); i++) {
        int digitA = (i < a.size()) ? a[i] : 0;
        int digitB = (i < b.size()) ? b[i] : 0;
        int sum = digitA + digitB + carry;
        res[i] = sum % 10;
        carry = sum / 10;
    }
    while (res.size() > 1 && res.back() == 0)
        res.pop_back();
    return res;
}

vector<int> subtract(const vector<int>& a, const vector<int>& b) {
    vector<int> res(a.size(), 0);
    int borrow = 0;
    for (int i = 0; i < a.size(); i++) {
        int digitA = a[i];
        int digitB = (i < b.size()) ? b[i] : 0;
        int sub = digitA - digitB - borrow;
        if (sub < 0) {
            sub += 10;
            borrow = 1;
        } else {
            borrow = 0;
        }
        res[i] = sub;
    }
    while (res.size() > 1 && res.back() == 0)
        res.pop_back();
    return res;
}

vector<int> karatsuba(const vector<int>& x, const vector<int>& y) {
    int n = max(x.size(), y.size());
    if (n <= 32) { // base case for small numbers
        vector<int> res(x.size() + y.size(), 0);
        for (int i = 0; i < x.size(); i++) {
            int carry = 0;
            for (int j = 0; j < y.size() || carry; j++) {
                long long cur = res[i + j] + x[i] * 1LL * (j < y.size() ? y[j] : 0) + carry;
                res[i + j] = cur % 10;
                carry = cur / 10;
            }
        }
        while (res.size() > 1 && res.back() == 0)
            res.pop_back();
        return res;
    }

    int m = n / 2;

    vector<int> a(x.begin(), x.begin() + min((int)x.size(), m));
    vector<int> b(x.begin() + min((int)x.size(), m), x.end());
    vector<int> c(y.begin(), y.begin() + min((int)y.size(), m));
    vector<int> d(y.begin() + min((int)y.size(), m), y.end());

    vector<int> ac = karatsuba(a, c);
    vector<int> bd = karatsuba(b, d);

    vector<int> a_plus_b = add(a, b);
    vector<int> c_plus_d = add(c, d);
    vector<int> ab_cd = karatsuba(a_plus_b, c_plus_d);
    vector<int> ad_plus_bc = subtract(subtract(ab_cd, ac), bd);

    vector<int> res(ac.size() + 2 * m, 0);
    for (int i = 0; i < ac.size(); i++)
        res[i + 2 * m] += ac[i];
    for (int i = 0; i < ad_plus_bc.size(); i++)
        res[i + m] += ad_plus_bc[i];
    for (int i = 0; i < bd.size(); i++)
        res[i] += bd[i];

    // Handle carry
    int carry = 0;
    for (int i = 0; i < res.size(); i++) {
        res[i] += carry;
        carry = res[i] / 10;
        res[i] %= 10;
    }
    while (res.size() > 1 && res.back() == 0)
        res.pop_back();
    return res;
}

int main() {
    string strX, strY;
    cout << "Enter first large integer: ";
    cin >> strX;
    cout << "Enter second large integer: ";
    cin >> strY;

    vector<int> x, y;
    for (int i = strX.size() - 1; i >= 0; i--)
        x.push_back(strX[i] - '0');
    for (int i = strY.size() - 1; i >= 0; i--)
        y.push_back(strY[i] - '0');

    vector<int> result = karatsuba(x, y);

    cout << "Product: ";
    for (int i = result.size() - 1; i >= 0; i--)
        cout << result[i];
    cout << endl;

    return 0;
}
