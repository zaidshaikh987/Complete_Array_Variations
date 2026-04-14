// - Longest Subarray with at Most K Zeros (Flip Problem)

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Find the longest subarray such that count of 0s is <= k

int longestSubarrayKZeros(vector<int>& arr, int k) {
    int n = arr.size();
    int left = 0, maxLength = 0;
    int zeroCount = 0;

    for (int right = 0; right < n; right++) {
        if (arr[right] == 0) {
            zeroCount++;
        }

        // If zeroCount exceeds k, shrink the window from left
        while (zeroCount > k) {
            if (arr[left] == 0) {
                zeroCount--;
            }
            left++;
        }

        maxLength = max(maxLength, right - left + 1);
    }

    return maxLength;
}

int main() {
    int n, k;
    cout << "Enter the size of the binary array (0s and 1s): ";
    cin >> n;
    cout << "Enter k (max number of zeros to flip/allow): ";
    cin >> k;

    vector<int> arr(n);
    cout << "Enter " << n << " elements: ";
    for (int i = 0; i < n; i++) cin >> arr[i];

    int result = longestSubarrayKZeros(arr, k);
    cout << "The length of the longest subarray with at most " << k << " zeros is: " << result << endl;

    return 0;
}
