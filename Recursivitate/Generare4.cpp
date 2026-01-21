#include <iostream>
#include <vector>
using namespace std;

#include <iostream>
#include <vector>
using namespace std;

// Versiune RECURSIVĂ
vector<int> construieste_sir(int n) {
    // Caz de bază: n = 1
    if (n == 1) {
        return {1, 2};
    }
    
    // Pas recursiv: obținem șirul pentru n-1
    vector<int> sir_anterior = construieste_sir(n - 1);
    
    // Calculăm câte numere trebuie să inserăm: 2^(n-1)
    int count = 1 << (n - 1); // 2^(n-1)
    
    // Primul număr de inserat este 2^(n-1) + 1
    // (deoarece șirul anterior conține primele 2^(n-1) numere)
    int next_num = (1 << (n - 1)) + 1;
    
    // Calculăm poziția de mijloc
    int mijloc = sir_anterior.size() / 2;
    
    // Construim noul șir
    vector<int> sir_nou;
    
    // Prima jumătate din șirul anterior
    for (int i = 0; i < mijloc; i++) {
        sir_nou.push_back(sir_anterior[i]);
    }
    
    // Inserăm numerele noi
    for (int i = 0; i < count; i++) {
        sir_nou.push_back(next_num + i);
    }
    
    // A doua jumătate din șirul anterior
    for (int i = mijloc; i < sir_anterior.size(); i++) {
        sir_nou.push_back(sir_anterior[i]);
    }
    
    return sir_nou;
}

void afiseaza_sir(const vector<int>& sir) {
    for (int i = 0; i < sir.size(); i++) {
        cout << sir[i];
        if (i < sir.size() - 1) cout << " ";
    }
    cout << endl;
}      
int main() {
    int n;
    cin >> n;
    afiseaza_sir(construieste_sir(n));
    
    
}