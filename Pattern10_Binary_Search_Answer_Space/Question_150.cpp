// - Median of Two Sorted Arrays (Binary Search on Partitions)

#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

// Find the median of two sorted arrays of sizes m and n.
// Method: Binary Search on the smaller array (O(log(min(m, n))))
double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
    if (nums1.size() > nums2.size()) return findMedianSortedArrays(nums2, nums1);

    int m = nums1.size();
    int n = nums2.size();
    int low = 0, high = m;

    while (low <= high) {
        int partition1 = low + (high - low) / 2;
        int partition2 = (m + n + 1) / 2 - partition1;

        int maxLeft1 = (partition1 == 0) ? INT_MIN : nums1[partition1 - 1];
        int minRight1 = (partition1 == m) ? INT_MAX : nums1[partition1];

        int maxLeft2 = (partition2 == 0) ? INT_MIN : nums2[partition2 - 1];
        int minRight2 = (partition2 == n) ? INT_MAX : nums2[partition2];

        if (maxLeft1 <= minRight2 && maxLeft2 <= minRight1) {
            // Found the right partition
            if ((m + n) % 2 == 0) {
                return (double)(max(maxLeft1, maxLeft2) + min(minRight1, minRight2)) / 2.0;
            } else {
                return (double)max(maxLeft1, maxLeft2);
            }
        } else if (maxLeft1 > minRight2) {
            // Move left in nums1
            high = partition1 - 1;
        } else {
            // Move right in nums1
            low = partition1 + 1;
        }
    }
    return 0.0;
}

int main() {
    vector<int> nums1 = {1, 3}, nums2 = {2};
    cout << "Median: " << findMedianSortedArrays(nums1, nums2) << endl; // 2.0

    vector<int> nums3 = {1, 2}, nums4 = {3, 4};
    cout << "Median: " << findMedianSortedArrays(nums3, nums4) << endl; // 2.5
    
    return 0;
}
