// - Largest Subarray with 0 Sum (Prefix sum + Hashmap)

#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

int maxLenZeroSum(vector<int>& arr) {
    int n = arr.size();
    unordered_map<int, int> prefixSumIdx;
    int currentSum = 0;
    int maxLen = 0;

    for (int i = 0; i < n; i++) {
        currentSum += arr[i];

        if (currentSum == 0) {
            maxLen = i + 1;
        } else {
            if (prefixSumIdx.find(currentSum) != prefixSumIdx.end()) {
                maxLen = max(maxLen, i - prefixSumIdx[currentSum]);
            } else {
                prefixSumIdx[currentSum] = i;
            }
        }
    }

    return maxLen;
}

int main() {
    vector<int> arr = {15, -2, 2, -8, 1, 7, 10, 23};
    cout << "Length of the largest subarray with 0 sum: " << maxLenZeroSum(arr) << endl;
    return 0;
}
