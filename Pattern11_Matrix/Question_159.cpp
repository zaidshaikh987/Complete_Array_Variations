// - Rotate a Matrix by 90 Degrees (In-place)

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Method: Transpose then Reverse each row (O(n^2) time, O(1) space)
void rotateMatrix(vector<vector<int>>& matrix) {
    int n = matrix.size();

    // 1. Transpose the matrix
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            swap(matrix[i][j], matrix[j][i]);
        }
    }

    // 2. Reverse each row
    for (int i = 0; i < n; i++) {
        reverse(matrix[i].begin(), matrix[i].end());
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
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    cout << "Original Matrix:" << endl;
    printMatrix(matrix);

    rotateMatrix(matrix);

    cout << endl << "Rotated Matrix (90 degrees clockwise):" << endl;
    printMatrix(matrix);

    return 0;
}
