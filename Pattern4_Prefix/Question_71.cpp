// - Count Subarrays with Sum Divisible by K

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

// Logic: (prefixSum[i] - prefixSum[j]) % k == 0 
// implies prefixSum[i] % k == prefixSum[j] % k
int subarraysDivByK(vector<int>& nums, int k) {
    int n = nums.size();
    unordered_map<int, int> modFreq;
    modFreq[0] = 1; // Base case

    int currentSum = 0;
    int count = 0;

    for (int x : nums) {
        currentSum += x;
        int mod = currentSum % k;
        
        // Handle negative modulo in C++
        if (mod < 0) mod += k;

        if (modFreq.count(mod)) {
            count += modFreq[mod];
        }
        modFreq[mod]++;
    }

    return count;
}

int main() {
    vector<int> nums = {4, 5, 0, -2, -3, 1};
    int k = 5;
    cout << "Number of subarrays with sum divisible by " << k << ": " << subarraysDivByK(nums, k) << endl;
    return 0;
}
