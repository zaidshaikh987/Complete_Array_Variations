// - Squares of a Sorted Array (merge negatives & positives)

#include <iostream>
using namespace std;

void sortedSquares(int arr[], int n) {
    int result[n];
    int left = 0, right = n - 1;
    int pos = n - 1;  // position to fill in result (from back)

    // Merge squares of negative and positive parts
    while (left <= right) {
        if (abs(arr[left]) > abs(arr[right])) {
            result[pos] = arr[left] * arr[left];
            left++;
        } else {
            result[pos] = arr[right] * arr[right];
            right--;
        }
        pos--;
    }

    cout << "Sorted squares: ";
    for (int i = 0; i < n; i++) {
        cout << result[i] << " ";
    }
    cout << endl;
}

int main() {
    int arr[] = {-7, -3, 0, 2, 5};
    int n = sizeof(arr) / sizeof(arr[0]);

    sortedSquares(arr, n);

    return 0;
}
