

//[INCERCAREA 1 - RECURSIVITATE - CAPS]
//[CREEZ STRINGUL SN DIN S SI APOI CAUT IN EL N  < 10^18 => NU MERGE, O SA AM UN STRING COLOSAL]
//[CODUL REZOLVA PROBLEMA PENTRU VALORI MICI ALE LUI N, SI MERGE IN IDE, DAR NU ESTE EFICIENT]
//[0/100 PBINFO]

// string CAPS(string a){
//     string b = "";
//     for(char c : a)
//     {
//         if (c < 'a') b += tolower(c);
//         else b += toupper(c);
//     }
//     return b;
// }

// string NEXT(string a, size_t N){
//     while(a.length() < N){
//     a.append(CAPS(a));
//     a.append(CAPS(a));
//     a.append(a);
//     }
//     return a;
// }

// void raspunsuri(int Q, const string& S){
//     if (Q <= 0 ) return;
//     int N;
//     if (!(cin>>N)) return;

//     if (N <= 0) {
//         cout << "index invalid = " << N << endl;
//         raspunsuri(Q - 1, S);
//         return;
//     }
//     string SN = NEXT(S, static_cast<size_t>(N));
//     char target = SN[N - 1];
//     int aparitii = 0;

//     for (int i = 0; i < N; ++i)
//         if (SN[i] == target) ++aparitii;

//     cout << "pe pozitia " << N << " este: " << target
//          << " si apare de: " << aparitii << " ori\n";
//         raspunsuri(Q-1, S);
// }

// int main(){
//    // ios::sync_with_stdio(false);
//     //cin.tie(nullptr);

//     int Q;  int k; //nr litere in S;
//     if (!(cin >> k >> Q)) return 0;//nr interogari de tipul:

//      „Dacă se dă un număr natural N, ce literă este în
//     șirul final pe poziția N și de câte ori a apărut această literă în șirul final,
//     de la începutul șirului final până la poziția N inclusiv?”.

//     string S; // string initial
//     cin>>S;
//     raspunsuri(Q, S);
//     return 0;
// }


// [INCERCAREA 2 - RECURSIVITATE - CAPS]
// [REZOLVARE EFICIENTA - O(log N) PENTRU FIECARE INTEROGARE - 25/100 PBINFO]
// [STRATEGIE - NU CONSTRUIM STRINGUL SN, CI DETERMINAM RECURSIV CARACTERUL DE LA POZITIA N SI NR DE APARITII ALE ACESTUIA]
// [FIECARE "NIVEL" SScScS CRESTE IN LUNGIME CU FACTORUL 4 => PROGRESIE GEOMETRICA l0=K, L1=4K, L2=16K, ... => LN=K*4^N]
// [IN LOC SA CONTRIUM UN STRING CARE POATE AJUNGE LA 10^18 CHAR IN LUNGIME, NAVIGAM TEORETIC PRIN EL FOLOSIND RECURSIVITATE ASTFEL:

// DIVIDE ET IMPERA: la fiecare nivel imaprtin stringul in 4 sferturi
                    // [   S   ][  Sc  ][  Sc  ][   S   ]
                    //   0-25%   25-50%  50-75%  75-100%
// MAPAM POSITIA: Determinam in ce sfert se afla N-ul nostru
// RECURSIVITATE: Il mapam pe N la pozitia corespunzatoare lui nivelului precedent
// CAZ DE BAZA: Cand ajugem la L0, accesam direct S (stringul initial)


// string S;
// int K;

// inline char CAPS(char c) {
//     if (c >= 'A' && c <= 'Z') return char(c - 'A' + 'a');
//     if (c >= 'a' && c <= 'z') return char(c - 'a' + 'A');
//     return c;
// }

// inline char findChar(long long pos, long long len) {
//     if (len == K) {

//         return S[(size_t)pos - 1];
//     }

//     long long sfert = len / 4;
//     if (pos <= sfert) {
//         return findChar(pos, sfert);
//     } else if (pos <= 2 * sfert) {
//         return CAPS(findChar(pos - sfert, sfert));
//     } else if (pos <= 3 * sfert) {
//         return CAPS(findChar(pos - 2 * sfert, sfert));
//     } else {
//         return findChar(pos - 3 * sfert, sfert);
//     }
// }


