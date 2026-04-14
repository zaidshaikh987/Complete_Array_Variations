// - Subarray Sum Equals K (Prefix sum + Hashmap)

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int subarraySum(vector<int>& nums, int k) {
    int n = nums.size();
    unordered_map<int, int> prefixSumFreq;
    prefixSumFreq[0] = 1; // Base case for subarrays starting from index 0

    int currentSum = 0;
    int count = 0;

    for (int i = 0; i < n; i++) {
        currentSum += nums[i];

        // If (currentSum - k) exists in the map, it means there's a subarray
        // ending at i with sum k.
        if (prefixSumFreq.find(currentSum - k) != prefixSumFreq.end()) {
            count += prefixSumFreq[currentSum - k];
        }

        prefixSumFreq[currentSum]++;
    }

    return count;
}

int main() {
    vector<int> nums = {1, 1, 1};
    int k = 2;
    cout << "Number of subarrays with sum " << k << ": " << subarraySum(nums, k) << endl;

    vector<int> nums2 = {1, 2, 3};
    int k2 = 3;
    cout << "Number of subarrays with sum " << k2 << ": " << subarraySum(nums2, k2) << endl;

    return 0;
}
