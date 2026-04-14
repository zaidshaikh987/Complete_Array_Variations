// - Search in a Rotated Sorted Array

#include <iostream>
#include <vector>
using namespace std;

// Find the index of target in an array that was originally sorted then rotated.
// Method: Binary Search (O(log n))
int searchRotated(vector<int>& nums, int target) {
    int low = 0, high = nums.size() - 1;

    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (nums[mid] == target) return mid;

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
    return -1;
}

int main() {
    vector<int> nums = {4, 5, 6, 7, 0, 1, 2};
    int target = 0;
    int result = searchRotated(nums, target);
    
    if (result != -1) {
        cout << "Target " << target << " found at index " << result << endl;
    } else {
        cout << "Target " << target << " not found." << endl;
    }
    
    return 0;
}
