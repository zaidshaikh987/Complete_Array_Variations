// - Find a Pair with Given Difference k

//Pattern 2 : Two Pointers ( Same Direction – Difference)

bool findPairWithDifference(vector<int>& arr, int k) {
    int left = 0;                      // Smaller element pointer
    int right = 1;                     // Larger element pointer

    while (right < arr.size()) {

        // Make sure we are comparing two different indices
        if (left == right) {
            right++;
            continue;
        }

        int diff = arr[right] - arr[left];

        if (diff == k) {
            return true;               // Valid pair found
        }
        else if (diff < k) {
            right++;                   // Need a larger difference
        }
        else {
            left++;                    // Need a smaller difference
        }
    }

    return false;                      // No valid pair exists
}
