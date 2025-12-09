#include <fstream>
#include <iostream>
#include <string>
using namespace std;

ifstream in("caps.in");
ofstream out("caps.out");

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
// [REZOLVARE EFICIENTA - O(log N) PENTRU FIECARE INTEROGARE - 100/100 PBINFO]
// [STRATEGIE - NU CONSTRUIM STRINGUL SN, CI DETERMINAM RECURSIV CARACTERUL DE LA POZITIA N SI NR DE APARITII ALE ACESTUIA]
// [FIECARE "NIVEL" SScScS CRESTE IN LUNGIME CU FACTORUL 4 => PROGRESIE GEOMETRICA l0=K, L1=4K, L2=16K, ... => LN=K*4^N]
// [IN LOC SA CONTRIUM UN STRING CARE POATE AJUNGE LA 10^18 CHAR IN LUNGIME, NAVIGAM TEORETIC PRIN EL FOLOSIND RECURSIVITATE ASTFEL:

// DIVIDE ET IMPERA: la fiecare nivel imaprtin stringul in 4 sferturi
                    // [   S   ][  Sc  ][  Sc  ][   S   ]
                    //   0-25%   25-50%  50-75%  75-100%
// MAPAM POSITIA: Determinam in ce sfert se afla N-ul nostru
// RECURSIVITATE: Il mapam pe N la pozitia corespunzatoare lui nivelului precedent
// CAZ DE BAZA: Cand ajugem la L0, accesam direct S (stringul initial) 

