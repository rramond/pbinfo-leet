#include <iostream>
#include <vector>
using namespace std;

// 60% 2 fatal signal 11 work in progress

// We're gonna solve this using matrix multiplication and exponentiation by squaring to quickly 
// compute the nth fibonacci recurrent term in O(log n) time.

typedef long long ll;
typedef vector<vector<ll>> Matrix; 

const ll MOD =  666013;  // modulo cerut de problema

Matrix multiply(const Matrix &A, const Matrix &B, int mod = MOD){
            int n = A.size();
            int m = B[0].size();
            int p = B.size();

            Matrix C(n, vector<ll> (m, 0));
            for(int i = 0; i < n; i++){
                for(int j = 0; j < m; j++){
                    for(int k = 0; k < p; k++){
                        C[i][j] = (C[i][j] + A[i][k] * B[k][j]) % mod;
                    }
                }
            }
            return C;
}

Matrix exponentiation(Matrix M, ll n, int mod = MOD){
    int size = M.size();
    Matrix result(size, vector<ll>(size, 0));

    // Initialize result as identity matrix. 
      for(int i = 0; i < size; i++)
        result[i][i] = 1;

    while(n > 0){
        if(n & 1)  // if n is odd == if n's least significant bit is 1
            result = multiply(result, M, mod);
        M = multiply(M, M, mod);
        n >>= 1;   // n = n / 2 // right shift by 1
    }
    return result;
}

// Apply everything to get the nth fibonacci number

ll fibonacci(ll n){
    if(n == 0) return 0;
    if(n == 1 || n == 2) return 1;

    Matrix F = {{1, 1},
                {1, 0}};
    
    Matrix result = exponentiation(F, n - 1, MOD);
    return result[0][0]; // F(n) is located at position (0, 0) in the resulting matrix
}

int main() { 
    ll n;
    cin >> n;
    cout << fibonacci(n);
}