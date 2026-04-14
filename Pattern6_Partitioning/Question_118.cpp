// - Dutch National Flag Problem (Sort 0s, 1s, and 2s)

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Method: Three-way partitioning (O(n) time, O(1) space)
void sort012(vector<int>& arr) {
    int low = 0, mid = 0, high = arr.size() - 1;

    while (mid <= high) {
        if (arr[mid] == 0) {
            swap(arr[low], arr[mid]);
            low++;
            mid++;
        } else if (arr[mid] == 1) {
            mid++;
        } else { // arr[mid] == 2
            swap(arr[mid], arr[high]);
            high--;
            // Do not increment mid here because the swapped element from high 
            // needs to be processed.
        }
    }
}

int main() {
    vector<int> arr = {0, 1, 2, 0, 1, 2, 1, 0};
    cout << "Original array: ";
    for (int x : arr) cout << x << " ";
    cout << endl;

    sort012(arr);

    cout << "Sorted array (DNF): ";
    for (int x : arr) cout << x << " ";
    cout << endl;

    return 0;
}
