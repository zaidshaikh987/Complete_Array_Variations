// - Squares of a Sorted Array (merge negatives & positives)

// Pattern 0 : Two Pointers (Opposite Ends → Merge-like Overwrite)

vector<int> sortedSquares(vector<int>& arr) {
    int n = arr.size();

    vector<int> result(n);          // Result array
    int left = 0;                   // Pointer at start
    int right = n - 1;              // Pointer at end
    int pos = n - 1;                // Position to fill in result (from end)

    while (left <= right) {

        int leftSquare = arr[left] * arr[left];
        int rightSquare = arr[right] * arr[right];

        // Place the larger square at the current position
        if (leftSquare > rightSquare) {
            result[pos] = leftSquare;
            left++;                 // Move left pointer inward
        } else {
            result[pos] = rightSquare;
            right--;                // Move right pointer inward
        }

        pos--;                      // Move result pointer backward
    }

    return result;
}
