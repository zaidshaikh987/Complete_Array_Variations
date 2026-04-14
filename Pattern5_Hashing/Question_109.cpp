// - Maximum Length Subarray with Sum at Most K

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Find the length of the longest subarray with sum <= k.
// Method: Sliding Window (O(n)) - only works if all numbers are non-negative.
// If negative numbers are allowed, we need a prefix sum + monotonic queue or binary search approach.
int maxLengthSubarraySumAtMostK(vector<int>& arr, int k) {
    int n = arr.size();
    int left = 0, currentSum = 0, maxLen = 0;

    for (int right = 0; right < n; right++) {
        currentSum += arr[right];

        while (currentSum > k && left <= right) {
            currentSum -= arr[left];
            left++;
        }

        maxLen = max(maxLen, right - left + 1);
    }

    return maxLen;
}

int main() {
    vector<int> arr = {1, 2, 1, 0, 1, 1, 0};
    int k = 4;
    cout << "Maximum length subarray with sum at most " << k << ": " << maxLengthSubarraySumAtMostK(arr, k) << endl;
    return 0;
}