// inline long long countChar(char c, long long pos, long long len) {
//     if (pos <= 0) return 0;
//     if (len == K) {
//         long long cnt = 0;
//         long long upto = min<long long>(pos, K);
//         for (long long i = 0; i < upto; ++i) if (S[(size_t)i] == c) ++cnt;
//         return cnt;
//     }

//     long long sfert = len / 4;
//     long long total = 0;

//     if (pos <= sfert) {
//         total = countChar(c, pos, sfert);
//     } else if (pos <= 2 * sfert) {
//         total = countChar(c, sfert, sfert);
//         total += countChar(CAPS(c), pos - sfert, sfert);
//     } else if (pos <= 3 * sfert) {
//         total = countChar(c, sfert, sfert);
//         total += countChar(CAPS(c), sfert, sfert);
//         total += countChar(CAPS(c), pos - 2 * sfert, sfert);
//     } else {
//         total = countChar(c, sfert, sfert);
//         total += countChar(CAPS(c), sfert, sfert);
//         total += countChar(CAPS(c), sfert, sfert);
//         total += countChar(c, pos - 3 * sfert, sfert);
//     }

//     return total;
// }

// int main() {
//     ios::sync_with_stdio(false);
//     cin.tie(nullptr);

//     ifstream fin("caps.in.txt");
//     ofstream fout("caps.out");
//     if (!fin) return 0;

//     int Q;
//     fin >> K >> Q;
//     string tmp;
//     fin >> S;
//     vector<long long> intrebari(Q);
//     intrebari.reserve(50000);
//     long long maxN = 0;
//     for (int i = 0; i < Q; ++i) {
//         fin >> intrebari[i];
//         maxN = max(maxN, intrebari[i]);
//     }

//     long long len = K;
//     while (len < maxN) len *= 4;

//     for (int i = 0; i < Q; ++i) {
//         long long pos = intrebari[i];
//         char ch = findChar(pos, len);
//         long long cnt = countChar(ch, pos, len);
//         fout << ch << " " << cnt << "\n";
//     }

//     return 0;
// }

// [INCERCAREA 3 - RECURSIVITATE - CAPS]
// [REZOLVARE EFICIENTA CU MEMOIZATION - 30/100 PBINFO]
// [STRATEGIA DE LA V2 ERA BUNA SI CODUL FUNCTIONA, DAR INRECEA LIMITA DE TIMP PENTRU VALORI FOARTE MARI ALE LUI N, K  SI Q (DE EXEMPLE K=26, Q=50000, N APROAPE DE 10^18)]
// [STRATEGIE - LA FEL CA IN INCERCAREA 2, DAR AM ADAUGAT MEMOIZATION FOLOSIND UN UNORDERED MAP PENTRU FUNCTIA countChar PENTRU A EVITA RECALCULAREA ACELEIASI VALORI DE MAI MULTE ORI]
// [FOLOSIND MEMEOIZARE, IN countChar, CAND STIM CA AM TRECUT DE ANUMITE SFERTURI, FOLOSIM DIRECT aparitii[c][k], IN LOC SA MAI FACEM APELURI RECURSIVE PENTRU ACESTE SFERTURI, MEMOIZAREA NE AJUTA SI SA SARIM DE CALCULE REDUNDANTE CAND ACELEASI VALORI SUNT CERUTE DE MAI MULTE ORI, SAU AU MAI APARUT IN ARBORELE APELURILOR RECURSIVE]

// #include <fstream>
// #include <iostream>
// #include <string>
// #include <vector>
// #include <unordered_map>
// using namespace std;

// string S;
// int K;
// vector<int> aparitii[256];
// unordered_map<long long, long long> countMemo[256]; // [MEMOIZARE PENTRU FIECARE countChar]

// inline char CAPS(char c) {
//     if (c >= 'A' && c <= 'Z') return char(c - 'A' + 'a');
//     if (c >= 'a' && c <= 'z') return char(c - 'a' + 'A');
//     return c;
// }

// // [PRECOMPUTAM NR DE APARITII PENTRU FIECARE CARACTER IN STRINGUL INITIAL S PANA LA ORICE POZITIE i <= K]
// void calcAparitii() {
//     for (int i = 0; i < 256; ++i) {
//         aparitii[i].resize(K + 1, 0);
//         for (int j = 1; j <= K; ++j) {
//             aparitii[i][j] = aparitii[i][j - 1] + (S[j] == i ? 1 : 0);
//         }
//     }
// }

