//Se citește un număr natural nenul n. Să se afişeze, în ordine lexicografică, toate submulțimile nevide ale mulţimii {1,2,..,n}.

#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

ifstream fin("submultimi.in");
ofstream fout("submultimi.out");

void backtrack(int n, vector<int>& sol, vector<bool>& used) {
    if (!sol.empty()) {
        for (int num : sol) {
            fout << num << " ";
        }
        fout << "\n";
    }

    int vmin = 1;
    if(sol.size() > 0) {
        vmin = sol.back() + 1;
    }

    for (int i = vmin; i <= n; ++i) {
        if (!used[i]) {
            used[i] = true;
            sol.push_back(i);
            backtrack(n, sol, used);
            sol.pop_back();
            used[i] = false;
        }
    }
}

int main() {
    int n;
    fin >> n;

    vector<int> sol;
    vector<bool> used(n + 1, false);
    backtrack(n, sol, used);

    fin.close();
    fout.close();
}