// - Subarrays with Sum = K (Positive Numbers)

#include <iostream>
#include <vector>
using namespace std;

// This specific problem (positive numbers) can be solved using two pointers/sliding window.
// If there were negative numbers, we would use a hashmap with prefix sums.

void subarraysWithSumK(vector<int>& arr, int k) {
    int n = arr.size();
    int left = 0, currentSum = 0;
    bool found = false;

    for (int right = 0; right < n; right++) {
        currentSum += arr[right];

        // While currentSum is greater than k, shrink the window from left
        while (currentSum > k && left < right) {
            currentSum -= arr[left];
            left++;
        }

        if (currentSum == k) {
            cout << "Subarray found between indices [" << left << ", " << right << "]: ";
            for (int i = left; i <= right; i++) cout << arr[i] << " ";
            cout << endl;
            found = true;
        }
    }

    if (!found) {
        cout << "No subarray found with sum " << k << endl;
    }
}

int main() {
    int n, k;
    cout << "Enter the size of the array: ";
    cin >> n;
    cout << "Enter target sum k: ";
    cin >> k;

    vector<int> arr(n);
    cout << "Enter " << n << " positive elements: ";
    for (int i = 0; i < n; i++) cin >> arr[i];

    cout << "Subarrays with sum " << k << ":" << endl;
    subarraysWithSumK(arr, k);

    return 0;
}
