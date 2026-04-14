// - Right Rotate Array by One Position

#include <iostream>
#include <vector>
using namespace std;

void rightRotateOne(vector<int>& arr) {
    if (arr.size() < 2) return;
    int last = arr[arr.size() - 1];
    for (int i = arr.size() - 1; i > 0; i--) {
        arr[i] = arr[i - 1];
    }
    arr[0] = last;
}

int main() {
    vector<int> arr = {1, 2, 3, 4, 5};
    cout << "Original array: ";
    for (int x : arr) cout << x << " ";
    cout << endl;

    rightRotateOne(arr);

    cout << "Right rotated by 1: ";
    for (int x : arr) cout << x << " ";
    cout << endl;

    return 0;
}
