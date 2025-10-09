// | - Count of Subarrays of Size K with Sum > X *(optional)* | Conditional | Builds pattern understanding |

#include <iostream>
using namespace std;

int countSubarraysGreaterThanX(int arr[], int n, int k, int X) {
    if (k > n) return 0; // edge case

    int count = 0;
    int windowSum = 0;

    // Sum of first window
    for (int i = 0; i < k; i++)
        windowSum += arr[i];

    if (windowSum > X)
        count++;

    // Slide the window
    for (int i = k; i < n; i++) {
        windowSum += arr[i] - arr[i - k]; // remove left, add right
        if (windowSum > X)
            count++;
    }

    return count;
}

int main() {
    int n, k, X;
    cout << "Enter number of elements, window size k, and X: ";
    cin >> n >> k >> X;

    int arr[n];
    cout << "Enter elements: ";
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    int result = countSubarraysGreaterThanX(arr, n, k, X);
    cout << "Number of subarrays of size " << k << " with sum > " << X << " is " << result << "\n";

    return 0;
}
