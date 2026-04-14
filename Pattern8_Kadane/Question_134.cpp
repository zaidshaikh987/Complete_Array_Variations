// - Maximum Sum Circular Subarray (Kadane's Variation)

#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>
using namespace std;

// The maximum sum can be either:
// 1. A normal subarray (standard Kadane)
// 2. A circular subarray (TotalSum - MinimumSubarraySum)
int maxCircularSum(vector<int>& nums) {
    int totalSum = 0;
    int maxKadane = 0, currentMax = 0;
    int minKadane = 0, currentMin = 0;
    int maxVal = nums[0]; // For all-negative case

    for (int x : nums) {
        totalSum += x;
        maxVal = max(maxVal, x);

        currentMax = max(x, currentMax + x);
        maxKadane = max(maxKadane, currentMax);

        currentMin = min(x, currentMin + x);
        minKadane = min(minKadane, currentMin);
    }

    // If all numbers are negative, Kadane's max would be 0 or negative.
    // In that case, max circular sum is just the largest single element.
    if (maxVal < 0) return maxVal;

    return max(maxKadane, totalSum - minKadane);
}

int main() {
    vector<int> nums = {5, -3, 5};
    cout << "Maximum circular subarray sum: " << maxCircularSum(nums) << endl; // {5, 5} (circular) -> 10
    
    vector<int> nums2 = {1, -2, 3, -2};
    cout << "Maximum circular subarray sum: " << maxCircularSum(nums2) << endl; // {3} -> 3
    
    return 0;
}
