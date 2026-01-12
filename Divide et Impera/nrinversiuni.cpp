#include <iostream>
using namespace std;

long long mergeAndCount(int v[], int temp[], int left, int mid, int right) {
    int i = left;    
    int j = mid + 1;
    int k = left;    
    long long inv_count = 0;
    
    while (i <= mid && j <= right) {
        if (v[i] <= v[j]) {
            temp[k++] = v[i++];
        } else {
            temp[k++] = v[j++];
            
            inv_count += (mid - i + 1);
        }
    }
    
    while (i <= mid)
        temp[k++] = v[i++];
    while (j <= right)
        temp[k++] = v[j++];
    
 
    for (i = left; i <= right; i++)
        v[i] = temp[i];
    
    return inv_count;
}

long long mergeSortAndCount(int v[], int temp[], int left, int right) {
    long long inv_count = 0;
    if (left < right) {
        int mid = left + (right - left) / 2;
        
        inv_count += mergeSortAndCount(v, temp, left, mid);
        inv_count += mergeSortAndCount(v, temp, mid + 1, right);
        inv_count += mergeAndCount(v, temp, left, mid, right);
    }
    return inv_count;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n, v[100000];
    cin >> n;
    
    for (int i = 0; i < n; i++)
        cin >> v[i];
    
    int temp[100000];
    long long S = mergeSortAndCount(v, temp, 0, n - 1);
    
    cout << S;
    
    return 0;
}