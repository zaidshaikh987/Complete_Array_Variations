// - Find the Missing Number in a Range [1, n]

#include <iostream>
#include <vector>
#include <numeric>
using namespace std;

// Method 1: Math (Sum of first n numbers)
int findMissingMath(vector<int>& nums, int n) {
    long long expectedSum = (long long)n * (n + 1) / 2;
    long long actualSum = accumulate(nums.begin(), nums.end(), 0LL);
    return expectedSum - actualSum;
}

// Method 2: XOR 
int findMissingXOR(vector<int>& nums, int n) {
    int xorValue = 0;
    for (int i = 1; i <= n; i++) xorValue ^= i;
    for (int x : nums) xorValue ^= x;
    return xorValue;
}

int main() {
    vector<int> nums = {1, 2, 4, 5, 6}; // n = 6, missing = 3
    int n = 6;
    
    cout << "Missing number (Math): " << findMissingMath(nums, n) << endl;
    cout << "Missing number (XOR): " << findMissingXOR(nums, n) << endl;
    
    return 0;
}
