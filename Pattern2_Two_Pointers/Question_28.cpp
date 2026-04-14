// - 4-Sum Problem

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void fourSum(vector<int>& nums, long long target) {
    int n = nums.size();
    sort(nums.begin(), nums.end());
    bool found = false;

    for (int i = 0; i < n - 3; i++) {
        // Skip duplicates for i
        if (i > 0 && nums[i] == nums[i - 1]) continue;
        
        for (int j = i + 1; j < n - 2; j++) {
            // Skip duplicates for j
            if (j > i + 1 && nums[j] == nums[j - 1]) continue;
            
            int left = j + 1;
            int right = n - 1;
            
            while (left < right) {
                long long sum = (long long)nums[i] + nums[j] + nums[left] + nums[right];
                
                if (sum == target) {
                    cout << "[" << nums[i] << ", " << nums[j] << ", " << nums[left] << ", " << nums[right] << "]" << endl;
                    found = true;
                    
                    // Skip duplicates for left and right
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
        }
    }

    if (!found) {
        cout << "No quadruplets found." << endl;
    }
}

int main() {
    int n;
    cout << "Enter the size of the array: ";
    cin >> n;

    vector<int> nums(n);
    cout << "Enter " << n << " elements: ";
    for (int i = 0; i < n; i++) cin >> nums[i];

    long long target;
    cout << "Enter the target sum: ";
    cin >> target;

    cout << "Unique quadruplets summing to " << target << ":" << endl;
    fourSum(nums, target);

    return 0;
}
