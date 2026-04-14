// - Median in a Row-wise Sorted Matrix (Binary Search on Answer Space)

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Find the median of a matrix where each row is sorted.
// Method: Binary Search on the range of values [min, max] (O(32 * rows * log(cols)))
int countSmallerThanMid(vector<int>& row, int mid) {
    return upper_bound(row.begin(), row.end(), mid) - row.begin();
}

int findMedian(vector<vector<int>>& matrix) {
    int rows = matrix.size();
    int cols = matrix[0].size();
    
    int low = matrix[0][0];
    int high = matrix[0][cols - 1];

    for (int i = 1; i < rows; i++) {
        low = min(low, matrix[i][0]);
        high = max(high, matrix[i][cols - 1]);
    }

    int expectedCount = (rows * cols + 1) / 2;

    while (low <= high) {
        int mid = low + (high - low) / 2;
        int count = 0;
        for (int i = 0; i < rows; i++) {
            count += countSmallerThanMid(matrix[i], mid);
        }

        if (count < expectedCount) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return low;
}

int main() {
    vector<vector<int>> matrix = {
        {1, 3, 5},
        {2, 6, 9},
        {3, 6, 9}
    };

    cout << "Median of the matrix: " << findMedian(matrix) << endl; // 5
    return 0;
}
