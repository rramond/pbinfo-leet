#include <iostream>
using namespace std;


// [PROBLEMA FIVE - NUMARAREA TRIPLETELOR CU SUMA DIVIZIBILA LA 5]
// putem lua modulul fiecarui numar cu 5 si numaram cate numere avem pentru fiecare rest
// apoi folosim combinari pentru a numara tripletele care dau suma divizibila la 5

//Time complexity: O(n) for generation + O(5²) = O(n) overall
//Space complexity: O(1)


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n;
    cin >> n;
    long long w, X, Y ,Z ;
    cin >> w >> X >> Y >> Z;

    //numaram frecventa fiecarui rest modulo 5 in vectorul cnt
    long long cnt[5] = {0};
    long long a = w;
    
    for (long long i = 0; i < n; i++) {
        cnt[a % 5]++;
        a = (X * a + Y) % Z;
    }
    
    long long result = 0;
    
    // iteram prin toate combinatiile de resturi (r1, r2, r3)
    for (int r1 = 0; r1 < 5; r1++) {
        for (int r2 = r1; r2 < 5; r2++) {
            int r3 = (15 - r1 - r2) % 5;  // r1 + r2 + r3 ≡ 0 (mod 5)

            if (r3 < r2) continue; // asiguram ordinea r1 <= r2 <= r3
            
            // calculam numarul de triplete in functie de egalitatea resturilor
            if (r1 == r2 && r2 == r3) {
               // toate resturile sunt egale
                result += cnt[r1] * (cnt[r1] - 1) * (cnt[r1] - 2) / 6;
            } else if (r1 == r2) {
              // r1 si r2 sunt egale
                result += cnt[r1] * (cnt[r1] - 1) / 2 * cnt[r3];
            } else if (r2 == r3) {
                // r2 si r3 sunt egale
                result += cnt[r1] * cnt[r2] * (cnt[r2] - 1) / 2;
            } else {
               // toate resturile sunt diferite
                result += cnt[r1] * cnt[r2] * cnt[r3];
            }
        }
    }
    
    cout << result << endl;
    
    return 0;
}
