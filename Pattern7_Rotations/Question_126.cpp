// - Rearrange Array (arr[i] = i)

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Rearrange an array such that arr[i] = i if i is present in the array, 
// else arr[i] = -1.
void rearrangeArray(vector<int>& arr) {
    int n = arr.size();
    for (int i = 0; i < n; i++) {
        while (arr[i] != -1 && arr[i] != i) {
            int target = arr[i];
            
            // Swap arr[i] with arr[target]
            if (arr[target] != target) {
                swap(arr[i], arr[target]);
            } else {
                // Duplicate or target already set, break to avoid infinite loop
                break;
            }
        }
    }
}

int main() {
    vector<int> arr = {-1, -1, 6, 1, 9, 3, 2, -1, 4, -1};
    cout << "Original array: ";
    for (int x : arr) cout << x << " ";
    cout << endl;

    rearrangeArray(arr);

    cout << "Rearranged array: ";
    for (int x : arr) cout << x << " ";
    cout << endl;

    return 0;
}
