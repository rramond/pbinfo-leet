#include <iostream>
#include <cstdlib>
using namespace std;

const int N = 10; // Dimensiunea maxima a solutiei

int n, sol[N];
bool col[N], DP[N], DS[N];

void afisare(){
    for(int i = 0; i < n; i++){
        for(int j = 0; j < sol[i]; j++){
            cout << "- ";
        }
        cout << "* ";
        for(int j = sol[i] + 1; j < n; j++){
            cout << "- ";
        }
        cout << '\n';
    }
    exit(0);
}
		

void back(int k) {
    if (k == n) {
        afisare();
        return;
    }

    for (int i = 0; i < n; i++) {
        if (!col[i] && !DP[k + i] && !DS[k - i + n]) {
            sol[k] = i;
            col[i] = DP[k + i] = DS[k - i + n] = true;
            back(k + 1);
            col[i] = DP[k + i] = DS[k - i + n] = false;
        }
    }
}


int main() {

    cin >> n;
    back(0);
    return 0;

}