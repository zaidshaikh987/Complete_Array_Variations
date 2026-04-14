// - Swap the First and Last Elements

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void swapFirstLast(vector<int>& arr) {
    if (arr.size() < 2) return;
    swap(arr[0], arr[arr.size() - 1]);
}

int main() {
    vector<int> arr = {1, 2, 3, 4, 5};
    cout << "Original array: ";
    for (int x : arr) cout << x << " ";
    cout << endl;

    swapFirstLast(arr);

    cout << "Modified array: ";
    for (int x : arr) cout << x << " ";
    cout << endl;

    return 0;
}
