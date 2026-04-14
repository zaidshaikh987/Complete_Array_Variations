// - Longest Subarray with Equal 0s and 1s (0->-1 trick)

#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

// The core trick is to treat 0 as -1.
// Then we find the longest subarray with sum 0.
// Although this is a prefix-sum + hashmap problem, it is often grouped with sliding window concepts.

int longestEqualZerosOnes(vector<int>& arr) {
    int n = arr.size();
    unordered_map<int, int> prefixSumIdx;
    int currentSum = 0;
    int maxLength = 0;

    // Handle case where sum becomes 0 from the start
    prefixSumIdx[0] = -1;

    for (int i = 0; i < n; i++) {
        currentSum += (arr[i] == 1 ? 1 : -1);

        if (prefixSumIdx.find(currentSum) != prefixSumIdx.end()) {
            maxLength = max(maxLength, i - prefixSumIdx[currentSum]);
        } else {
            prefixSumIdx[currentSum] = i;
        }
    }

    return maxLength;
}

int main() {
    int n;
    cout << "Enter the size of the binary array (0s and 1s): ";
    cin >> n;

    vector<int> arr(n);
    cout << "Enter " << n << " elements: ";
    for (int i = 0; i < n; i++) cin >> arr[i];

    int result = longestEqualZerosOnes(arr);
    cout << "Length of the longest subarray with equal 0s and 1s is: " << result << endl;

    return 0;
}
