#include <vector>
#include <iostream>
using namespace std;

// NOTE: 1292 can also be solved using this code + one little extra condition int he final if statement and a max var

class Solution {
private:
vector<vector<int>> prefix;
public:
    int countSquares(vector<vector<int>>& matrix) {
        if(matrix.empty()) return 0;
        int sq = 0;
        int m = matrix.size();
        int n = matrix[0].size();

        prefix.resize(m + 1, vector<int>(n + 1, 0));

        for(int i = 1; i <= m; i++)
            for(int j = 1; j <= n; j++)
                prefix[i][j] = matrix[i-1][j-1] + prefix[i-1][j] + prefix[i][j-1] - prefix[i-1][j-1];
        
        for(short int k = 1; k <= (short int)min(m, n); k++) {
            for(int i = 1; i <= (m-k+1); i++)
                for(int j = 1; j <= (n-k+1); j++)
                    if((prefix[i+k-1][j+k-1] 
                    - prefix[i-1][j+k-1] 
                    - prefix[i+k-1][j-1] 
                    + prefix[i-1][j-1]) == k*k)
                        sq++;
        }
        return sq;
    }
};

int main() {
    int m, n;
    cin >> m >> n;
    vector<vector<int>> matrix(m, vector<int>(n));
    for(int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            int val;
            cin >> val;
            matrix[i][j] = val;
        }
    }
    Solution sol;
    cout << sol.countSquares(matrix) << endl;
}