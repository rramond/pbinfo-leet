#include <iostream>
using namespace std;

//am pus-o aici pt ca prima incercare am inteles ca voia numere a caror prima cifra e minima dintre cifrele ACELUIASI numar

//pbinfo ar trebui sa adauge mai multe test cases la vedere si mai diversificate
//FREAKING BUMS

int getFirstDigit(int x) {
    while (x >= 10) {
        x /= 10;
    }
    return x;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n, x;
    cin >> n;
    
    int minFirstDigit = 10;  
    int max = 0;
    
    for (int i = 0; i < n; i++) {
        cin >> x;
        int firstDigit = getFirstDigit(x);
        
        if (firstDigit < minFirstDigit || (firstDigit == minFirstDigit && x > max)) {
            minFirstDigit = firstDigit;
            max = x;
        }
    }
    
    cout << max << endl;
    
    return 0;
}