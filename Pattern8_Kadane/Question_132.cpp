// - Maximum Product Subarray

#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

// Find the contiguous subarray which has the largest product.
int maxProduct(vector<int>& nums) {
    if (nums.empty()) return 0;

    int maxSoFar = nums[0];
    int minSoFar = nums[0];
    int result = nums[0];

    for (int i = 1; i < nums.size(); i++) {
        int x = nums[i];
        
        // If x is negative, max and min will swap
        if (x < 0) swap(maxSoFar, minSoFar);

        maxSoFar = max(x, maxSoFar * x);
        minSoFar = min(x, minSoFar * x);

        result = max(result, maxSoFar);
    }

    return result;
}

int main() {
    vector<int> nums = {2, 3, -2, 4};
    cout << "Maximum product subarray: " << maxProduct(nums) << endl; // {2, 3} -> 6

    vector<int> nums2 = {-2, 0, -1};
    cout << "Maximum product subarray: " << maxProduct(nums2) << endl; // 0
    
    return 0;
}
