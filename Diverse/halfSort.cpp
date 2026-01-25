#include <fstream>
#include <algorithm>
#include <vector>
using namespace std;

inline bool desc(int a, int b){
  return a > b;
}

int main() {
    
    ifstream in("halfsortqs.in");
    ofstream out("halfsortqs.out");
    
  int n;
  in >> n;
  vector<int> v(n);
  vector<int> pozitiv;
  vector<int> negativ;
  
  int p = 0, q = 0;
  
  for(int i = 0; i < n; i++){
      in >> v[i];
      if(v[i] < 0) {
        negativ.push_back(v[i]);
      } else {
        pozitiv.push_back(v[i]);
      }
  }
  
  //pozitiv.resize(n - size_p);
  sort(pozitiv.begin(), pozitiv.end(), desc);
  //negativ.resize(n - size_n);
  sort(negativ.begin(), negativ.end());
  
  for(int i = 0; i < n; i++) {
    if(v[i] < 0) v[i] = negativ[p++];
    else v[i] = pozitiv[q++];
    out << v[i] << " ";
  }
  
  
}