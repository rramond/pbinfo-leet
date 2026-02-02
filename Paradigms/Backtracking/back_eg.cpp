// Backtracking example in C++17

#include <iostream>
#include <vector>
using namespace std;

void backtrack(int n, vector<int>& solution, vector<bool>& used) {
    // Cazul de baza: daca solutia are dimensiunea n, o afisam
    if (solution.size() == n) {
        for (int num : solution) {
            cout << num << " ";
        }
        cout << "\n";
        return;
    }

    // Incercam sa adaugam fiecare numar de la 1 la n in solutie
    for (int i = 1; i <= n; ++i) {
        if (!used[i]) { // Daca numarul nu a fost folosit
            used[i] = true; // Marcam numarul ca folosit
            solution.push_back(i); // Adaugam numarul in solutie

            backtrack(n, solution, used); // Apel recursiv

            // Backtrack: eliminam ultimul numar adaugat si il marcam ca nefolosit
            solution.pop_back();
            used[i] = false;
        }
    }
}

int main() {
    int n;
    cout << "Introduceti un numar n pentru a genera permutarile de la 1 la n: ";
    cin >> n;

    vector<int> solution; // Solutia curenta
    vector<bool> used(n + 1, false); // Vector pentru a marca numerele folosite

    backtrack(n, solution, used); // Pornim backtracking-ul

    return 0;
}