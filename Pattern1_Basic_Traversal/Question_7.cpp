//  - Find the Difference Between Largest and Smallest Elements

#include <iostream>
using namespace std;

int findDifference(int arr[], int n) {
    int max = arr[0];
    int min = arr[0];
    for(int i = 1; i < n; i++) {
        if(arr[i] > max) {
            max = arr[i];
        }
        if(arr[i] < min) {
            min = arr[i];
        }
    }
    return max - min;
}

int main() {
    int arr[] = {10, 5, 8, 20, 15};
    int n = sizeof(arr) / sizeof(arr[0]);
    int difference = findDifference(arr, n);
    cout << "Difference between largest and smallest elements: " << difference << endl;
    return 0;
}
