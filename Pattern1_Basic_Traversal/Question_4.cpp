//  - Linear Search: Find the index of a given element.

#include <iostream>
using namespace std;

// Function to perform linear search
int linearSearch(int arr[], int n, int key) {
    for(int i = 0; i < n; i++) {
        if(arr[i] == key) {
            return i; // return index if key is found
        }
    }
    return -1; // return -1 if key not found
}

int main() {
    int arr[] = {10, 5, 8, 20, 15};
    int n = sizeof(arr) / sizeof(arr[0]);
    int key;
    cout << " Enter the element to be searched";
    cin >> key;

    int index = linearSearch(arr, n, key);

    if(index != -1)
        cout << "Element " << key << " found at index: " << index << endl;
    else
        cout << "Element " << key << " not found in the array." << endl;

    return 0;
}
