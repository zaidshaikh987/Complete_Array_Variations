// - Count Pairs with XOR = K

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

// Find number of pairs (i, j) such that arr[i] ^ arr[j] = k.
int countPairsXOR(vector<int>& arr, int k) {
    unordered_map<int, int> freq;
    int count = 0;

    for (int x : arr) {
        int target = x ^ k;
        if (freq.count(target)) {
            count += freq[target];
        }
        freq[x]++;
    }

    return count;
}

int main() {
    vector<int> arr = {5, 4, 10, 15, 7, 6};
    int k = 5;
    cout << "Number of pairs with XOR " << k << ": " << countPairsXOR(arr, k) << endl;
    return 0;
}
