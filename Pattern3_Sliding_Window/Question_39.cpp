// | - Longest Subarray with Sum ≤ K | Sum-based | Keep window valid with sum ≤ K |
 
#include <iostream>
using namespace std;

// Function to find longest subarray with sum ≤ K
int longestSubarraySumLEK(int arr[], int n, int K) {
    int left = 0;      // left boundary of window
    int sum = 0;       // current sum of window
    int maxLen = 0;    // maximum length found

    for (int right = 0; right < n; right++) {
        sum += arr[right]; // expand window

        // shrink window from left while sum > K
        while (sum > K) {
            sum -= arr[left];
            left++;
        }

        // update max length
        int currentLen = right - left + 1;
        if (currentLen > maxLen)
            maxLen = currentLen;
    }

    return maxLen;
}

// Main function
int main() {
    int n, K;
    cout << "Enter number of elements: ";
    cin >> n;

    int arr[n];
    cout << "Enter elements: ";
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    cout << "Enter K: ";
    cin >> K;

    int result = longestSubarraySumLEK(arr, n, K);
    cout << "Length of longest subarray with sum ≤ " << K << " = " << result << endl;

    return 0;
}
