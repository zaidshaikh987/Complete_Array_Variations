// - Maximum Sum with No Two Elements Adjacent (House Robber Problem)

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Find the maximum sum of a subsequence such that no two elements are adjacent.
// Method: Dynamic Programming (O(n) time, O(1) space)
int maxNonAdjacentSum(vector<int>& arr) {
    int n = arr.size();
    if (n == 0) return 0;
    if (n == 1) return arr[0];

    int prev2 = 0; // max sum ending 2 steps back
    int prev1 = arr[0]; // max sum ending 1 step back

    for (int i = 1; i < n; i++) {
        int take = arr[i] + prev2;
        int skip = prev1;
        int current = max(take, skip);
        
        prev2 = prev1;
        prev1 = current;
    }
    return prev1;
}

int main() {
    vector<int> arr = {5, 5, 10, 100, 10, 5};
    cout << "Maximum sum with no two elements adjacent: " << maxNonAdjacentSum(arr) << endl; // 5 + 100 + 5 = 110
    
    vector<int> arr2 = {1, 2, 3};
    cout << "Maximum sum with no two elements adjacent: " << maxNonAdjacentSum(arr2) << endl; // 4
    
    return 0;
}
