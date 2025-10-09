//  - Check if an Array Contains a Specific Element

#include <iostream>
using namespace std;

bool containsElement(int arr[], int n, int key) {
    for(int i = 0; i < n; i++) {
        if(arr[i] == key) {
            return true; // element found
        }
    }
    return false; // element not found
}

int main() {
    int arr[] = {10, 5, 8, 20, 15};
    int n = sizeof(arr) / sizeof(arr[0]);
    int key = 20; // element to search for

    if(containsElement(arr, n, key))
        cout << "Element " << key << " is present in the array." << endl;
    else
        cout << "Element " << key << " is not present in the array." << endl;

    return 0;
}
