// - Find Pair with Sum Closest to Zero (minimum absolute sum pair)

// Pattern 1 : Two Pointers ( Opposite ends + Optimization)

int closestSumToZero(vector<int>& arr) {
    sort(arr.begin(), arr.end());      // Sorting is required

    int left = 0;                      // Smallest element
    int right = arr.size() - 1;        // Largest element

    int bestSum = INT_MAX;             // Stores sum closest to zero

    while (left < right) {

        int currentSum = arr[left] + arr[right];

        // Update bestSum if this sum is closer to zero
        if (abs(currentSum) < abs(bestSum)) {
            bestSum = currentSum;
        }

        // If sum is negative, move left to increase sum
        if (currentSum < 0) {
            left++;
        }
        // If sum is positive, move right to decrease sum
        else {
            right--;
        }
    }

    return bestSum;
}
