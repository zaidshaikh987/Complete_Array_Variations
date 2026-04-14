// - Left Rotate Array by D Positions

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Method: Reversal Algorithm (O(n) time, O(1) space)
// 1. Reverse first d elements
// 2. Reverse remaining n-d elements
// 3. Reverse the entire array
void leftRotateD(vector<int>& arr, int d) {
    int n = arr.size();
    if (n == 0) return;
    d = d % n;
    if (d == 0) return;

    reverse(arr.begin(), arr.begin() + d);
    reverse(arr.begin() + d, arr.end());
    reverse(arr.begin(), arr.end());
}

int main() {
    vector<int> arr = {1, 2, 3, 4, 5, 6, 7};
    int d = 3;
    
    cout << "Original array: ";
    for (int x : arr) cout << x << " ";
    cout << endl;

    leftRotateD(arr, d);

    cout << "Left rotated by " << d << ": ";
    for (int x : arr) cout << x << " ";
    cout << endl;

    return 0;
}
