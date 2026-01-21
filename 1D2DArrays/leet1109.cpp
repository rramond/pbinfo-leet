#include <iostream>
#include <vector>
using namespace std;

 vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {
        vector<int> results(n);
        vector<int> diff(n+1, 0);
        for(auto& booking : bookings) {
            diff[booking[0]] += booking[2];
            diff[booking[1] + 1] -= booking[2];
        }
            results[0] += diff[1];
            for(size_t j = 1; j < (size_t)n; j++) {
                results[j] = results[j-1] + diff[j+1];
            }
        return results;
    }
int main() {
  int n;
  cin >> n;
  vector<vector<int>> bookings = {{1, 2, 10},{2,3,20},{2,5,25}};
  vector<int> results = corpFlightBookings(bookings, n);
  
  for(auto v : results)
    cout << v << " ";
}