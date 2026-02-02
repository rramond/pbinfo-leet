// 1D difference array implementation in C++17
#include <iostream>
#include <vector>
using namespace std;

void applyDifferenceArray(vector<int>& arr, const vector<tuple<int, int, int>>& updates) {
    int n = arr.size();
    vector<int> diff(n + 1, 0); // Create a difference array of size n+1

    // Apply each update to the difference array
    for (const auto& update : updates) {
        int l, r, val;
        tie(l, r, val) = update;
        diff[l] += val;          // Increment at the start index
        if (r + 1 < n) {
            diff[r + 1] -= val;  // Decrement just after the end index
        }
    }

    // Build the final array using the difference array
    int current = 0;
    for (int i = 0; i < n; ++i) {
        current += diff[i];
        arr[i] += current; // Update the original array
    }
}

// Simpler implementation without tuples
void applyDifferenceArraySimple(vector<int>& arr, const vector<vector<int>>& updates) {
    int n = arr.size();
    vector<int> diff(n + 1, 0); // Create a difference array of size n+1

    // Apply each update to the difference array
    for (const auto& update : updates) {
        int l = update[0];
        int r = update[1];
        int val = update[2];
        diff[l] += val;          // Increment at the start index
        if (r + 1 < n) {
            diff[r + 1] -= val;  // Decrement just after the end index
        }
    }

    // Build the final array using the difference array
    int current = 0;
    for (int i = 0; i < n; ++i) {
        current += diff[i];
        arr[i] += current; // Update the original array
    }
}

// Example usage
int main() {
    vector<int> arr = {1, 2, 3, 4, 5};
    vector<tuple<int, int, int>> updates = {
        {1, 3, 10}, // Add 10 to indices 1 to 3
        {0, 2, 5}   // Add 5 to indices 0 to 2
    };

    applyDifferenceArray(arr, updates);

    cout << "Updated array using tuple-based updates: ";
    for (int val : arr) {
        cout << val << " ";
    }
    cout << endl;

    // Reset array for simple implementation
    arr = {1, 2, 3, 4, 5};
    vector<vector<int>> simpleUpdates = {
        {1, 3, 10}, // Add 10 to indices 1 to 3
        {0, 2, 5}   // Add 5 to indices 0 to 2
    };

    applyDifferenceArraySimple(arr, simpleUpdates);

    cout << "Updated array using vector-based updates: ";
    for (int val : arr) {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}

// 2D difference array implementation in C++17
#include <iostream>
#include <vector>
using namespace std;

void apply2DDifferenceArray(vector<vector<int>>& matrix, const vector<tuple<int, int, int, int, int>>& updates) {
    int rows = matrix.size();
    int cols = matrix[0].size();
    vector<vector<int>> diff(rows + 1, vector<int>(cols + 1, 0)); // Create a 2D difference array

    // Apply each update to the difference array
    for (const auto& update : updates) {
        int x1, y1, x2, y2, val;
        tie(x1, y1, x2, y2, val) = update;
        diff[x1][y1] += val;               // Top-left corner
        if (x2 + 1 < rows) diff[x2 + 1][y1] -= val; // Below bottom-left corner
        if (y2 + 1 < cols) diff[x1][y2 + 1] -= val; // Right of top-right corner
        if (x2 + 1 < rows && y2 + 1 < cols) diff[x2 + 1][y2 + 1] += val; // Bottom-right corner
    }

    // Build the final matrix using the difference array
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            if (i > 0) diff[i][j] += diff[i - 1][j];
            if (j > 0) diff[i][j] += diff[i][j - 1];
            if (i > 0 && j > 0) diff[i][j] -= diff[i - 1][j - 1];
            matrix[i][j] += diff[i][j]; // Update the original matrix
        }
    }
}

// Example usage for 2D difference array
int main() {
    vector<vector<int>> matrix = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };
    vector<tuple<int, int, int, int, int>> updates = {
        {0, 0, 1, 1, 10}, // Add 10 to submatrix from (0,0) to (1,1)
        {1, 1, 2, 2, 5}   // Add 5 to submatrix from (1,1) to (2,2)
    };

    apply2DDifferenceArray(matrix, updates);

    cout << "Updated matrix using 2D difference array: \n";
    for (const auto& row : matrix) {
        for (int val : row) {
            cout << val << " ";
        }
        cout << endl;
    }

    return 0;
}