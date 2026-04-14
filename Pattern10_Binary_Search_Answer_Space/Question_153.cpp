// - K-th Element of Two Sorted Arrays (Binary Search on Partitions)

#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

// Find the k-th element in the union of two sorted arrays.
// Method: Binary Search on partitions (O(log(min(m, n))))
int kthElement(vector<int>& nums1, vector<int>& nums2, int k) {
    if (nums1.size() > nums2.size()) return kthElement(nums2, nums1, k);

    int m = nums1.size();
    int n = nums2.size();
    
    // We search for a partition in nums1
    // Number of elements from nums1 must be between [max(0, k-n), min(k, m)]
    int low = max(0, k - n), high = min(k, m);

    while (low <= high) {
        int partition1 = low + (high - low) / 2;
        int partition2 = k - partition1;

        int maxLeft1 = (partition1 == 0) ? INT_MIN : nums1[partition1 - 1];
        int minRight1 = (partition1 == m) ? INT_MAX : nums1[partition1];

        int maxLeft2 = (partition2 == 0) ? INT_MIN : nums2[partition2 - 1];
        int minRight2 = (partition2 == n) ? INT_MAX : nums2[partition2];

        if (maxLeft1 <= minRight2 && maxLeft2 <= minRight1) {
            return max(maxLeft1, maxLeft2);
        } else if (maxLeft1 > minRight2) {
            high = partition1 - 1;
        } else {
            low = partition1 + 1;
        }
    }
    return -1;
}

int main() {
    vector<int> nums1 = {2, 3, 6, 7, 9};
    vector<int> nums2 = {1, 4, 8, 10};
    int k = 5;
    // Union: 1, 2, 3, 4, 6, 7, 8, 9, 10
    // 5th element is 6.
    cout << k << "-th element: " << kthElement(nums1, nums2, k) << endl; // 6
    return 0;
}