// // [CREAM O CHEIE UNICA PENTRU FIECARE APEL RECURSIV IN FUNCTIA countChar PENTRU MEMOIZARE]
// inline long long cheie(long long pos, long long len) {
//     //[CUM LUNGIMEA ESTE MEREU M4 PUTEM FOLOSI LOGARITMUL IN BAZA 4 PENTRU A DETERMINA NIVELUL]
//     long long logLen = 0;
//     long long temp = len / K;
//     while (temp > 1) {
//         temp /= 4;
//         logLen++;
//     }
//     return (logLen << 40) | pos; // [COMBINAM LOGARITMUL LUI LEN CU POS PENTRU A FORMA O CHEIE UNICA]
// }

// //[la fel ca v2, dar cu verificare siguranta la accesarea lui S]
// inline char findChar(long long pos, long long len) {
//     if (len == K) {
//         if (pos < 1 || pos > K) return '?'; // [VERIFICARE SIGURANTA]
//         return S[pos];
//     }
//     long long sfert = len / 4;
//     if (pos <= sfert) {
//         return findChar(pos, sfert);
//     } else if (pos <= 2 * sfert) {
//         return CAPS(findChar(pos - sfert, sfert));
//     } else if (pos <= 3 * sfert) {
//         return CAPS(findChar(pos - 2 * sfert, sfert));
//     } else {
//         return findChar(pos - 3 * sfert, sfert);
//     }
// }

// //[FUNCTIA countChar CU MEMOIZATION - NUMARA RECURSIV IN FIECARE SFERT]
// long long countChar(char c, long long pos, long long len) {
//     if (pos <= 0) return 0;

//     if (len == K) {
//         long long poz = min(pos, (long long)K);
//         return aparitii[(unsigned char)c][poz];
//     }

//     //[VERIFICAM DACA AVEM VALOAREA CALCULATA IN MEMO]
//     long long key = cheie(pos, len);
//     auto& memo = countMemo[(unsigned char)c];
//     auto it = memo.find(key);
//     if (it != memo.end()) {
//         return it->second;
//     }

//     long long sfert = len / 4;
//     long long total = 0;

//     if (pos <= sfert) {
//         // [NUMARAM DOAR IN PRIMUL SFERT]
//         total = countChar(c, pos, sfert);
//     } else if (pos <= 2 * sfert) {
//         // [PRIMUL SFERT COMPLET + PARTIAL DIN AL DOILEA]
//         total = countChar(c, sfert, sfert);
//         total += countChar(CAPS(c), pos - sfert, sfert);
//     } else if (pos <= 3 * sfert) {
//         // [PRIMELE DOUA SFERTURI COMPLETE + PARTIAL DIN AL TREILEA]
//         total = countChar(c, sfert, sfert);
//         total += countChar(CAPS(c), sfert, sfert);
//         total += countChar(CAPS(c), pos - 2 * sfert, sfert);
//     } else {
//         // [PRIMELE TREI SFERTURI COMPLETE + PARTIAL DIN AL PATRULEA]
//         total = countChar(c, sfert, sfert);
//         total += countChar(CAPS(c), sfert, sfert);
//         total += countChar(CAPS(c), sfert, sfert);
//         total += countChar(c, pos - 3 * sfert, sfert);
//     }

//     memo[key] = total;
//     return total;
// }

//


// [VARIANTA FINALA - RECURSIVITATE - CAPS]
// [REZOLVARE EFICIENTA CU MEMOIZATION - 75/100 PBINFO]
// [STRATEGIA DE LA V3 ESTE FOARTE BUNA SI CODUL FUNCTIONA, DAR AM INLOCUIT UNORDERED_MAP CU MAP PENTRU A REDUCE CONSUMUL DE MEMORIE]
// [FOLOSIND UNORDERED_MAP, PENTRU CA FUNCTIA DE HASH FOLOSESTE MULTA MEMORIE, AM AJUNS LA LIMITELE DE MEMORIE ALE PROBLEMEI PENTRU CA FIECARE INTEROGARE POATE GENERA MULTI APARITII ALE ACELEIASI CHEI IN ARBORELE APELURILOR RECURSIVE]

#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <map>
using namespace std;

string S;
int K;
vector<int> aparitii[256];
map<pair<long long, long long>, long long> countMemo[256];

