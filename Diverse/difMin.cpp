#include <iostream>
using namespace std;

// ts like PrimaCifraMinima but more tuff

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n, x, y;
    cin >> n;
    
    cin >> x;
    int bestx, besty;
    int difMin = 2000000000;
    int sumMin = 2000000000;
    for (int i = 1; i < n; i++) {
        cin >> y;
        
        if (abs(x-y) < difMin || (abs(x-y) == difMin && (x+y) < sumMin)) {
            difMin = abs(x-y);
            sumMin = x+y;
            bestx = x;
            besty = y;
        }
        x = y;
    }
    
    cout << bestx << " " << besty << endl;
    
    return 0;
}