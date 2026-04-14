// - Minimum Number of Days to Make m Bouquets (Binary Search on Answer Space)

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Find the minimum day 'd' such that we can make 'm' bouquets of 'k' adjacent flowers.
// Method: Binary Search (O(n log(max_day)))
bool canMakeBouquets(vector<int>& bloomDay, int m, int k, int day) {
    int bouquets = 0;
    int adjacent = 0;
    for (int d : bloomDay) {
        if (d <= day) {
            adjacent++;
            if (adjacent == k) {
                bouquets++;
                adjacent = 0;
            }
        } else {
            adjacent = 0;
        }
    }
    return bouquets >= m;
}

int minDays(vector<int>& bloomDay, int m, int k) {
    long long totalNeeded = (long long)m * k;
    if (totalNeeded > bloomDay.size()) return -1;

    int low = *min_element(bloomDay.begin(), bloomDay.end());
    int high = *max_element(bloomDay.begin(), bloomDay.end());
    int ans = -1;

    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (canMakeBouquets(bloomDay, m, k, mid)) {
            ans = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    return ans;
}

int main() {
    vector<int> bloomDay = {7, 7, 7, 7, 12, 7, 7};
    int m = 2, k = 3;
    cout << "Minimum days: " << minDays(bloomDay, m, k) << endl; // 12
    return 0;
}
