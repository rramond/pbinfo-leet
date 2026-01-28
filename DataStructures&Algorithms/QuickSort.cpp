#include <iostream>
#include <utility>
#include <vector>
using namespace std;

template <typename T>
void mySwap(T &a, T &b) {
    T tmp = a;
    a = b;
    b = tmp;
}

template <typename T>
// using the median-of-three method to choose pivot, we can reduce the chances of worst-case performance on already sorted or nearly sorted arrays, since the pivot will be closer to the median value of the array segment.
void medianOfThree(T a[], int low, int high) {
    int mid = low + (high - low)/2;
    if (a[mid] < a[low]) mySwap(a[mid], a[low]);
    if(a[high] < a[low]) mySwap(a[high], a[low]);
    if(a[high] < a[mid]) mySwap(a[high], a[mid]);
    mySwap(a[low], a[mid]);
}

template <typename T>
// we use Hoare's partitioning scheme 
// to partition the array, because it performs better than Lomuto's scheme, since it does fewer swaps and works well with duplicate elements.
// it works by initializing two pointers that start at the ends of the array segment being partitioned, and move towards each other until they find elements that are on the wrong side of the pivot. When such elements are found, they are swapped. This continues until the pointers meet.
// in the end, it returns the index of the partition point.
int hoarePartition(T a[], int low, int high){
    medianOfThree(a, low, high);
    T pivot = a[low];
    int i = low - 1;
    int j = high + 1;
    
    while(true) {
        do {
            i++;
        } while(a[i] < pivot);  
        do {
            j--;
        } while(a[j] > pivot);
        if (i >= j) return j;
        mySwap(a[i], a[j]);
    }
}

// three way partitioning can be implemented to handle arrays with many duplicate elements more efficiently.
// template <typename T>
// int threeWayPartition(T a[], int low, int high, T pivot) {
//     int lt = low;     // We initialize lt to be the part that is less than pivot
//     int gt = high;    // We initialize gt to be the part that is greater than pivot
//     int i = low;      // We scan the array from left to right

//     while (i <= gt) {
//         if (a[i] < pivot) {
//             mySwap(a[lt], a[i]);
//             lt++;
//             i++;
//         } else if (a[i] > pivot) {
//             mySwap(a[i], a[gt]);
//             gt--;
//         } else {
//             i++;
//         }
//     }
//     return lt; // return the index of the first element equal to pivot
// }

template <typename T>
void quickSort(T a[], int low, int high){
    if (low < high) {
        int p = hoarePartition(a, low, high);
        quickSort(a, low, p);
        quickSort(a, p+1, high);
    }
}

//QUICKSORT VERSION USE

int main() {
    vector<int> a = {3, 7, 8, 5, 2, 1, 9, 5, 4};
    
    quickSort(a.data(), 0, (int)a.size() - 1); 
    
    for (size_t i = 0; i < a.size(); i++)
        cout << a[i] << " ";
    
    return 0;
}