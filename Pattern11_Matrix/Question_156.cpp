// - Search in a 2D Matrix (Sorted row-wise and column-wise)

#include <iostream>
#include <vector>
using namespace std;

// Each row and column is sorted in ascending order.
// Method: Staircase Search (O(m + n))
pair<int, int> searchMatrix(vector<vector<int>>& matrix, int target) {
    int rows = matrix.size();
    if (rows == 0) return {-1, -1};
    int cols = matrix[0].size();

    // Start from top-right corner
    int i = 0, j = cols - 1;

    while (i < rows && j >= 0) {
        if (matrix[i][j] == target) {
            return {i, j};
        } else if (matrix[i][j] > target) {
            j--; // Look in smaller columns
        } else {
            i++; // Look in larger rows
        }
    }

    return {-1, -1};
}

int main() {
    vector<vector<int>> matrix = {
        {10, 20, 30, 40},
        {15, 25, 35, 45},
        {27, 29, 37, 48},
        {32, 33, 39, 50}
    };
    int target = 29;

    pair<int, int> result = searchMatrix(matrix, target);

    if (result.first != -1) {
        cout << "Target " << target << " found at: (" << result.first << ", " << result.second << ")" << endl;
    } else {
        cout << "Target " << target << " not found." << endl;
    }

    return 0;
}
