// - Partition Array by Condition (stable vs unstable)

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Unstable Partition (using two pointers)
void unstablePartition(vector<int>& arr) {
    int left = 0, right = arr.size() - 1;
    while (left < right) {
        // Move left while it's even
        while (left < right && arr[left] % 2 == 0) left++;
        // Move right while it's odd
        while (left < right && arr[right] % 2 != 0) right--;
        
        if (left < right) {
            swap(arr[left], arr[right]);
            left++;
            right--;
        }
    }
}

// Stable Partition (using extra space)
vector<int> stablePartition(const vector<int>& arr) {
    vector<int> result;
    // First pass for even numbers
    for (int x : arr) {
        if (x % 2 == 0) result.push_back(x);
    }
    // Second pass for odd numbers
    for (int x : arr) {
        if (x % 2 != 0) result.push_back(x);
    }
    return result;
}

int main() {
    int n;
    cout << "Enter the size of the array: ";
    cin >> n;

    vector<int> arr(n);
    cout << "Enter " << n << " elements: ";
    for (int i = 0; i < n; i++) cin >> arr[i];

    vector<int> arrUnstable = arr;
    unstablePartition(arrUnstable);
    cout << "Unstable Partition (Even first, then Odd): ";
    for (int x : arrUnstable) cout << x << " ";
    cout << endl;

    vector<int> arrStable = stablePartition(arr);
    cout << "Stable Partition (Even first, then Odd): ";
    for (int x : arrStable) cout << x << " ";
    cout << endl;

    return 0;
}
