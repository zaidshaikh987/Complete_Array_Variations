// - Counting Inversions in an Array

#include <iostream>
#include <vector>
using namespace std;

// Find the number of pairs (i, j) such that i < j and arr[i] > arr[j].
// Method: Modified Merge Sort (O(n log n))
long long mergeAndCount(vector<int>& arr, int l, int m, int r) {
    int n1 = m - l + 1;
    int n2 = r - m;
    vector<int> left(n1), right(n2);

    for (int i = 0; i < n1; i++) left[i] = arr[l + i];
    for (int i = 0; i < n2; i++) right[i] = arr[m + 1 + i];

    long long count = 0;
    int i = 0, j = 0, k = l;

    while (i < n1 && j < n2) {
        if (left[i] <= right[j]) {
            arr[k++] = left[i++];
        } else {
            // All elements from left[i] to left[n1-1] are greater than right[j]
            arr[k++] = right[j++];
            count += (n1 - i);
        }
    }

    while (i < n1) arr[k++] = left[i++];
    while (j < n2) arr[k++] = right[j++];

    return count;
}

long long countInversions(vector<int>& arr, int l, int r) {
    long long count = 0;
    if (l < r) {
        int m = l + (r - l) / 2;
        count += countInversions(arr, l, m);
        count += countInversions(arr, m + 1, r);
        count += mergeAndCount(arr, l, m, r);
    }
    return count;
}

int main() {
    vector<int> arr = {8, 4, 2, 1};
    // Inversions: (8,4), (8,2), (8,1), (4,2), (4,1), (2,1) -> 6
    cout << "Number of inversions: " << countInversions(arr, 0, arr.size() - 1) << endl;
    return 0;
}
