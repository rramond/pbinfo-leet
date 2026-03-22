#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

ifstream in("permutari1.in");
ofstream out("permutari1.out");


void BKT(int n, vector<int>& path, vector<bool>& used) {
	
    if(path.size() == n) {
        for(int sol : path)
            cout << sol << " ";
        cout << '\n';
        return;
    }
    //lexicografic
    for(int i = 1; i <= n; i++) {
        if(!used[i-1]){
            used[i-1] = true;
            path.push_back(i);
            
            BKT(n, path, used);
        
    		path.pop_back();
            used[i-1] = false;
        }
    }
    
    //invers lexicografic
    for(int i = n; i > 0; i--) {
        if(!used[n-i]){
            used[n-i] = true;
            path.push_back(i);
            
            BKT(n, path, used);
        
    		path.pop_back();
            used[n-i] = false;
        }
    }
}


int main(){
    int n;
    cin >> n;
    
    vector<int> path;
    vector<bool> used(n, false);
    
    BKT(n, path, used);
    
    return 0;
}
             