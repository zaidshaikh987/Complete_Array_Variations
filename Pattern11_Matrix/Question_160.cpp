// - Set Matrix Zeros

#include <iostream>
#include <vector>
using namespace std;

// If an element is 0, set its entire row and column to 0.
// Method: Using first row and first column as markers (O(1) space, O(m*n) time)
void setZeroes(vector<vector<int>>& matrix) {
    int rows = matrix.size();
    int cols = matrix[0].size();
    bool firstRowZero = false;
    bool firstColZero = false;

    // Check if first row needs to be zeroed
    for (int j = 0; j < cols; j++) {
        if (matrix[0][j] == 0) firstRowZero = true;
    }

    // Check if first column needs to be zeroed
    for (int i = 0; i < rows; i++) {
        if (matrix[i][0] == 0) firstColZero = true;
    }

    // Use first row and column as markers
    for (int i = 1; i < rows; i++) {
        for (int j = 1; j < cols; j++) {
            if (matrix[i][j] == 0) {
                matrix[i][0] = 0;
                matrix[0][j] = 0;
            }
        }
    }

    // Set zeros based on markers
    for (int i = 1; i < rows; i++) {
        for (int j = 1; j < cols; j++) {
            if (matrix[i][0] == 0 || matrix[0][j] == 0) {
                matrix[i][j] = 0;
            }
        }
    }

    // Zero out first row and column if needed
    if (firstRowZero) {
        for (int j = 0; j < cols; j++) matrix[0][j] = 0;
    }
    if (firstColZero) {
        for (int i = 0; i < rows; i++) matrix[i][0] = 0;
    }
}

void printMatrix(vector<vector<int>>& matrix) {
    for (const auto& row : matrix) {
        for (int x : row) cout << x << " ";
        cout << endl;
    }
}

int main() {
    vector<vector<int>> matrix = {
        {1, 1, 1},
        {1, 0, 1},
        {1, 1, 1}
    };

    cout << "Original Matrix:" << endl;
    printMatrix(matrix);

    setZeroes(matrix);

    cout << endl << "Matrix after Set Zeroes:" << endl;
    printMatrix(matrix);

    return 0;
}
