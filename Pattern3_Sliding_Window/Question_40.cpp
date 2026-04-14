// - Longest Subarray with at Most K Distinct Elements

#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

int longestSubarrayKDistinct(vector<int>& arr, int k) {
    int n = arr.size();
    if (k == 0) return 0;

    unordered_map<int, int> freq;
    int left = 0, maxLength = 0;

    for (int right = 0; right < n; right++) {
        freq[arr[right]]++;

        // If distinct elements exceed k, shrink the window from left
        while (freq.size() > k) {
            freq[arr[left]]--;
            if (freq[arr[left]] == 0) {
                freq.erase(arr[left]);
            }
            left++;
        }

        maxLength = max(maxLength, right - left + 1);
    }

    return maxLength;
}

int main() {
    int n, k;
    cout << "Enter the size of the array: ";
    cin >> n;
    cout << "Enter k (at most k distinct elements): ";
    cin >> k;

    vector<int> arr(n);
    cout << "Enter " << n << " elements: ";
    for (int i = 0; i < n; i++) cin >> arr[i];

    int result = longestSubarrayKDistinct(arr, k);
    cout << "The length of the longest subarray with at most " << k << " distinct elements is: " << result << endl;

    return 0;
}
