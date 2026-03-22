#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, idx;
vector<int> perm; 
vector<bool> used;
vector<int> rest; 

void afis() {
    for (int x : perm)
        cout << x << ' ';
    cout << '\n';
}

void BKT(int slot) {
    
    if (slot >= n) { 
        afis();
        return;
    }
    
    if(slot == idx){
      BKT(slot + 1);
      return;
    }
    
    for (int i = 0; i < (int)rest.size(); i++) {
        if (!used[i]) {
            used[i] = true;
            perm[slot] = rest[i]; 
            BKT(slot + 1);
            used[i] = false;
        }
    }
}

int main() {
	
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    rest.resize(n);
    for (int i = 0; i < n; i++)
        cin >> rest[i];

    int fixed = *min_element(rest.begin(), rest.end());
    auto it = find(rest.begin(), rest.end(), fixed);
    idx = it - rest.begin();

    perm.resize(n);
    perm[idx] = fixed;

   
    rest.erase(it);
    sort(rest.begin(), rest.end());

    used.assign(rest.size(), false);

    BKT(0);
    return 0;
}
    