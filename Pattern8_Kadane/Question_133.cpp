// - Longest Subarray with Sum > 0

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Find the length of the longest subarray with a positive sum.
// Method: Prefix Sum + Monotonic Stack (O(n log n) or O(n))
int longestSubarrayPositiveSum(vector<int>& nums) {
    int n = nums.size();
    vector<pair<long long, int>> prefixSum(n + 1);
    prefixSum[0] = {0, 0};
    
    long long current = 0;
    for (int i = 0; i < n; i++) {
        current += nums[i];
        prefixSum[i + 1] = {current, i + 1};
    }

    // This is essentially finding max(j - i) such that prefixSum[j] > prefixSum[i]
    // A simpler O(n log n) approach:
    sort(prefixSum.begin(), prefixSum.end());

    int maxLen = 0;
    int minIdx = prefixSum[0].second;

    for (int i = 1; i <= n; i++) {
        if (prefixSum[i].second > minIdx) {
            maxLen = max(maxLen, prefixSum[i].second - minIdx);
        }
        minIdx = min(minIdx, prefixSum[i].second);
    }

    return maxLen;
}

int main() {
    vector<int> nums = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    cout << "Longest subarray with sum > 0 length: " << longestSubarrayPositiveSum(nums) << endl;
    return 0;
}
