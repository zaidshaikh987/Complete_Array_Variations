// - Union of Two Sorted Arrays

#include <iostream>
#include <vector>
#include <set>
using namespace std;

// Two-pointer approach for finding the union of two sorted arrays
vector<int> findUnion(int arr1[], int n, int arr2[], int m) {
    int i = 0, j = 0;
    vector<int> result;

    while (i < n && j < m) {
        // Skip duplicates in arr1
        if (i > 0 && arr1[i] == arr1[i - 1]) {
            i++;
            continue;
        }
        // Skip duplicates in arr2
        if (j > 0 && arr2[j] == arr2[j - 1]) {
            j++;
            continue;
        }

        if (arr1[i] < arr2[j]) {
            result.push_back(arr1[i++]);
        } else if (arr2[j] < arr1[i]) {
            result.push_back(arr2[j++]);
        } else {
            result.push_back(arr1[i++]);
            j++; // Both are equal, add once and increment both
        }
    }

    // Add remaining elements of arr1
    while (i < n) {
        if (i == 0 || arr1[i] != arr1[i - 1]) {
            result.push_back(arr1[i]);
        }
        i++;
    }

    // Add remaining elements of arr2
    while (j < m) {
        if (j == 0 || arr2[j] != arr2[j - 1]) {
            result.push_back(arr2[j]);
        }
        j++;
    }

    return result;
}

int main() {
    int arr1[] = {1, 2, 2, 4, 5, 6};
    int n = sizeof(arr1) / sizeof(arr1[0]);
    int arr2[] = {2, 3, 5, 7};
    int m = sizeof(arr2) / sizeof(arr2[0]);

    vector<int> unionArray = findUnion(arr1, n, arr2, m);

    cout << "Union of arrays: ";
    for (int x : unionArray) {
        cout << x << " ";
    }
    cout << endl;

    return 0;
}
