//  - Find the Floor/Ceil of a number in a Sorted Array

#include <iostream>
using namespace std;

// Function to find floor
int findFloor(int arr[], int n, int x) {
    int low = 0, high = n - 1;
    int floorAns = -1;

    while (low <= high) {
        int mid = (low + high) / 2;

        if (arr[mid] == x) {
            return arr[mid];  // exact match = both floor & ceil
        }
        else if (arr[mid] < x) {
            floorAns = arr[mid]; // possible floor
            low = mid + 1;       // search right
        }
        else {
            high = mid - 1;      // search left
        }
    }
    return floorAns;
}

// Function to find ceil
int findCeil(int arr[], int n, int x) {
    int low = 0, high = n - 1;
    int ceilAns = -1;

    while (low <= high) {
        int mid = (low + high) / 2;

        if (arr[mid] == x) {
            return arr[mid];  // exact match
        }
        else if (arr[mid] < x) {
            low = mid + 1;       // search right
        }
        else {
            ceilAns = arr[mid];  // possible ceil
            high = mid - 1;      // search left
        }
    }
    return ceilAns;
}

int main() {
    int arr[] = {2, 4, 6, 8, 10, 12};
    int n = sizeof(arr) / sizeof(arr[0]);
    int x = 5;

    int floorVal = findFloor(arr, n, x);
    int ceilVal = findCeil(arr, n, x);

    cout << "Floor of " << x << " is: " << floorVal << endl;
    cout << "Ceil of " << x << " is: " << ceilVal << endl;

    return 0;
}

