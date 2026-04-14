// - Two-Sum in a Rotated Sorted Array

#include <iostream>
#include <vector>
using namespace std;

bool pairInRotatedSorted(vector<int>& arr, int target) {
    int n = arr.size();
    
    // Find the pivot element (largest element)
    int i;
    for (i = 0; i < n - 1; i++) {
        if (arr[i] > arr[i + 1])
            break;
    }
    
    // l is now index of smallest element
    int l = (i + 1) % n;
    // r is now index of largest element
    int r = i;
    
    // Keep moving either l or r till they meet
    while (l != r) {
        // If we find a pair with sum target, return true
        if (arr[l] + arr[r] == target)
            return true;
        
        // If current pair sum is less, move to the higher sum
        if (arr[l] + arr[r] < target)
            l = (l + 1) % n;
        else // Move to the lower sum side
            r = (n + r - 1) % n;
    }
    return false;
}

int main() {
    int n;
    cout << "Enter size of the array: ";
    cin >> n;
    
    vector<int> arr(n);
    cout << "Enter " << n << " elements of the rotated sorted array: " << endl;
    for (int i = 0; i < n; i++) cin >> arr[i];
    
    int target;
    cout << "Enter the target sum: ";
    cin >> target;
    
    if (pairInRotatedSorted(arr, target))
        cout << "Array has a pair with sum " << target << endl;
    else
        cout << "Array doesn't have a pair with sum " << target << endl;
        
    return 0;
}
