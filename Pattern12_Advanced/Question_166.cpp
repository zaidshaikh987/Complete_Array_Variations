// - Find the Next Permutation

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Find the next lexicographically greater permutation of numbers.
// Method: 4-step algorithm (O(n))
void nextPermutation(vector<int>& nums) {
    int n = nums.size();
    if (n < 2) return;

    // 1. Find the first decreasing element from the right
    int i = n - 2;
    while (i >= 0 && nums[i] >= nums[i + 1]) {
        i--;
    }

    if (i >= 0) {
        // 2. Find the index to swap with (smallest element > nums[i])
        int j = n - 1;
        while (nums[j] <= nums[i]) {
            j--;
        }
        // 3. Swap nums[i] and nums[j]
        swap(nums[i], nums[j]);
    }

    // 4. Reverse the suffix starting at i + 1
    reverse(nums.begin() + i + 1, nums.end());
}

void printArray(vector<int>& nums) {
    for (int x : nums) cout << x << " ";
    cout << endl;
}

int main() {
    vector<int> nums = {1, 2, 3};
    cout << "Original permutation: ";
    printArray(nums);

    nextPermutation(nums);
    cout << "Next permutation: ";
    printArray(nums); // 1, 3, 2

    vector<int> nums2 = {3, 2, 1};
    cout << endl << "Original permutation: ";
    printArray(nums2);

    nextPermutation(nums2);
    cout << "Next permutation: ";
    printArray(nums2); // 1, 2, 3

    return 0;
}
