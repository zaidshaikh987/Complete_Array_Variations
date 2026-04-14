// - Reverse an Array

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Method 1: Two Pointers (In-place)
void reverseArrayInPlace(vector<int>& arr) {
    int left = 0, right = arr.size() - 1;
    while (left < right) {
        swap(arr[left++], arr[right--]);
    }
}

// Method 2: Recursive
void reverseArrayRecursive(vector<int>& arr, int start, int end) {
    if (start >= end) return;
    swap(arr[start], arr[end]);
    reverseArrayRecursive(arr, start + 1, end - 1);
}

int main() {
    vector<int> arr = {1, 2, 3, 4, 5};
    cout << "Original array: ";
    for (int x : arr) cout << x << " ";
    cout << endl;

    reverseArrayInPlace(arr);
    cout << "Reversed (In-place): ";
    for (int x : arr) cout << x << " ";
    cout << endl;

    reverseArrayRecursive(arr, 0, arr.size() - 1);
    cout << "Reversed back (Recursive): ";
    for (int x : arr) cout << x << " ";
    cout << endl;

    return 0;
}
