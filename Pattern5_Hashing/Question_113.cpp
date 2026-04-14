// - Subarrays with Exactly K Different Integers (Hashing + Sliding Window)

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

// Formula: exactly(k) = atMost(k) - atMost(k-1)
long long atMostK(vector<int>& arr, int k) {
    if (k < 0) return 0;
    int n = arr.size();
    unordered_map<int, int> freq;
    int left = 0;
    long long count = 0;

    for (int right = 0; right < n; right++) {
        freq[arr[right]]++;
        while (freq.size() > k) {
            freq[arr[left]]--;
            if (freq[arr[left]] == 0) freq.erase(arr[left]);
            left++;
        }
        count += (long long)(right - left + 1);
    }
    return count;
}

long long exactlyK(vector<int>& arr, int k) {
    return atMostK(arr, k) - atMostK(arr, k - 1);
}

int main() {
    vector<int> arr = {1, 2, 1, 2, 3};
    int k = 2;
    cout << "Total subarrays with exactly " << k << " distinct integers: " << exactlyK(arr, k) << endl;
    return 0;
}
