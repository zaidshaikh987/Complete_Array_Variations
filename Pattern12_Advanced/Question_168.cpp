// - Minimum Swaps to Sort an Array

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Find the minimum number of swaps required to sort an array.
// Method: Cycle Decomposition (O(n log n))
int minSwaps(vector<int>& arr) {
    int n = arr.size();
    vector<pair<int, int>> pos(n);
    for (int i = 0; i < n; i++) {
        pos[i] = {arr[i], i};
    }

    // Sort the pairs based on values
    sort(pos.begin(), pos.end());

    vector<bool> visited(n, false);
    int ans = 0;

    for (int i = 0; i < n; i++) {
        // If element is already in correct position or already visited
        if (visited[i] || pos[i].second == i) {
            continue;
        }

        // Find cycle size
        int cycle_size = 0;
        int j = i;
        while (!visited[j]) {
            visited[j] = true;
            j = pos[j].second;
            cycle_size++;
        }

        if (cycle_size > 0) {
            ans += (cycle_size - 1);
        }
    }
    return ans;
}

int main() {
    vector<int> arr = {4, 3, 2, 1};
    cout << "Minimum swaps to sort the array: " << minSwaps(arr) << endl; // 2
    
    vector<int> arr2 = {1, 5, 4, 3, 2};
    cout << "Minimum swaps to sort the array: " << minSwaps(arr2) << endl; // 2
    
    return 0;
}
