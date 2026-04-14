// - Find First and Last Position of Element in Sorted Array

#include <iostream>
#include <vector>
using namespace std;

int findFirst(vector<int>& nums, int target) {
    int low = 0, high = nums.size() - 1, ans = -1;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (nums[mid] == target) {
            ans = mid;
            high = mid - 1; // Look on the left side
        } else if (nums[mid] < target) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return ans;
}

int findLast(vector<int>& nums, int target) {
    int low = 0, high = nums.size() - 1, ans = -1;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (nums[mid] == target) {
            ans = mid;
            low = mid + 1; // Look on the right side
        } else if (nums[mid] < target) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return ans;
}

int main() {
    vector<int> nums = {5, 7, 7, 8, 8, 10};
    int target = 8;
    int first = findFirst(nums, target);
    int last = findLast(nums, target);
    
    cout << "Range of " << target << ": [" << first << ", " << last << "]" << endl;
    return 0;
}
