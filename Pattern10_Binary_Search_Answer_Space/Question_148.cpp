// - Find the Smallest Divisor Given a Threshold (Binary Search on Answer Space)

#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

// Find the smallest divisor 'd' such that the sum of ceil(num / d) <= threshold.
// Method: Binary Search (O(n log(max_val)))
long long calculateSum(vector<int>& nums, int divisor) {
    long long sum = 0;
    for (int x : nums) {
        sum += (x + divisor - 1) / divisor; // ceil(x / divisor)
    }
    return sum;
}

int smallestDivisor(vector<int>& nums, int threshold) {
    int low = 1, high = *max_element(nums.begin(), nums.end());
    int ans = high;

    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (calculateSum(nums, mid) <= threshold) {
            ans = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    return ans;
}

int main() {
    vector<int> nums = {1, 2, 5, 9};
    int threshold = 6;
    cout << "Smallest divisor: " << smallestDivisor(nums, threshold) << endl; // 5

    vector<int> nums2 = {44, 22, 33, 11, 1};
    threshold = 5;
    cout << "Smallest divisor: " << smallestDivisor(nums2, threshold) << endl; // 44
    
    return 0;
}
