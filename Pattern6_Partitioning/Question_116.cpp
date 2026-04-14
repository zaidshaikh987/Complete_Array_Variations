// - Segregate 0s and 1s

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Method: Two Pointers (O(n))
void segregate0and1(vector<int>& arr) {
    int left = 0, right = arr.size() - 1;

    while (left < right) {
        while (arr[left] == 0 && left < right) left++;
        while (arr[right] == 1 && left < right) right--;

        if (left < right) {
            arr[left] = 0;
            arr[right] = 1;
            left++;
            right--;
        }
    }
}

int main() {
    vector<int> arr = {0, 1, 0, 1, 1, 1, 0, 0};
    cout << "Original array: ";
    for (int x : arr) cout << x << " ";
    cout << endl;

    segregate0and1(arr);

    cout << "Segregated array: ";
    for (int x : arr) cout << x << " ";
    cout << endl;

    return 0;
}
