// - Circular Two-Pointer Variants (Sorted circular array pair sum)

#include <iostream>
#include <vector>
using namespace std;

// Function to find a pair with a given sum in a sorted circular array
bool circularPairSum(vector<int>& arr, int target) {
    int n = arr.size();
    if (n < 2) return false;

    // Find the pivot (max element)
    int i;
    for (i = 0; i < n - 1; i++) {
        if (arr[i] > arr[i + 1])
            break;
    }

    int left = (i + 1) % n; // smallest element
    int right = i;          // largest element

    while (left != right) {
        int currentSum = arr[left] + arr[right];
        if (currentSum == target) {
            cout << "Pair found: (" << arr[left] << ", " << arr[right] << ")" << endl;
            return true;
        }

        if (currentSum < target) {
            left = (left + 1) % n;
        } else {
            right = (n + right - 1) % n;
        }
    }

    return false;
}

int main() {
    int n;
    cout << "Enter the size of the array: ";
    cin >> n;

    vector<int> arr(n);
    cout << "Enter " << n << " elements of the sorted circular array: ";
    for (int i = 0; i < n; i++) cin >> arr[i];

    int target;
    cout << "Enter the target sum: ";
    cin >> target;

    if (!circularPairSum(arr, target)) {
        cout << "No pair found with the given sum." << endl;
    }

    return 0;
}
