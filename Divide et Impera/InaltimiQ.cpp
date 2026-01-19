#include <iostream>
#include <utility>
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

int main() {
    int n;
    cin >> n;
    
    pair<int, int> v[100001];
    
    for (int i = 1; i <= n; i++){
        int val;
        cin >> val;
        v[i] = {val, i};
    }
    
    quickSort(v, 1, n); 
    
    for (int i = 1; i <= n; i++)
        cout << v[i].second << " ";
    
    return 0;
}