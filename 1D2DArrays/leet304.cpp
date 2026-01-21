

//2D array prefix sum

#include <iostream>
#include <vector>
using namespace std;

// function to build prefix sum array
vector<vector<int>> buildPrefixSum(const vector<vector<int>>& matrix) {
    if (matrix.empty() || matrix[0].empty()) {
        return vector<vector<int>>();
    }
    
    int m = matrix.size();
    int n = matrix[0].size();
    vector<vector<int>> prefix(m + 1, vector<int>(n + 1, 0));
    
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            prefix[i][j] = matrix[i-1][j-1] 
                         + prefix[i-1][j] 
                         + prefix[i][j-1] 
                         - prefix[i-1][j-1];
        }
    }
    
    return prefix;
}

// function to get sum of submatrix 
int sumRegion(const vector<vector<int>>& prefix, int row1, int col1, int row2, int col2) {
    // Calculating this way, the input has to be top-left and bottom-right corners
    // return prefix[row2][col2] 
    //      - prefix[row1-1][col2] 
    //      - prefix[row2][col1-1] 
    //      + prefix[row1-1][col1-1];

    // We can take any two corners by normalizing them
    int minRow = min(row1, row2);
    int maxRow = max(row1, row2);
    int minCol = min(col1, col2);
    int maxCol = max(col1, col2);
    
   return prefix[maxRow][maxCol] 
         - prefix[minRow-1][maxCol] 
         - prefix[maxRow][minCol-1] 
         + prefix[minRow-1][minCol-1];
}

int main() {
    int m, n;
    cout << "Enter number of rows: ";
    cin >> m;
    cout << "Enter number of columns: ";
    cin >> n;
    
    vector<vector<int>> matrix(m, vector<int>(n));
    
    cout << "Enter matrix elements row by row:\n";
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cin >> matrix[i][j];
        }
    }
    
    vector<vector<int>> prefix = buildPrefixSum(matrix);
    
    int q;
    cout << "Enter number of queries: ";
    cin >> q;
    
    cout << "Enter queries as: row1 col1 row2 col2 (1-indexed)\n";
    for (int i = 1; i <= q; i++) {
        int row1, col1, row2, col2;
        cin >> row1 >> col1 >> row2 >> col2;
        cout << "Sum: " << sumRegion(prefix, row1, col1, row2, col2) << endl;
    }
    
    return 0;
}
