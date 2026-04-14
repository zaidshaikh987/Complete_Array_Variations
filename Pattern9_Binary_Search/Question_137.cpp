// - Find Floor and Ceil of an Element in Sorted Array

#include <iostream>
#include <vector>
using namespace std;

// Floor: Greatest element smaller than or equal to target
int findFloor(vector<int>& arr, int target) {
    int low = 0, high = arr.size() - 1, ans = -1;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (arr[mid] <= target) {
            ans = arr[mid];
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return ans;
}

// Ceil: Smallest element greater than or equal to target
int findCeil(vector<int>& arr, int target) {
    int low = 0, high = arr.size() - 1, ans = -1;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (arr[mid] >= target) {
            ans = arr[mid];
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    return ans;
}

int main() {
    vector<int> arr = {1, 2, 8, 10, 10, 12, 19};
    int target = 5;
    cout << "Floor of " << target << ": " << findFloor(arr, target) << endl;
    cout << "Ceil of " << target << ": " << findCeil(arr, target) << endl;
    
    target = 10;
    cout << "Floor of " << target << ": " << findFloor(arr, target) << endl;
    cout << "Ceil of " << target << ": " << findCeil(arr, target) << endl;
    
    return 0;
}
