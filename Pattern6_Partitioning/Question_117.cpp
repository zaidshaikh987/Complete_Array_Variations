// - Sort an Array of 0s and 1s Without a Sorting Algorithm

#include <iostream>
#include <vector>
using namespace std;

// Method: Counting (O(n))
void sort0and1Counting(vector<int>& arr) {
    int count0 = 0;
    for (int x : arr) {
        if (x == 0) count0++;
    }

    for (int i = 0; i < count0; i++) arr[i] = 0;
    for (int i = count0; i < arr.size(); i++) arr[i] = 1;
}

int main() {
    vector<int> arr = {1, 0, 1, 0, 0, 1};
    cout << "Original array: ";
    for (int x : arr) cout << x << " ";
    cout << endl;

    sort0and1Counting(arr);

    cout << "Sorted array (Counting): ";
    for (int x : arr) cout << x << " ";
    cout << endl;

    return 0;
}
