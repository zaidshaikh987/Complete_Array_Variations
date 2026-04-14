// - Move All Zeros to the End (In-place)

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void moveZerosToEnd(vector<int>& arr) {
    int n = arr.size();
    int nonZeroIdx = 0;

    // Shift all non-zero elements to the front
    for (int i = 0; i < n; i++) {
        if (arr[i] != 0) {
            swap(arr[nonZeroIdx], arr[i]);
            nonZeroIdx++;
        }
    }
}

int main() {
    vector<int> arr = {0, 1, 9, 8, 4, 0, 0, 2, 0, 7, 0, 6, 0, 9};
    cout << "Original array: ";
    for (int x : arr) cout << x << " ";
    cout << endl;

    moveZerosToEnd(arr);

    cout << "Array after moving zeros: ";
    for (int x : arr) cout << x << " ";
    cout << endl;

    return 0;
}
