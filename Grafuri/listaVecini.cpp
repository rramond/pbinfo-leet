
#include <fstream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

int main() {
    ifstream fin("listavecini.in");
    ofstream fout("listavecini.out");
    
    int n;
    fin >> n;
    
    // Folosim set pentru a evita duplicatele și a păstra ordinea sortată
    vector<set<int>> vecini(n + 1);
    
    // Citim muchiile
    int i, j;
    while (fin >> i >> j) {
        // Graf neorientat - adăugăm muchie în ambele sensuri
        vecini[i].insert(j);
        vecini[j].insert(i);
    }
    
    // Afișăm lista de vecini pentru fiecare vârf
    for (int v = 1; v <= n; v++) {
        fout << vecini[v].size();
        for (int vecin : vecini[v]) {
            fout << " " << vecin;
        }
        fout << "\n";
    }
    
    fin.close();
    fout.close();
    
    return 0;
}