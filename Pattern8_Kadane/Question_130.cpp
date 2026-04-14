// - Maximum Subarray Sum (Kadane's Algorithm)

#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
using namespace std;

// Find the contiguous subarray (containing at least one number) which 
// has the largest sum.
int maxSubarraySum(vector<int>& nums) {
    int maxSoFar = INT_MIN;
    int currentSum = 0;

    for (int x : nums) {
        currentSum += x;
        maxSoFar = max(maxSoFar, currentSum);
        if (currentSum < 0) {
            currentSum = 0;
        }
    }
    return maxSoFar;
}

int main() {
    vector<int> nums = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    cout << "Maximum subarray sum (Kadane): " << maxSubarraySum(nums) << endl; // {4,-1,2,1} -> 6
    return 0;
}
