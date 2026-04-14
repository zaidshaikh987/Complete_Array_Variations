// - Majority Element (> n/2 times)

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

// Method 1: Hashing (O(n) space)
int majorityElementHash(vector<int>& nums) {
    int n = nums.size();
    unordered_map<int, int> freq;
    for (int x : nums) {
        freq[x]++;
        if (freq[x] > n / 2) return x;
    }
    return -1;
}

// Method 2: Boyer-Moore Voting Algorithm (O(1) space)
int majorityElementVoting(vector<int>& nums) {
    int candidate = 0, count = 0;
    for (int x : nums) {
        if (count == 0) {
            candidate = x;
            count = 1;
        } else if (candidate == x) {
            count++;
        } else {
            count--;
        }
    }
    return candidate;
}

int main() {
    vector<int> nums = {2, 2, 1, 1, 1, 2, 2};
    cout << "Majority Element (Hash): " << majorityElementHash(nums) << endl;
    cout << "Majority Element (Voting): " << majorityElementVoting(nums) << endl;
    return 0;
}
