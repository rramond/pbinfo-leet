#include <iostream>
#include <vector>
using namespace std;

// Stars and Bars Theorem
// The number of ways to put n indistinguishable balls into k distinguishable boxes is C(n + k - 1, k - 1)
// the balls are the stars and the dividers between different boxes are the bars.
// *||*|** represents putting 1 ball in the first box, 0 in the second, and 2 in the third box.

// If we had to have at least 1 ball in each box, we would first place 1 ball in each box (using k balls), and then distribute the remaining n - k balls freely.
// Thus, the number of ways would be C((n - k) + k - 1, k - 1) = C(n - 1, k - 1)

// combinarea explodeaza foarte repede (peste long long) si pt 100 de cutii, deci trebuie sa folosim inmultirea si impartirea pe big integer 


// big integer: least significant digit first
vector<int> multiply(vector<int> a, int b) {
    int carry = 0;
    for (int i = 0; i < a.size(); i++) {
        int x = a[i] * b + carry;
        a[i] = x % 10;
        carry = x / 10;
    }
    while (carry) {
        a.push_back(carry % 10);
        carry /= 10;
    }
    return a;
}

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

int main() {
    int n, k;
    cin >> n >> k;

    int N = n + k - 1;
    int K = k - 1;
    if (K > N - K) K = N - K;

    vector<int> result(1, 1);

    for (int i = 1; i <= K; i++) {
        result = multiply(result, N - K + i);
        result = divide(result, i);
    }

    for (int i = result.size() - 1; i >= 0; i--)
        cout << result[i];
}

