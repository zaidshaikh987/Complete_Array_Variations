// - 3-Sum Closest

#include <iostream>
#include <algorithm>
#include <climits>
using namespace std;

int threeSumClosest(int arr[], int n, int target) {
    sort(arr, arr + n);

    int closestSum = arr[0] + arr[1] + arr[2]; // initialize with first triplet

    for(int i = 0; i < n - 2; i++) {
        int left = i + 1;
        int right = n - 1;

        while(left < right) {
            int currentSum = arr[i] + arr[left] + arr[right];

            if(abs(currentSum - target) < abs(closestSum - target)) {
                closestSum = currentSum; // update closest
            }

            if(currentSum < target) {
                left++;   // need bigger sum
            } 
            else if(currentSum > target) {
                right--;  // need smaller sum
            } 
            else {
                // exact match
                return target;
            }
        }
    }

    return closestSum;
}

int main() {
    int n;
    cout << "Enter the size of the array: ";
    cin >> n;

    int arr[n];
    cout << "Enter " << n << " elements: ";
    for(int i = 0; i < n; i++) cin >> arr[i];

    int target;
    cout << "Enter the target: ";
    cin >> target;

    int result = threeSumClosest(arr, n, target);
    cout << "Closest sum to target is: " << result << endl;

    return 0;
}
