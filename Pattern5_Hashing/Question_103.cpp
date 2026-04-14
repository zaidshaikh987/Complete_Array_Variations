// - All Pairs with Given Difference

#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

// Find all unique pairs (a, b) such that abs(a - b) = k.
void findPairsWithDiff(vector<int>& arr, int k) {
    unordered_set<int> seen;
    unordered_set<int> nums(arr.begin(), arr.end());
    bool found = false;

    for (int x : nums) {
        // Case 1: x - b = k => b = x - k
        // Case 2: b - x = k => b = x + k
        if (nums.count(x + k)) {
            cout << "(" << x << ", " << x + k << ")" << endl;
            found = true;
        }
    }

    if (!found) cout << "No pairs found with difference " << k << endl;
}

int main() {
    vector<int> arr = {1, 5, 3, 4, 2};
    int k = 3;
    cout << "Pairs with difference " << k << ":" << endl;
    findPairsWithDiff(arr, k);
    return 0;
}
