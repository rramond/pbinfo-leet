#include <iostream>
#include <vector>
using namespace std;

// 2D array prefix sum to find maximum sum of k submatrices after k queries

int main() {
    int n, m, k;
    cin >> n >> m >> k;
    
    vector<vector<int>> matrix(n, vector<int>(m));
    
    for(int i = 0; i < n; i++)
      for(int j = 0; j < m; j++)
    	cin >> matrix[i][j];
        
    if(matrix.empty()) return 0;
        
    vector<vector<int>> prefix;
        
    prefix.resize(n + 1, vector<int>(m + 1, 0));
    
    for(int i = 1; i <= n; i++)
      for(int j = 1; j <= m; j++)
        prefix[i][j] = matrix[i-1][j-1] + prefix[i-1][j] + prefix[i][j-1] - prefix[i-1][j-1];
        
    int C, maxC = 0;
    int row1, col1, row2, col2;
        for(int z = 0; z < k; z++){
        	cin >> row1 >> col1 >> row2 >> col2;
        	C = prefix[row2][col2] 
         		- prefix[row1-1][col2] 
        		- prefix[row2][col1-1] 
         		+ prefix[row1-1][col1-1];
        	if(maxC < C) maxC = C;
    	}
    cout << maxC;
    return 0;
}