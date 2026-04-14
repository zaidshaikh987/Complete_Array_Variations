// - Find Peak Element

#include <iostream>
#include <vector>
using namespace std;

// Find a peak element (strictly greater than its neighbors).
// An element at index i is a peak if nums[i] > nums[i-1] and nums[i] > nums[i+1].
// Method: Binary Search (O(log n))
int findPeakElement(vector<int>& nums) {
    int low = 0, high = nums.size() - 1;

    while (low < high) {
        int mid = low + (high - low) / 2;

        if (nums[mid] < nums[mid + 1]) {
            // We are on an increasing slope, peak must be on the right
            low = mid + 1;
        } else {
            // We are on a decreasing slope, peak is at mid or on the left
            high = mid;
        }
    }
    return low;
}

int main() {
    vector<int> nums = {1, 2, 3, 1};
    cout << "Index of a peak element: " << findPeakElement(nums) << endl; // index 2 (value 3)

    vector<int> nums2 = {1, 2, 1, 3, 5, 6, 4};
    cout << "Index of a peak element: " << findPeakElement(nums2) << endl; // index 1 or 5
    
    return 0;
}
