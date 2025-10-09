// - Two-Sum (on a sorted array, target = k)

#include <iostream>
using namespace std;

void twoSumSorted(int arr[], int n, int target) {
    int left = 0, right = n - 1;

    while (left < right) {
        int currentSum = arr[left] + arr[right];

        if (currentSum == target) {
            cout << arr[left] << " " << arr[right] << endl;
            left++;
            right--;
        } 
        else if (currentSum < target) {
            left++;
        } 
        else {
            right--;
        }
    }
}

int main() {
    int arr[] = {-3, -1, 0, 2, 4, 5};
    int n = sizeof(arr) / sizeof(arr[0]);
    int target = 2;

    cout << "Pairs with sum " << target << ":\n";
    twoSumSorted(arr, n, target);

    return 0;
}
