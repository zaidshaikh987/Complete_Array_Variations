// - Two-Sum (on an unsorted array)

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

// Find indices of two numbers that sum to target
pair<int, int> twoSum(vector<int>& nums, int target) {
    unordered_map<int, int> seen;
    for (int i = 0; i < nums.size(); i++) {
        int complement = target - nums[i];
        if (seen.count(complement)) {
            return {seen[complement], i};
        }
        seen[nums[i]] = i;
    }
    return {-1, -1};
}

int main() {
    vector<int> nums = {2, 7, 11, 15};
    int target = 9;
    pair<int, int> result = twoSum(nums, target);
    
    if (result.first != -1) {
        cout << "Indices: " << result.first << ", " << result.second << endl;
    } else {
        cout << "No pair found." << endl;
    }
    
    return 0;
}
