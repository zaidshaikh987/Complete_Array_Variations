// - Average of Subarray of Size K | Average | Compute rolling average |

#include <iostream>
using namespace std;

void averageSubarray(int arr[], int n, int k) {
    double windowSum = 0.0;

    // Sum of first 'k' elements
    for(int i = 0; i < k; i++) {
        windowSum += arr[i];
    }
    cout << "Average of window 1: " << windowSum / k << endl;

    // Slide the window
    for(int i = k; i < n; i++) {
        windowSum += arr[i] - arr[i - k]; // remove left, add right
        cout << "Average of window " << i - k + 2 << ": " << windowSum / k << endl;
    }
}

int main() {
    int arr[] = {1, 2, 3, 4, 5};
    int n = sizeof(arr) / sizeof(arr[0]);
    int k;
    cout << "Enter size of subarray k: ";
    cin >> k;

    averageSubarray(arr, n, k);

    return 0;
}
