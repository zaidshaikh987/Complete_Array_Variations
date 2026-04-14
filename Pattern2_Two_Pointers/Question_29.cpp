// - K-Sum Problem (generalize to k > 2)

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Recursive helper for K-Sum
void kSumHelper(vector<int>& nums, long long target, int k, int start, vector<int>& current, vector<vector<int>>& result) {
    int n = nums.size();
    
    // Base Case: 2-Sum
    if (k == 2) {
        int left = start, right = n - 1;
        while (left < right) {
            long long sum = (long long)nums[left] + nums[right];
            if (sum == target) {
                vector<int> temp = current;
                temp.push_back(nums[left]);
                temp.push_back(nums[right]);
                result.push_back(temp);
                
                while (left < right && nums[left] == nums[left + 1]) left++;
                while (left < right && nums[right] == nums[right - 1]) right--;
                left++;
                right--;
            } else if (sum < target) {
                left++;
            } else {
                right--;
            }
        }
        return;
    }

    // Recursive Case: Reduce K to K-1
    for (int i = start; i <= n - k; i++) {
        if (i > start && nums[i] == nums[i - 1]) continue;
        
        current.push_back(nums[i]);
        kSumHelper(nums, target - nums[i], k - 1, i + 1, current, result);
        current.pop_back(); // Backtrack
    }
}

vector<vector<int>> kSum(vector<int>& nums, long long target, int k) {
    sort(nums.begin(), nums.end());
    vector<vector<int>> result;
    vector<int> current;
    kSumHelper(nums, target, k, 0, current, result);
    return result;
}

int main() {
    int n, k;
    cout << "Enter the size of the array: ";
    cin >> n;
    cout << "Enter k (number of elements in sum): ";
    cin >> k;

    vector<int> nums(n);
    cout << "Enter " << n << " elements: ";
    for (int i = 0; i < n; i++) cin >> nums[i];

    long long target;
    cout << "Enter the target sum: ";
    cin >> target;

    vector<vector<int>> results = kSum(nums, target, k);

    cout << "Unique " << k << "-sized sets summing to " << target << ":" << endl;
    for (const auto& set : results) {
        cout << "[ ";
        for (int x : set) cout << x << " ";
        cout << "]" << endl;
    }
    
    if (results.empty()) cout << "No sets found." << endl;

    return 0;
}
