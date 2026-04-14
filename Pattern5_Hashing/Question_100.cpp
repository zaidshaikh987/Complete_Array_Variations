// - Find All Duplicates in an Array

#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

// Find all elements that appear twice in an array where elements are in range [1, n].
// Method 1: Hashing (O(n) space)
vector<int> findDuplicatesHash(vector<int>& nums) {
    unordered_map<int, int> freq;
    for (int x : nums) freq[x]++;
    
    vector<int> result;
    for (auto const& [key, val] : freq) {
        if (val > 1) result.push_back(key);
    }
    return result;
}

// Method 2: In-place Negation (O(1) auxiliary space, O(n) time)
// Valid only if elements are in range [1, n] and appear at most twice.
vector<int> findDuplicatesInPlace(vector<int>& nums) {
    vector<int> result;
    for (int i = 0; i < nums.size(); i++) {
        int val = abs(nums[i]) - 1;
        if (nums[val] < 0) {
            result.push_back(val + 1);
        } else {
            nums[val] = -nums[val];
        }
    }
    return result;
}

int main() {
    vector<int> nums = {4, 3, 2, 7, 8, 2, 3, 1};
    vector<int> result = findDuplicatesHash(nums);
    
    cout << "Duplicates in array: ";
    for (int x : result) cout << x << " ";
    cout << endl;

    vector<int> nums2 = {4, 3, 2, 7, 8, 2, 3, 1};
    vector<int> result2 = findDuplicatesInPlace(nums2);
    cout << "Duplicates (In-place): ";
    for (int x : result2) cout << x << " ";
    cout << endl;

    return 0;
}
