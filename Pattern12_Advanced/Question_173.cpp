// - Find Fixed Point in a Sorted Array (arr[i] == i)

#include <iostream>
#include <vector>
using namespace std;

// Find an index i such that arr[i] == i in a sorted array of distinct integers.
// Method: Binary Search (O(log n))
int findFixedPoint(vector<int>& arr) {
    int low = 0, high = arr.size() - 1;

    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (arr[mid] == mid) {
            return mid;
        } else if (arr[mid] < mid) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return -1;
}

int main() {
    vector<int> arr = {-10, -5, 0, 3, 7};
    // index 0: -10, 1: -5, 2: 0, 3: 3 (Fixed point!), 4: 7
    int result = findFixedPoint(arr);
    if (result != -1) {
        cout << "Fixed point found at index: " << result << endl;
    } else {
        cout << "No fixed point found." << endl;
    }
    return 0;
}
