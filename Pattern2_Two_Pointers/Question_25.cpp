// - All Unique Pairs with Sum = k (handle duplicates)

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void findUniquePairs(vector<int>& arr, int target) {
    sort(arr.begin(), arr.end());
    int left = 0, right = arr.size() - 1;
    bool found = false;

    while (left < right) {
        int sum = arr[left] + arr[right];
        if (sum == target) {
            cout << "(" << arr[left] << ", " << arr[right] << ")" << endl;
            found = true;
            
            // Skip duplicates for left
            while (left < right && arr[left] == arr[left + 1]) left++;
            // Skip duplicates for right
            while (left < right && arr[right] == arr[right - 1]) right--;
            
            left++;
            right--;
        } else if (sum < target) {
            left++;
        } else {
            right--;
        }
    }

    if (!found) {
        cout << "No unique pairs found." << endl;
    }
}

int main() {
    int n;
    cout << "Enter the size of the array: ";
    cin >> n;

    vector<int> arr(n);
    cout << "Enter " << n << " elements: ";
    for (int i = 0; i < n; i++) cin >> arr[i];

    int target;
    cout << "Enter the target sum: ";
    cin >> target;

    cout << "Unique pairs summing to " << target << ":" << endl;
    findUniquePairs(arr, target);

    return 0;
}
