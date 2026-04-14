// - Longest Subarray with Sum = K (Prefix Sum + Hashmap)

#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

// Find the length of the longest subarray that sums to K.
// This version handles negative numbers efficiently.
int longestSubarraySumK(vector<int>& arr, int k) {
    int n = arr.size();
    unordered_map<int, int> prefixSumIdx;
    int currentSum = 0;
    int maxLength = 0;

    for (int i = 0; i < n; i++) {
        currentSum += arr[i];

        if (currentSum == k) {
            maxLength = i + 1;
        }

        // If (currentSum - k) has occurred before, the subarray between
        // that index and current index sums to k.
        if (prefixSumIdx.find(currentSum - k) != prefixSumIdx.end()) {
            maxLength = max(maxLength, i - prefixSumIdx[currentSum - k]);
        }

        // Only store the first occurrence of currentSum to get the longest subarray
        if (prefixSumIdx.find(currentSum) == prefixSumIdx.end()) {
            prefixSumIdx[currentSum] = i;
        }
    }

    return maxLength;
}

int main() {
    vector<int> arr = {10, 5, 2, 7, 1, 9};
    int k = 15;
    cout << "Length of the longest subarray with sum " << k << ": " << longestSubarraySumK(arr, k) << endl;
    return 0;
}
