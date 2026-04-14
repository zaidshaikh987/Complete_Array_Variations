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



________________________________________________________________________________

def max_sum_subarray(arr, k):
    
    # Step 1: take first window
    window_sum = sum(arr[0:k])
    
    # this will store final answer
    max_sum = window_sum

    # Step 2: start sliding
    for i in range(k, len(arr)):
        
        # remove old element + add new element
        window_sum = window_sum - arr[i-k] + arr[i]
        
        # update maximum
        if window_sum > max_sum:
            max_sum = window_sum

    return max_sum