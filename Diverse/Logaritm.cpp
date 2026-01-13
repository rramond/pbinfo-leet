

//UNA INTERESANTA. IMPLEMENTARE A LOGARITMULUI NATURAL FARA A FOLOSI FUNCTII PREDEFINITE

//WORK IN PROGRESS



#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

const double EPSILON = 1e-10;
const int MAX_ITERATIONS = 100;
const double LN2 = 0.693147180559945309417;  // Pre-calculated ln(2)

double ln_custom(double n) {
    if (n <= 0) {
        cout << "Error: ln is undefined for n <= 0" << endl;
        return -1;
    }
    if (n == 1.0) return 0.0;
    
    // Normalize using ln(n) = ln(n/2^k) + k*ln(2)
    int k = 0;
    while (n > 1.5) {
        n /= 2.0;
        k++;
    }
    while (n < 0.5) {
        n *= 2.0;
        k--;
    }
    
    // Use series: ln((1+x)/(1-x)) = 2(x + x³/3 + x⁵/5 + ...)
    double x = (n - 1.0) / (n + 1.0);
    double x_squared = x * x;
    double result = 0.0;
    double term = x;
    
    for (int i = 1; i < MAX_ITERATIONS; i += 2) {
        double contribution = term / i;
        result += contribution;
        
        if (abs(contribution) < EPSILON)
            break;
        
        term *= x_squared;
    }
    
    result *= 2.0;
    result += k * LN2;
    
    return result;
}

int main() {
    double x;
    cin >> x;
    
    cout << fixed << setprecision(6) << ln_custom(x);
    
    
    
    return 0;
}