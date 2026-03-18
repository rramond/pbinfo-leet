//Se citesc două numere naturale nenule n și k. Să se afişeze, în ordine lexicografică, submulțimile de câte k elemente ale mulţimii {1,2,..,n}.

#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

ifstream fin("combinari.in");
ofstream fout("combinari.out");

void backtrack(int n, int k, vector<int>& solution, vector<bool>& used) {
    if (solution.size() == k) {
        for (int num : solution) {
            fout << num << " ";
        }
        fout << "\n";
        return;
    }

    int vmin = 1;
    if(solution.size() > 0) {
        vmin = solution.back() + 1;
    }

    for (int i = vmin; i <= n; ++i) {
        if (!used[i]) {
            used[i] = true;
            solution.push_back(i);
            backtrack(n, k, solution, used);
            solution.pop_back();
            used[i] = false;
        }
    }
}

int main () {

    int n, k;
    fin >> n >> k;

    vector<int> solution;
    vector<bool> used(n + 1, false); 
    backtrack(n, k, solution, used);

    fin.close();
    fout.close();

    return 0;
}