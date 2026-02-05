#include <iostream>
#include <vector>
using namespace std;

// the function checks if a given matrix is an adjacency matrix of a simple undirected graph
bool adiacenta(const vector<vector<int>>& matrix, int n){
    for(int i = 0; i < n; i++) {
        // the diagonal elements must be 0 (no self-loops)
        if(matrix[i][i] != 0)
            return false;
            
        for(int j = i + 1; j < n; j++) {
            // the matrix must be symmetric
            if(matrix[i][j] != matrix[j][i])
                return false;
            
            // the elements must be either 0 or 1 (nu multiple edges between the same 2 nodes)
            if(matrix[i][j] < 0 || matrix[i][j] > 1)
                return false;
        }
    }
    
    return true;
}

int main() {
    int n;
    cin >> n;
    vector<vector<int>> M(n, vector<int>(n));
    
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin >> M[i][j];
        }
    }
    
    cout << (adiacenta(M, n)? 1 : 0) << "\n";
    return 0;
}