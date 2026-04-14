// - Capacity To Ship Packages Within D Days (Binary Search on Answer Space)

#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>
using namespace std;

// Find the minimum weight capacity of a ship that will result in all packages 
// being shipped within 'days' days.
// Method: Binary Search (O(n log(sum_weights)))
bool canShip(vector<int>& weights, int days, int capacity) {
    int currentWeight = 0;
    int daysNeeded = 1;
    for (int w : weights) {
        if (currentWeight + w > capacity) {
            daysNeeded++;
            currentWeight = w;
            if (daysNeeded > days) return false;
        } else {
            currentWeight += w;
        }
    }
    return true;
}

int shipWithinDays(vector<int>& weights, int days) {
    int low = *max_element(weights.begin(), weights.end());
    int high = accumulate(weights.begin(), weights.end(), 0);
    int ans = high;

    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (canShip(weights, days, mid)) {
            ans = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    return ans;
}

int main() {
    vector<int> weights = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int days = 5;
    cout << "Minimum ship capacity: " << shipWithinDays(weights, days) << endl; // 15
    return 0;
}
