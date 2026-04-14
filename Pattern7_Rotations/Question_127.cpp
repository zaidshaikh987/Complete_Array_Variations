// - Rearrange Positive and Negative Numbers Alternatively

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Rearrange an array such that positive and negative numbers appear in 
// alternating fashion. 
// Assume number of positive and negative numbers can be different.
void rearrangeAlternate(vector<int>& arr) {
    int n = arr.size();
    
    // 1. Separate positives and negatives (partitioning)
    int i = -1;
    for (int j = 0; j < n; j++) {
        if (arr[j] < 0) {
            i++;
            swap(arr[i], arr[j]);
        }
    }

    // Now all negatives are from 0 to i, and positives from i+1 to n-1
    int neg = 1, pos = i + 1;
    while (neg < pos && pos < n && arr[neg] < 0) {
        swap(arr[neg], arr[pos]);
        neg += 2;
        pos++;
    }
}

int main() {
    vector<int> arr = {-1, 2, -3, 4, 5, 6, -7, 8, 9};
    cout << "Original array: ";
    for (int x : arr) cout << x << " ";
    cout << endl;

    rearrangeAlternate(arr);

    cout << "Rearranged array: ";
    for (int x : arr) cout << x << " ";
    cout << endl;

    return 0;
}
