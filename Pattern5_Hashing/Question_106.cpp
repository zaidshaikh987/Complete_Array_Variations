// - Subarrays with Equal Number of 0s and 1s (Prefix Sum + Hashmap)

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

// Find the length of the longest subarray with an equal number of 0s and 1s.
// Replace 0 with -1 and find the longest subarray with sum 0.
int findMaxLengthEqual01(vector<int>& nums) {
    int n = nums.size();
    unordered_map<int, int> prefixSumIdx;
    prefixSumIdx[0] = -1; // Base case

    int currentSum = 0;
    int maxLen = 0;

    for (int i = 0; i < n; i++) {
        currentSum += (nums[i] == 1 ? 1 : -1);

        if (prefixSumIdx.find(currentSum) != prefixSumIdx.end()) {
            maxLen = max(maxLen, i - prefixSumIdx[currentSum]);
        } else {
            prefixSumIdx[currentSum] = i;
        }
    }

    return maxLen;
}

int main() {
    vector<int> nums = {0, 1, 0, 1};
    cout << "Length of the longest subarray with equal 0s and 1s: " << findMaxLengthEqual01(nums) << endl;
    return 0;
}
