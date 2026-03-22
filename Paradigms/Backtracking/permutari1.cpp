
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;

ifstream in("permutari2.in");
ofstream out("permutari2.out");

void BKT(int n, vector<int>& path, vector<bool>& used, vector<int>& numbers) {
    
    if(path.size() == n) {
        for(int sol : path)
            out << sol << " ";
        out << '\n';
        return;
    }
    
    for(int i = 0; i < n; i++) {
        if(!used[i]){
            used[i] = true;
            path.push_back(numbers[i]);
            
            BKT(n, path, used, numbers);
        
    		path.pop_back();
            used[i] = false;
        }
    }
}

int main(){
    int n;
    in >> n;
    
    vector<int> numbers(n);
    for(int i = 0; i < n; i++) {
        in >> numbers[i];
    }
    
    sort(numbers.begin(), numbers.end());
    vector<int> path;
    vector<bool> used(n, false);
    
    BKT(n, path, used, numbers);
    
    return 0;
}