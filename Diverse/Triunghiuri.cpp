#include <iostream>
#include <algorithm>
using namespace std;

int main() { 
    int n;
    cin >> n;
    int v[101];
    int C, c;
    long long count = 0;
    
    for (int i = 0; i < n; i++)
        cin >> v[i];
    
    sort(v, v + n);
    
   
    for (int k = n-1; k >= 2; k--){
       	 int i = 0, j = k - 1;
    	while(i < j ) {
        	if (v[i] + v[j] > v[k]){
        		count += (j-i);
        		j--;
    		} else i++;
    	}
	}
    cout << count;
}