// - Two-Sum (on a sorted array, target = k)

// Pattern 2 : Two Pointers ( Same end + Comparison)

bool twoSumSorted(vector<int>& arr, int k) {
    int left = 0;                       // Smallest element
    int right = arr.size() - 1;         // Largest element

    while (left < right) {

        int currentSum = arr[left] + arr[right];  // Sum of two values

        if (currentSum == k) {
            return true;                // Found the required pair
        }
        else if (currentSum < k) {
            left++;                     // Need a bigger sum
        }
        else {
            right--;                    // Need a smaller sum
        }
    }

    return false;                       // No pair found
}
