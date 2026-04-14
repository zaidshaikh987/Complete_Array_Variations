// - 4-Sum (Unsorted)

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Find all unique quadruplets in the array which gives the sum of target.
// Method: Sorting + Three Nested Loops + Two Pointers (O(n^3))
vector<vector<int>> fourSum(vector<int>& nums, int target) {
    int n = nums.size();
    sort(nums.begin(), nums.end());
    vector<vector<int>> result;

    for (int i = 0; i < n; i++) {
        if (i > 0 && nums[i] == nums[i - 1]) continue;
        for (int j = i + 1; j < n; j++) {
            if (j > i + 1 && nums[j] == nums[j - 1]) continue;

            long long newTarget = (long long)target - nums[i] - nums[j];
            int left = j + 1, right = n - 1;

            while (left < right) {
                int currentSum = nums[left] + nums[right];
                if (currentSum == newTarget) {
                    result.push_back({nums[i], nums[j], nums[left], nums[right]});
                    left++;
                    right--;
                    while (left < right && nums[left] == nums[left - 1]) left++;
                    while (left < right && nums[right] == nums[right + 1]) right--;
                } else if (currentSum < newTarget) {
                    left++;
                } else {
                    right--;
                }
            }
        }
    }
    return result;
}

int main() {
    vector<int> nums = {1, 0, -1, 0, -2, 2};
    int target = 0;
    vector<vector<int>> result = fourSum(nums, target);

    cout << "Unique quadruplets with sum " << target << ":" << endl;
    for (const auto& quad : result) {
        cout << "[" << quad[0] << ", " << quad[1] << ", " << quad[2] << ", " << quad[3] << "]" << endl;
    }
    return 0;
}
