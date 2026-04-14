// - Count of Subarrays with Sum Divisible by K (Prefix Sum + Hashmap)

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

// Find the number of subarrays whose sum is divisible by k.
int subarraysDivByK(vector<int>& arr, int k) {
    int n = arr.size();
    unordered_map<int, int> modFreq;
    modFreq[0] = 1; // Base case

    int currentSum = 0;
    int count = 0;

    for (int x : arr) {
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
    vector<int> arr = {4, 5, 0, -2, -3, 1};
    int k = 5;
    cout << "Number of subarrays with sum divisible by " << k << ": " << subarraysDivByK(arr, k) << endl;
    return 0;
}
