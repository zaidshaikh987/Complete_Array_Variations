// - Find Kth Missing Positive Number

#include <iostream>
#include <vector>
using namespace std;

// Find the kth positive integer that is missing from a sorted array.
// Method: Binary Search (O(log n))
// Logic: At index i, the number of missing elements is arr[i] - (i + 1).
int findKthPositive(vector<int>& arr, int k) {
    int low = 0, high = arr.size() - 1;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        int missing = arr[mid] - (mid + 1);
        
        if (missing < k) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    // Result = arr[high] + (k - missing_at_high)
    //         = arr[high] + k - (arr[high] - (high + 1))
    //         = k + high + 1
    //         = k + low
    return low + k;
}

int main() {
    vector<int> arr = {2, 3, 4, 7, 11};
    int k = 5;
    // Missing: 1, 5, 6, 8, 9, 10, ...
    // 5th missing is 9.
    cout << "The " << k << "th missing positive number is: " << findKthPositive(arr, k) << endl;
    
    vector<int> arr2 = {1, 2, 3, 4};
    k = 2;
    // Missing: 5, 6, 7, ...
    // 2nd missing is 6.
    cout << "The " << k << "th missing positive number is: " << findKthPositive(arr2, k) << endl;

    return 0;
}
