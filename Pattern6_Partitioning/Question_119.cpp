// - Partition Array Around a Pivot

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// This is similar to the partitioning step in QuickSort.
void partitionAroundPivot(vector<int>& arr, int pivot) {
    int n = arr.size();
    int i = 0; // Index of elements smaller than or equal to pivot

    for (int j = 0; j < n; j++) {
        if (arr[j] <= pivot) {
            swap(arr[i], arr[j]);
            i++;
        }
    }
}

int main() {
    vector<int> arr = {10, 80, 30, 90, 40, 50, 70};
    int pivot = 50;
    
    cout << "Original array: ";
    for (int x : arr) cout << x << " ";
    cout << endl;

    partitionAroundPivot(arr, pivot);

    cout << "Partitioned around " << pivot << ": ";
    for (int x : arr) cout << x << " ";
    cout << endl;

    return 0;
}
