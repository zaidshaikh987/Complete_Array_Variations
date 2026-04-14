// - Aggressive Cows (Binary Search on Answer Space)

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Find the maximum possible minimum distance between 'k' cows placed in stalls.
// Method: Binary Search (O(n log(max_dist)))
bool canPlaceCows(vector<int>& stalls, int k, int minDist) {
    int count = 1;
    int lastPos = stalls[0];
    for (int i = 1; i < stalls.size(); i++) {
        if (stalls[i] - lastPos >= minDist) {
            count++;
            lastPos = stalls[i];
        }
        if (count >= k) return true;
    }
    return false;
}

int aggressiveCows(vector<int>& stalls, int k) {
    sort(stalls.begin(), stalls.end());
    int low = 1, high = stalls.back() - stalls[0];
    int ans = 1;

    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (canPlaceCows(stalls, k, mid)) {
            ans = mid;
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return ans;
}

int main() {
    vector<int> stalls = {1, 2, 8, 4, 9};
    int k = 3;
    // Sorted stalls: 1, 2, 4, 8, 9
    // Placements: {1, 4, 8} -> minDist 3; {1, 4, 9} -> minDist 3; {1, 2, 4} -> minDist 1
    // Max minDist is 3.
    cout << "Maximum minimum distance: " << aggressiveCows(stalls, k) << endl; // 3
    return 0;
}
