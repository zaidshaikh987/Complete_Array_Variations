// - Maximum Size Subarray Sum Equals K

#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

// This is essentially the same as "Longest Subarray with Given Sum K"
int maxSubarrayLen(vector<int>& nums, int k) {
    int n = nums.size();
    unordered_map<int, int> prefixSumIdx;
    prefixSumIdx[0] = -1; // Base case for sum starting at index 0

    int currentSum = 0;
    int maxLen = 0;

    for (int i = 0; i < n; i++) {
        currentSum += nums[i];

        if (prefixSumIdx.count(currentSum - k)) {
            maxLen = max(maxLen, i - prefixSumIdx[currentSum - k]);
        }

        // Only store the first occurrence of currentSum to get the longest subarray
        if (prefixSumIdx.find(currentSum) == prefixSumIdx.end()) {
            prefixSumIdx[currentSum] = i;
        }
    }

    return maxLen;
}

int main() {
    vector<int> nums = {1, -1, 5, -2, 3};
    int k = 3;
    cout << "Max length subarray with sum " << k << ": " << maxSubarrayLen(nums, k) << endl; // index [2, 4] -> size 3

    vector<int> nums2 = {-2, -1, 2, 1};
    int k2 = 1;
    cout << "Max length subarray with sum " << k2 << ": " << maxSubarrayLen(nums2, k2) << endl; // index [2, 3] -> size 2
    
    return 0;
}
