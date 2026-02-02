// tuff ahh problem nu trec de 45 rn

// rezolvare cu quick select - 45 puncte

#include <fstream>
#include <algorithm>
using namespace std;

ifstream fin("statisticiordine.in");
ofstream fout("statisticiordine.out");

int n, k;
int v[4000005];

// Partiționare în 3 căi: < pivot, = pivot, > pivot
void partition3(int left, int right, int &lt, int &gt) {
    int pivot = v[left + right >> 1];
    int i = left;
    lt = left;
    gt = right;
    
    while (i <= gt) {
        if (v[i] < pivot) {
            swap(v[i], v[lt]);
            lt++;
            i++;
        } else if (v[i] > pivot) {
            swap(v[i], v[gt]);
            gt--;
        } else {
            i++;
        }
    }
}

// QuickSelect cu partiționare în 3 căi
int quickSelect(int left, int right, int k) {
    if (left == right) return v[left];
    
    int lt, gt;
    partition3(left, right, lt, gt);
    
    // Acum avem:
    // [left, lt-1] - elemente < pivot
    // [lt, gt] - elemente = pivot
    // [gt+1, right] - elemente > pivot
    
    if (k <= lt) {
        // Al k-lea element este în partea stângă
        return quickSelect(left, lt - 1, k);
    } else if (k <= gt + 1) {
        // Al k-lea element este pivotul
        return v[lt];
    } else {
        // Al k-lea element este în partea dreaptă
        return quickSelect(gt + 1, right, k);
    }
}

int main() {
    fin >> n >> k;
    
    for (int i = 0; i < n; i++) {
        fin >> v[i];
    }
    
    fout << quickSelect(0, n - 1, k) << '\n';
    
    fin.close();
    fout.close();
    
    return 0;
}

// incercam cu set - 15puncte + un signal 11

#include <fstream>
#include <set>
using namespace std;

ifstream fin("kmin.in");
ofstream fout("kmin.out");

int main() {
    int n, k;
    fin >> n >> k;
    
    set<int> s;
    
    for (int i = 0; i < n; i++) {
        int x;
        fin >> x;
        s.insert(x);
    }
    
    // Iterăm până la al k-lea element
    // auto it = s.begin();
    // for (int i = 1; i < k; i++) {
    //     ++it;
    // }
    
    fout << *next(s.begin(), k - 1) << '\n';
    
    fin.close();
    fout.close();
    
    return 0;
}