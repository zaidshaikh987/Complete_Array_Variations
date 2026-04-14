// - Koko Eating Bananas (Binary Search on Answer Space)

#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

// Find the minimum integer speed 'k' such that Koko can eat all bananas within 'h' hours.
// Method: Binary Search (O(n log(max_piles)))
bool canEatAll(vector<int>& piles, int h, int k) {
    long long hoursSpent = 0;
    for (int pile : piles) {
        hoursSpent += (pile + k - 1) / k; // Equivalent to ceil(pile / k)
    }
    return hoursSpent <= h;
}

int minEatingSpeed(vector<int>& piles, int h) {
    int low = 1, high = *max_element(piles.begin(), piles.end());
    int ans = high;

    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (canEatAll(piles, h, mid)) {
            ans = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    return ans;
}

int main() {
    vector<int> piles = {3, 6, 7, 11};
    int h = 8;
    cout << "Minimum eating speed: " << minEatingSpeed(piles, h) << endl; // 4
    return 0;
}
