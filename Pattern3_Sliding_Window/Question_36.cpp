// - Subarray of Size K with Maximum Average / Minimum Average | Average | Similar to above |

#include <iostream>
using namespace std;

double maxAverageSubarray(int arr[], int n, int k) {
    if (k > n) return -1; // edge case

    double windowSum = 0.0;

    // Sum of first window
    for (int i = 0; i < k; i++) {
        windowSum += arr[i];
    }

    double maxSum = windowSum;

    // Slide the window
    for (int i = k; i < n; i++) {
        windowSum += arr[i] - arr[i - k];
        if (windowSum > maxSum)
            maxSum = windowSum;
    }

    return maxSum / k; // return maximum average
}

int main() {
    int n, k;
    cout << "Enter number of elements and window size k: ";
    cin >> n >> k;

    int arr[n];
    cout << "Enter elements: ";
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    double result = maxAverageSubarray(arr, n, k);
    if (result == -1)
        cout << "Window size larger than array size!\n";
    else
        cout << "Maximum average of subarray of size " << k << " is " << result << "\n";

    return 0;
}
