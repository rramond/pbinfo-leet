// the dutch flag problem is a classic algorithmic problem that involves sorting an array of elements into three distinct groups based on a pivot value. The three groups are typically referred to as "less than", "equal to", and "greater than" the pivot. The problem is named after the Dutch national flag, which consists of three horizontal stripes of different colors.

// The algorithm works by maintaining three pointers: one for the current element being examined, one for the boundary of the "less than" group, and one for the boundary of the "greater than" group. As we iterate through the array, we swap elements to their appropriate positions based on their comparison with the pivot value.

#include <iostream>
#include <vector>
using namespace std;

void dutchFlag(vector<int>& arr, int pivot) {
    int low = 0;               // Pointer for the "less than" group
    int mid = 0;               // Pointer for the current element
    int high = arr.size() - 1; // Pointer for the "greater than" group

    while (mid <= high) {
        if (arr[mid] < pivot) {
            swap(arr[low], arr[mid]);
            low++;
            mid++;
        } else if (arr[mid] == pivot) {
            mid++;
        } else { // arr[mid] > pivot
            swap(arr[mid], arr[high]);
            high--;
        }
    }
}

