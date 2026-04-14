// - Transpose of a Matrix

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// The transpose of a matrix is found by swapping elements across the main diagonal.
// This version handles non-square matrices by creating a new matrix.
vector<vector<int>> transpose(vector<vector<int>>& matrix) {
    int rows = matrix.size();
    if (rows == 0) return {};
    int cols = matrix[0].size();

    vector<vector<int>> result(cols, vector<int>(rows));
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result[j][i] = matrix[i][j];
        }
    }
    return result;
}

void printMatrix(vector<vector<int>>& matrix) {
    for (const auto& row : matrix) {
        for (int x : row) cout << x << " ";
        cout << endl;
    }
}

int main() {
    vector<vector<int>> matrix = {
        {1, 2, 3},
        {4, 5, 6}
    };

    cout << "Original Matrix:" << endl;
    printMatrix(matrix);

    vector<vector<int>> result = transpose(matrix);

    cout << endl << "Transposed Matrix:" << endl;
    printMatrix(result);

    return 0;
}
