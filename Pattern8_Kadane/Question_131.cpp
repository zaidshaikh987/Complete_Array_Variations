// - Smallest Subarray Sum (Variation of Kadane's Algorithm)

#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
using namespace std;

// Find the contiguous subarray which has the smallest sum.
int minSubarraySum(vector<int>& nums) {
    int minSoFar = INT_MAX;
    int currentSum = 0;

    for (int x : nums) {
        currentSum += x;
        minSoFar = min(minSoFar, currentSum);
        if (currentSum > 0) {
            currentSum = 0;
        }
    }
    return minSoFar;
}

int main() {
    vector<int> nums = {3, -4, 2, -3, -1, 7, -5};
    cout << "Smallest subarray sum: " << minSubarraySum(nums) << endl; // {-4,2,-3,-1} -> -6
    return 0;
}
