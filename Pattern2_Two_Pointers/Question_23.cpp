// - Remove Duplicates from Sorted Array II (allow at most two duplicates)

#include <iostream>
#include <vector>
using namespace std;

int removeDuplicatesII(vector<int>& nums) {
    int n = nums.size();
    if (n <= 2) return n;

    int index = 2; // Start from the third element
    for (int i = 2; i < n; i++) {
        // If the current element is not the same as the element two positions before the current index
        if (nums[i] != nums[index - 2]) {
            nums[index] = nums[i];
            index++;
        }
    }
    return index;
}

int main() {
    int n;
    cout << "Enter the size of the sorted array: ";
    cin >> n;

    vector<int> nums(n);
    cout << "Enter " << n << " elements (sorted): ";
    for (int i = 0; i < n; i++) cin >> nums[i];

    int newLength = removeDuplicatesII(nums);

    cout << "New length: " << newLength << endl;
    cout << "Array after removing duplicates (at most 2): ";
    for (int i = 0; i < newLength; i++) {
        cout << nums[i] << " ";
    }
    cout << endl;

    return 0;
}
