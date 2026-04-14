// - Find the Number that Appears Once (while others appear twice)

#include <iostream>
#include <vector>
using namespace std;

// Method 1: XOR (Optimal for space O(1))
int findOnceXOR(vector<int>& nums) {
    int xorValue = 0;
    for (int x : nums) xorValue ^= x;
    return xorValue;
}

int main() {
    vector<int> nums = {4, 1, 2, 1, 2};
    cout << "Number that appears once: " << findOnceXOR(nums) << endl;
    return 0;
}
