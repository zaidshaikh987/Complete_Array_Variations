// - Longest Subarray with at Most K Distinct Elements (Hashing + Sliding Window)

#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

// Find the length of the longest subarray with at most k distinct elements.
int longestSubarrayAtMostK(vector<int>& arr, int k) {
    int n = arr.size();
    if (k == 0) return 0;

    unordered_map<int, int> freq;
    int left = 0;
    int maxLen = 0;

    for (int right = 0; right < n; right++) {
        freq[arr[right]]++;

        while (freq.size() > k) {
            freq[arr[left]]--;
            if (freq[arr[left]] == 0) {
                freq.erase(arr[left]);
            }
            left++;
        }

        maxLen = max(maxLen, right - left + 1);
    }

    return maxLen;
}

int main() {
    vector<int> arr = {1, 2, 1, 2, 3};
    int k = 2;
    cout << "Length of the longest subarray with at most " << k << " distinct elements: " << longestSubarrayAtMostK(arr, k) << endl;
    return 0;
}
