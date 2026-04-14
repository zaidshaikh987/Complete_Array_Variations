// - Split Array Largest Sum (Allocate Books / Painter's Partition)

#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>
using namespace std;

// Find the minimum value of the largest sum of any subarray when the array is 
// split into 'k' contiguous subarrays.
// Method: Binary Search (O(n log(sum_weights)))
bool canSplit(vector<int>& nums, int k, int maxSum) {
    int currentSum = 0;
    int subarrays = 1;
    for (int x : nums) {
        if (currentSum + x > maxSum) {
            subarrays++;
            currentSum = x;
            if (subarrays > k) return false;
        } else {
            currentSum += x;
        }
    }
    return true;
}

int splitArray(vector<int>& nums, int k) {
    int low = *max_element(nums.begin(), nums.end());
    int high = accumulate(nums.begin(), nums.end(), 0);
    int ans = high;

    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (canSplit(nums, k, mid)) {
            ans = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    return ans;
}

int main() {
    vector<int> nums = {7, 2, 5, 10, 8};
    int k = 2;
    // Possible splits for k=2:
    // [7],[2,5,10,8] -> max 25
    // [7,2],[5,10,8] -> max 23
    // [7,2,5],[10,8] -> max 18 (Ans)
    // [7,2,5,10],[8] -> max 24
    cout << "Minimum largest sum: " << splitArray(nums, k) << endl; // 18
    return 0;
}
