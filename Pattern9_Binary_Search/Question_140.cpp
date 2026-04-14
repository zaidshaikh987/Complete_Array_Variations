// - Search in a Rotated Sorted Array II (with duplicates)

#include <iostream>
#include <vector>
using namespace std;

// Find if target exists in a rotated sorted array with duplicates.
// Method: Binary Search (Worst case O(n))
bool searchRotatedII(vector<int>& nums, int target) {
    int low = 0, high = nums.size() - 1;

    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (nums[mid] == target) return true;

        // Skip duplicates
        if (nums[low] == nums[mid] && nums[mid] == nums[high]) {
            low++;
            high--;
            continue;
        }

        // Determine which side is sorted
        if (nums[low] <= nums[mid]) {
            // Left side is sorted
            if (target >= nums[low] && target < nums[mid]) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        } else {
            // Right side is sorted
            if (target > nums[mid] && target <= nums[high]) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
    }
    return false;
}

int main() {
    vector<int> nums = {2, 5, 6, 0, 0, 1, 2};
    int target = 0;
    cout << "Target " << target << " found: " << (searchRotatedII(nums, target) ? "Yes" : "No") << endl;

    target = 3;
    cout << "Target " << target << " found: " << (searchRotatedII(nums, target) ? "Yes" : "No") << endl;
    
    return 0;
}
