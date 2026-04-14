// - Find the Row with the Maximum Number of 1s

#include <iostream>
#include <vector>
using namespace std;

// Each row is sorted. Find the row with the most 1s.
// Method: Staircase approach (O(m + n))
int rowWithMax1s(vector<vector<int>>& matrix) {
    int rows = matrix.size();
    if (rows == 0) return -1;
    int cols = matrix[0].size();

    int maxRowIndex = -1;
    // Start from the top-right corner
    int j = cols - 1;

    for (int i = 0; i < rows; i++) {
        // Move left as long as we find 1s
        while (j >= 0 && matrix[i][j] == 1) {
            j--;
            maxRowIndex = i;
        }
    }

    return maxRowIndex;
}

int main() {
    vector<vector<int>> matrix = {
        {0, 1, 1, 1},
        {0, 0, 1, 1},
        {1, 1, 1, 1},
        {0, 0, 0, 0}
    };

    int result = rowWithMax1s(matrix);
    if (result != -1) {
        cout << "Row with the maximum number of 1s is: " << result << endl;
    } else {
        cout << "No 1s found in the matrix." << endl;
    }

    return 0;
}
