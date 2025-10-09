// - Minimum Sum Subarray of Size K | Sum | Just track min instead of max |

# include <iostream>
using namespace std;

void minSumSubarray(int arr[],int n,int k){
    int windowSum = 0;
    int minSum = INT_MAX;

    // 1️⃣ Sum of first 'k' elements (first window)
    for(int i = 0; i < k; i++){
        windowSum += arr[i];
    }
    minSum = windowSum;

    // 2️⃣ Slide the window to the right (rest of the array)
    for(int i = k; i < n; i++){
        windowSum += arr[i] - arr[i - k];
        if(windowSum < minSum){
            minSum = windowSum;
        }
    }
     // 3️⃣ Return the minimum sum
     return minSum;
}

int main() {
    int arr[] = {1, 2, 3, 4, 5};
    int n = sizeof(arr) / sizeof(arr[0]);
    int k;
    cout << "Enter size of subarray k: ";
    cin >> k;

    int result = minSumSubarray(arr, n, k);
    cout << "Minimum sum of subarray of size " << k << " is " << result << endl;

    return 0;
}
