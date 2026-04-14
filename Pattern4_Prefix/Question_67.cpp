// - Longest Subarray with Given Sum K (Handles negatives)

#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

int longestSubarrayWithSumK(vector<int>& arr, int k) {
    int n = arr.size();
    unordered_map<int, int> prefixSumIdx;
    int currentSum = 0;
    int maxLen = 0;

    for (int i = 0; i < n; i++) {
        currentSum += arr[i];

        if (currentSum == k) {
            maxLen = i + 1;
        }

        // Check if (currentSum - k) has occurred before
        if (prefixSumIdx.find(currentSum - k) != prefixSumIdx.end()) {
            maxLen = max(maxLen, i - prefixSumIdx[currentSum - k]);
        }

        // Store the first occurrence of currentSum
        if (prefixSumIdx.find(currentSum) == prefixSumIdx.end()) {
            prefixSumIdx[currentSum] = i;
        }
    }

    return maxLen;
}

int main() {
    vector<int> arr1 = {10, 5, 2, 7, 1, 9};
    int k1 = 15;
    cout << "Length of the longest subarray with sum " << k1 << ": " << longestSubarrayWithSumK(arr1, k1) << endl;

    vector<int> arr2 = {-1, 2, 3};
    int k2 = 6;
    cout << "Length of the longest subarray with sum " << k2 << ": " << longestSubarrayWithSumK(arr2, k2) << endl;

    return 0;
}
