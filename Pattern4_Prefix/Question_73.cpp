// - Count Number of Subarrays with Given XOR K

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

// Logic: (prefixXOR[i] ^ prefixXOR[j]) == K
// implies prefixXOR[j] == prefixXOR[i] ^ K
int countSubarraysWithXOR(vector<int>& arr, int k) {
    int n = arr.size();
    unordered_map<int, int> xorFreq;
    xorFreq[0] = 1; // Base case

    int currentXOR = 0;
    int count = 0;

    for (int x : arr) {
        currentXOR ^= x;
        int target = currentXOR ^ k;

        if (xorFreq.count(target)) {
            count += xorFreq[target];
        }
        xorFreq[currentXOR]++;
    }

    return count;
}

int main() {
    vector<int> arr = {4, 2, 2, 6, 4};
    int k = 6;
    // Subarrays with XOR 6: {4,2}, {6}, {2,2,6}, {4,2,2,6,4}
    // Wait, let's trace:
    // 4 ^ 2 = 6 (Yes)
    // 6 = 6 (Yes)
    // 2 ^ 2 ^ 6 = 6 (Yes)
    // 4 ^ 2 ^ 2 ^ 6 ^ 4 = 6 (Yes)
    cout << "Number of subarrays with XOR " << k << ": " << countSubarraysWithXOR(arr, k) << endl;
    return 0;
}
