// - Left Rotate Array by One Position

#include <iostream>
#include <vector>
using namespace std;

void leftRotateOne(vector<int>& arr) {
    if (arr.size() < 2) return;
    int first = arr[0];
    for (int i = 0; i < arr.size() - 1; i++) {
        arr[i] = arr[i + 1];
    }
    arr[arr.size() - 1] = first;
}

int main() {
    vector<int> arr = {1, 2, 3, 4, 5};
    cout << "Original array: ";
    for (int x : arr) cout << x << " ";
    cout << endl;

    leftRotateOne(arr);

    cout << "Left rotated by 1: ";
    for (int x : arr) cout << x << " ";
    cout << endl;

    return 0;
}
