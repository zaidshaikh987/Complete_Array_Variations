// - 3-Sum (Unsorted)

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Find all unique triplets in the array which gives the sum of zero.
// Method: Sorting + Two Pointers (O(n^2))
vector<vector<int>> threeSum(vector<int>& nums) {
    int n = nums.size();
    sort(nums.begin(), nums.end());
    vector<vector<int>> result;

    for (int i = 0; i < n; i++) {
        // Skip duplicate elements for i
        if (i > 0 && nums[i] == nums[i - 1]) continue;

        int target = -nums[i];
        int left = i + 1, right = n - 1;

        while (left < right) {
            int currentSum = nums[left] + nums[right];
            if (currentSum == target) {
                result.push_back({nums[i], nums[left], nums[right]});
                left++;
                right--;
                // Skip duplicate elements for left and right
                while (left < right && nums[left] == nums[left - 1]) left++;
                while (left < right && nums[right] == nums[right + 1]) right--;
            } else if (currentSum < target) {
                left++;
            } else {
                right--;
            }
        }
    }
    return result;
}

int main() {
    vector<int> nums = {-1, 0, 1, 2, -1, -4};
    vector<vector<int>> result = threeSum(nums);

    cout << "Unique triplets with sum 0:" << endl;
    for (const auto& triplet : result) {
        cout << "[" << triplet[0] << ", " << triplet[1] << ", " << triplet[2] << "]" << endl;
    }
    return 0;
}