inline char CAPS(char c) {
    if (c >= 'A' && c <= 'Z') return char(c - 'A' + 'a');
    if (c >= 'a' && c <= 'z') return char(c - 'a' + 'A');
    return c;
}

// [PRECOMPUTAM NR DE APARITII PENTRU FIECARE CARACTER IN STRINGUL INITIAL S PANA LA ORICE POZITIE i <= K]
void calcAparitii() {
    for (int i = 0; i < 256; ++i) {
        aparitii[i].resize(K + 1, 0);
        for (int j = 1; j <= K; ++j) {
            aparitii[i][j] = aparitii[i][j - 1] + (S[j] == i ? 1 : 0);
        }
    }
}

inline char findChar(long long pos, long long len) {
    if (pos < 1) return '?';

    if (len == K) {
        if (pos > K) return '?';
        return S[pos];
    }

    long long sfert = len / 4;
    if (pos <= sfert) {
        return findChar(pos, sfert);
    } else if (pos <= 2 * sfert) {
        return CAPS(findChar(pos - sfert, sfert));
    } else if (pos <= 3 * sfert) {
        return CAPS(findChar(pos - 2 * sfert, sfert));
    } else {
        return findChar(pos - 3 * sfert, sfert);
    }
}

//[FUNCTIA countChar CU MEMOIZARE - NUMARA RECURSIV IN FIECARE SFERT]
long long countChar(char c, long long pos, long long len) {
    if (pos <= 0) return 0;

    if (len == K) {
        long long poz = min(pos, (long long)K);
        if (poz < 0 || poz >= aparitii[(unsigned char)c].size()) return 0;
        return aparitii[(unsigned char)c][poz];
    }

    //[VERIFICAM DACA AVEM VALOAREA CALCULATA IN MEMO]
    auto key = make_pair(pos, len);
    auto& memo = countMemo[(unsigned char)c];
    auto it = memo.find(key);
    if (it != memo.end()) {
        return it->second;
    }

    long long sfert = len / 4;
    long long total = 0;

    if (pos <= sfert) {
        // [NUMARAM DOAR IN PRIMUL SFERT]
        total = countChar(c, pos, sfert);
    } else if (pos <= 2 * sfert) {
        // [PRIMUL SFERT COMPLET: numaram tot sfertul, nu doar primele K pozitii]
        total = countChar(c, sfert, sfert);
        // [AL DOILEA SFERT PARTIAL: caracterele sunt swapped]
        total += countChar(CAPS(c), pos - sfert, sfert);
    } else if (pos <= 3 * sfert) {
        // [PRIMUL SFERT COMPLET]
        total = countChar(c, sfert, sfert);
        // [AL DOILEA SFERT COMPLET: caracterele sunt swapped]
        total += countChar(CAPS(c), sfert, sfert);
        // [AL TREILEA SFERT PARTIAL: caracterele sunt swapped]
        total += countChar(CAPS(c), pos - 2 * sfert, sfert);
    } else {
        // [PRIMUL SFERT COMPLET]
        total = countChar(c, sfert, sfert);
        // [AL DOILEA SFERT COMPLET: caracterele sunt swapped]
        total += countChar(CAPS(c), sfert, sfert);
        // [AL TREILEA SFERT COMPLET: caracterele sunt swapped]
        total += countChar(CAPS(c), sfert, sfert);
        // [AL PATRULEA SFERT PARTIAL: caracterele sunt normale]
        total += countChar(c, pos - 3 * sfert, sfert);
    }

    memo[key] = total;
    return total;
}

int main() {
    ifstream fin("caps.in.txt");
    ofstream fout("caps.out.txt");
    if (!fin) return 0;

    int Q;
    fin >> K >> Q;
    fin >> S;

    // [ADAUGAM UN CARACTER DUMMY LA INCEPUT PENTRU INDEXARE DE LA 1]
    S = " " + S;

    calcAparitii();

    vector<long long> intrebari(Q);
    long long maxN = 0;
    for (int i = 0; i < Q; ++i) {
        fin >> intrebari[i];
        maxN = max(maxN, intrebari[i]);
    }

    long long len = K;
    while (len < maxN) len *= 4;

    for (int i = 0; i < Q; ++i) {
        long long pos = intrebari[i];
        char ch = findChar(pos, len);
        long long cnt = countChar(ch, pos, len);
        fout << ch << " " << cnt << "\n";
    }

    return 0;
}
