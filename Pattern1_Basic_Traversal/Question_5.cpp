//  - Count Occurrences of a Given Element

#include <iostream>
using namespace std;

int countOccurrences(int arr[], int n, int key) {
    int count = 0;
    for(int i = 0; i < n; i++) {
        if(arr[i] == key) {
            count++;
        }
    }
    return count;
}

int main() {
    int arr[] = {10, 5, 8, 20, 15, 5, 10};
    int n = sizeof(arr) / sizeof(arr[0]);
    int key = 5; // element to count occurrences of

    int count = countOccurrences(arr, n, key);

    cout << "Element " << key << " occurs " << count << " times in the array." << endl;

    return 0;
}
