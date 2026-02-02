// prefix sums are useful for answering range sum queries efficiently
// use cases (as problem statements):
// 1. Given an array of integers, answer multiple queries asking for the sum of elements between two given indices.
#include <iostream>
#include <vector>
using namespace std;
class PrefixSum {
private:
    vector<int> prefixSums;
public:
    // Constructor to build the prefix sum array
    PrefixSum(const vector<int>& arr) {
        int n = arr.size();
        prefixSums.resize(n + 1, 0); // prefixSums[0] = 0
        for (int i = 1; i <= n; ++i) {
            prefixSums[i] = prefixSums[i - 1] + arr[i - 1];
        }
    }
    // Function to get the sum of elements from index l to r (0-based indexing)
    int rangeSum(int l, int r) {
        return prefixSums[r + 1] - prefixSums[l];
    }
};

// Example usage
int main() {
    vector<int> arr = {1, 2, 3, 4, 5};
    PrefixSum ps(arr);

    cout << "Sum of elements from index 1 to 3: " << ps.rangeSum(1, 3) << endl; // Output: 9
    cout << "Sum of elements from index 0 to 4: " << ps.rangeSum(0, 4) << endl; // Output: 15

    return 0;
}

// 2. Given a 2D matrix, answer multiple queries asking for the sum of elements within a submatrix defined by its top-left and bottom-right corners.
#include <iostream>
#include <vector>
using namespace std;
class PrefixSum2D {
private:
    vector<vector<int>> prefixSums;
public:
    // Constructor to build the 2D prefix sum array
    PrefixSum2D(const vector<vector<int>>& matrix) {
        int rows = matrix.size();
        int cols = matrix[0].size();
        prefixSums.resize(rows + 1, vector<int>(cols + 1, 0)); // Extra row and column for easier calculations

        for (int i = 1; i <= rows; ++i) {
            for (int j = 1; j <= cols; ++j) {
                prefixSums[i][j] = matrix[i - 1][j - 1] 
                                   + prefixSums[i - 1][j] 
                                   + prefixSums[i][j - 1] 
                                   - prefixSums[i - 1][j - 1];
            }
        }
    }
    // Function to get the sum of elements in the submatrix defined by (row1, col1) and (row2, col2)
    int rangeSum(int row1, int col1, int row2, int col2) {
        return prefixSums[row2 + 1][col2 + 1] 
               - prefixSums[row1][col2 + 1] 
               - prefixSums[row2 + 1][col1] 
               + prefixSums[row1][col1];
    }
};
// Example usage
int main() {
    vector<vector<int>> matrix = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };
    PrefixSum2D ps2d(matrix);

    cout << "Sum of elements in submatrix (0,0) to (1,1): " << ps2d.rangeSum(0, 0, 1, 1) << endl; // Output: 12
    cout << "Sum of elements in submatrix (1,1) to (2,2): " << ps2d.rangeSum(1, 1, 2, 2) << endl; // Output: 28

    return 0;
}

// 3. Given an array of integers, find the maximum sum of any contiguous subarray.
#include <iostream>
#include <vector>
using namespace std;
int maxSubArraySum(const vector<int>& arr) {
    int maxSoFar = arr[0];
    int maxEndingHere = arr[0];

    for (size_t i = 1; i < arr.size(); ++i) {
        maxEndingHere = max(arr[i], maxEndingHere + arr[i]);
        maxSoFar = max(maxSoFar, maxEndingHere);
    }
    return maxSoFar;
}
// Example usage
int main() {
    vector<int> arr = {-2,1,-3,4,-1,2,1,-5,4};
    cout << "Maximum contiguous subarray sum: " << maxSubArraySum(arr) << endl; // Output: 6
    return 0;
}

// 4. Given an array of integers, find the number of subarrays that sum to a given value k.
#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int main() {
    int n;
    long long k;
    cin >> n >> k;

    unordered_map<long long, int> freq;
    freq[0] = 1; // prefix sum 0 apare o dată

    long long sum = 0;
    long long count = 0;

    for (int i = 0; i < n; ++i) {
        long long x;
        cin >> x;
        sum += x;

        if (freq.count(sum - k))
            count += freq[sum - k];

        freq[sum]++;
    }

    cout << count;
    return 0;
}
