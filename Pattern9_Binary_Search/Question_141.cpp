// - Find Minimum in Rotated Sorted Array

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Find the minimum element in an array that was originally sorted then rotated.
// Method: Binary Search (O(log n))
int findMin(vector<int>& nums) {
    int low = 0, high = nums.size() - 1;
    int ans = nums[0];

    while (low <= high) {
        int mid = low + (high - low) / 2;

        // If the subarray is already sorted, the minimum is at the low index.
        if (nums[low] <= nums[high]) {
            ans = min(ans, nums[low]);
            break;
        }

        if (nums[low] <= nums[mid]) {
            // Left side is sorted, minimum must be on the right side
            ans = min(ans, nums[low]);
            low = mid + 1;
        } else {
            // Right side is sorted, minimum is on the left side or at mid
            ans = min(ans, nums[mid]);
            high = mid - 1;
        }
    }
    return ans;
}

int main() {
    vector<int> nums = {4, 5, 6, 7, 0, 1, 2};
    cout << "Minimum element: " << findMin(nums) << endl; // 0

    vector<int> nums2 = {3, 4, 5, 1, 2};
    cout << "Minimum element: " << findMin(nums2) << endl; // 1

    vector<int> nums3 = {11, 13, 15, 17};
    cout << "Minimum element: " << findMin(nums3) << endl; // 11
    
    return 0;
}
