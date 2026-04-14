// - Find Subarray with Given XOR (O(n) using Prefix XOR and Hashing)

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

// Find the first subarray whose XOR sum equals k.
pair<int, int> findSubarrayGivenXOR(vector<int>& arr, int k) {
    int n = arr.size();
    unordered_map<int, int> prefixXorIdx;
    prefixXorIdx[0] = -1; // Base case for XOR starting from index 0

    int currentXor = 0;

    for (int i = 0; i < n; i++) {
        currentXor ^= arr[i];
        int target = currentXor ^ k;

        if (prefixXorIdx.count(target)) {
            return {prefixXorIdx[target] + 1, i};
        }

        // Store first occurrence if we want the longest or just a valid one
        if (prefixXorIdx.find(currentXor) == prefixXorIdx.end()) {
            prefixXorIdx[currentXor] = i;
        }
    }

    return {-1, -1};
}

int main() {
    vector<int> arr = {4, 2, 2, 6, 4};
    int k = 6;
    pair<int, int> result = findSubarrayGivenXOR(arr, k);
    
    if (result.first != -1) {
        cout << "Subarray with XOR " << k << " found at indices [" << result.first << ", " << result.second << "]" << endl;
    } else {
        cout << "No subarray found with XOR " << k << endl;
    }
    
    return 0;
}
