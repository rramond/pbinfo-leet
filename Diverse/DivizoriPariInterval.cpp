#include <iostream>
using namespace std;

//interesanta logica la problema asta, kinda fun


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int a, b, ndr, ndrMAX = 0;
    cin >> a >> b;
    int minVal = 0, maxVal = 0;
    
    for (int i = a; i <= b; i++){
        ndr = 0;
        if (i % 2 == 0){
            for (int d = 1; d * d <= i; d++){
                if (i % d == 0){
                    if (d % 2 == 0) {
                        ndr++; 
                    }
                    if (d != i / d && (i / d) % 2 == 0) {
                        ndr++;  
                    }
                }
            }
        }
        
        if (ndr > ndrMAX) {
            ndrMAX = ndr;
            minVal = i; 
            maxVal = i;  
        } else if (ndr == ndrMAX && ndr > 0) {
            maxVal = i; 
        }
    }
    
    cout << ndrMAX << " " << minVal << " " << maxVal << endl; 
}