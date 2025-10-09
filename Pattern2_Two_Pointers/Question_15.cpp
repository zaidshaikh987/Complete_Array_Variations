// - Find a Pair with Given Difference k

#include <iostream>
#include <algorithm>
using namespace std;

void findPairWithDifferenceK(int arr[], int n, int k) {
    sort(arr, arr + n);
    int left = 0, right = 1;

    while (right < n) {
        int diff = arr[right] - arr[left];
        if (diff == k) {
            cout << arr[left] << ", " << arr[right] << endl;
            left++;
            right++;
        } else if (diff < k) {
            right++;
        } else { // diff > k
            left++;
            if (left == right) right++;
        }
    }
}

int main() {
    int arr[] = {1, 5, 3, 4, 2};
    int n = sizeof(arr) / sizeof(arr[0]);
    int k = 2;

    cout << "Pairs with difference " << k << ":\n";
    findPairWithDifferenceK(arr, n, k);

    return 0;
}
