// - Single Element in a Sorted Array

#include <iostream>
#include <vector>
using namespace std;

// Find the only element that appears exactly once in an array where 
// every other element appears exactly twice.
// Method: Binary Search (O(log n))
int singleNonDuplicate(vector<int>& nums) {
    int low = 0, high = nums.size() - 2;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        // Check the pairing property
        // For even mid: mid and mid+1 should be equal
        // For odd mid: mid and mid-1 should be equal
        if (mid % 2 == 0) {
            if (nums[mid] == nums[mid + 1]) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        } else {
            if (nums[mid] == nums[mid - 1]) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
    }
    return nums[low];
}

int main() {
    vector<int> nums = {1, 1, 2, 3, 3, 4, 4, 8, 8};
    cout << "Single element: " << singleNonDuplicate(nums) << endl; // 2

    vector<int> nums2 = {3, 3, 7, 7, 10, 11, 11};
    cout << "Single element: " << singleNonDuplicate(nums2) << endl; // 10
    
    return 0;
}
