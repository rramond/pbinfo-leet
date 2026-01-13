#include <bits/stdc++.h>
using namespace std;

template <typename T>
void mySwap(T &a, T &b) {
    T tmp = a;
    a = b;
    b = tmp;
}

template <typename T>
void medianOfThree(T a[], int low, int high) {
    int mid = low + (high - low)/2;
    if (a[mid] < a[low]) mySwap(a[mid], a[low]);
    if(a[high] < a[low]) mySwap(a[high], a[low]);
    if(a[high] < a[mid]) mySwap(a[high], a[mid]);
    mySwap(a[low], a[mid]);
}

template <typename T>
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