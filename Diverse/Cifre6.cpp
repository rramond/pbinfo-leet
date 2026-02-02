#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;


int numar(int n, int k, int &x){
  vector<int> nr(11);
  x = 0;
  while(n > 0) {
    nr.push_back(n % 10);
    n /= 10;
  }
  
  sort(nr.begin(), nr.end());
  
  int y;
  int size = nr.size() - 1;
  
  while (k--) {
    y = nr[size--];
    x = x * 10 + y;
  }
  return x;
    
}

int main() { 
    int n, k, x;
    cin >> n >> k;
    cout<<numar(n, k, x);
}