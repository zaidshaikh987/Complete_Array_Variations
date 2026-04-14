// - Count Subarrays with Product Less Than K (Sliding Window)

#include <iostream>
#include <vector>
using namespace std;

// Find the number of contiguous subarrays where the product of elements is less than k.
long long countProductLessThanK(vector<int>& arr, int k) {
    if (k <= 1) return 0;
    
    int n = arr.size();
    long long product = 1;
    long long count = 0;
    int left = 0;

    for (int right = 0; right < n; right++) {
        product *= arr[right];

        while (product >= k && left <= right) {
            product /= arr[left];
            left++;
        }

        count += (right - left + 1);
    }

    return count;
}

int main() {
    vector<int> arr = {10, 5, 2, 6};
    int k = 100;
    // Subarrays: {10}, {5}, {2}, {6}, {10,5}, {5,2}, {2,6}, {5,2,6} -> 8 subarrays
    cout << "Total subarrays with product less than " << k << ": " << countProductLessThanK(arr, k) << endl;
    return 0;
}
