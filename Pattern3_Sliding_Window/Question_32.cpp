// | - Maximum Sum Subarray of Size K | Sum | Classic fixed window base problem |

#include <iostream>
#include <climits>  // For INT_MIN
using namespace std;

int maxSumSubarray(int arr[], int n, int k) {
    int windowSum = 0;
    int MaxSum = INT_MIN;

    // Sum of first 'k' elements
    for(int i = 0; i < k; i++){
        windowSum += arr[i];
    }
    MaxSum = windowSum;

    // Slide the window
    for(int i = k; i < n; i++){
        windowSum += arr[i] - arr[i - k];
        if(windowSum > MaxSum){
            MaxSum = windowSum;
        }
    }

    return MaxSum;
}

int main() {
    int arr[] = {1, 2, 3, 4, 5};
    int n = sizeof(arr) / sizeof(arr[0]);
    int k;
    cout << "Enter size of subarray k: ";
    cin >> k;

    int result = maxSumSubarray(arr, n, k);
    cout << "Maximum sum of subarray of size " << k << " is " << result << endl;

    return 0;
}