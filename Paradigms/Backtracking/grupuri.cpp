//disjoint set generation


#include <iostream>
#include <fstream>
using namespace std;

ifstream fin("partitiimultime.in");
ofstream fout("partitiimultime.out");

int n;
int grup[10]; // grup[i] = which partition subset element i belongs to
// grup is 1-indexed for elements

void afisare(int nr_grupuri) {
    for (int g = 1; g <= nr_grupuri; g++) {
        for (int i = 1; i <= n; i++) {
            if (grup[i] == g)
                cout << i;
        }
        cout << '*';
    }
    cout << '\n';
}

void BKT(int elem, int nr_grupuri) {
    if (elem == n + 1) {
        afisare(nr_grupuri);
        return;
    }

    // Option 1: place elem in any existing group
    for (int g = 1; g <= nr_grupuri; g++) {
        grup[elem] = g;
        BKT(elem + 1, nr_grupuri);
    }

    // Option 2: open a brand new group
    grup[elem] = nr_grupuri + 1;
    BKT(elem + 1, nr_grupuri + 1);
}

int main() {
    cin >> n;
    // Element 1 always goes into group 1
    grup[1] = 1;
    BKT(2, 1);
    return 0;
}