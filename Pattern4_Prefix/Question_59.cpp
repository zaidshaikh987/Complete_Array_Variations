// - Intersection of Two Sorted Arrays

#include <iostream>
#include <vector>
using namespace std;

vector<int> findIntersection(int arr1[], int n, int arr2[], int m) {
    int i = 0, j = 0;
    vector<int> result;

    while (i < n && j < m) {
        if (i > 0 && arr1[i] == arr1[i - 1]) {
            i++;
            continue;
        }

        if (arr1[i] < arr2[j]) {
            i++;
        } else if (arr2[j] < arr1[i]) {
            j++;
        } else {
            result.push_back(arr1[i]);
            i++;
            j++;
        }
    }

    return result;
}

int main() {
    int arr1[] = {1, 2, 2, 3, 4, 5};
    int n = sizeof(arr1) / sizeof(arr1[0]);
    int arr2[] = {2, 2, 3, 6, 7};
    int m = sizeof(arr2) / sizeof(arr2[0]);

    vector<int> intersection = findIntersection(arr1, n, arr2, m);

    cout << "Intersection of arrays: ";
    for (int x : intersection) {
        cout << x << " ";
    }
    cout << endl;

    return 0;
}
