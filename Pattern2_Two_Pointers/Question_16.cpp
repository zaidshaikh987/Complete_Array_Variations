// - Find Pair with Sum Closest to Zero (minimum absolute sum pair)

# include <iostream>
using namespace std;

void findPairWithClosestToZero(int arr[], int n) {
    int left = 0, right = n - 1;
    int minSum = INT_MAX;
    int pairLeft = 0, pairRight = 0;

    while (left < right) {
        int currentSum = arr[left] + arr[right];
        if (abs(currentSum) < abs(minSum)) {
            minSum = currentSum;
            pairLeft = left;
            pairRight = right;
        }

        if (currentSum < 0) {
            left++;
        } else {
            right--;
        }
    }

    cout << "Pair with sum closest to zero: " << arr[pairLeft] << ", " << arr[pairRight] << endl;
}