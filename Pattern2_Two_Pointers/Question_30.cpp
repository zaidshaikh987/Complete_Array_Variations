// - Minimize Maximum Pair Sum in Array

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// The logic is to sort the array and pair the smallest element with the largest,
// the second smallest with the second largest, and so on.
// This minimizes the maximum sum of pairs.

int minMaxPairSum(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    int n = nums.size();
    int minMaxSum = 0;
    
    for (int i = 0; i < n / 2; i++) {
        int currentPairSum = nums[i] + nums[n - 1 - i];
        minMaxSum = max(minMaxSum, currentPairSum);
    }
    
    return minMaxSum;
}

int main() {
    int n;
    cout << "Enter the size of the array (must be even): ";
    cin >> n;

    if (n % 2 != 0) {
        cout << "Array size must be even for complete pairing." << endl;
        return 1;
    }

    vector<int> nums(n);
    cout << "Enter " << n << " elements: ";
    for (int i = 0; i < n; i++) cin >> nums[i];

    int result = minMaxPairSum(nums);
    cout << "The minimized maximum pair sum is: " << result << endl;

    return 0;
}
