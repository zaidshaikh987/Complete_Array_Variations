// - Spiral Traversal of a Matrix

#include <iostream>
#include <vector>
using namespace std;

// Traverse a matrix in spiral order.
vector<int> spiralOrder(vector<vector<int>>& matrix) {
    if (matrix.empty()) return {};

    int rows = matrix.size();
    int cols = matrix[0].size();
    vector<int> result;

    int top = 0, bottom = rows - 1;
    int left = 0, right = cols - 1;

    while (top <= bottom && left <= right) {
        // Move right
        for (int i = left; i <= right; i++) {
            result.push_back(matrix[top][i]);
        }
        top++;

        // Move down
        for (int i = top; i <= bottom; i++) {
            result.push_back(matrix[i][right]);
        }
        right--;

        // Move left
        if (top <= bottom) {
            for (int i = right; i >= left; i--) {
                result.push_back(matrix[bottom][i]);
            }
            bottom--;
        }

        // Move up
        if (left <= right) {
            for (int i = bottom; i >= top; i--) {
                result.push_back(matrix[i][left]);
            }
            left++;
        }
    }

    return result;
}

int main() {
    vector<vector<int>> matrix = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12}
    };

    vector<int> result = spiralOrder(matrix);

    cout << "Spiral Order traversal:" << endl;
    for (int x : result) cout << x << " ";
    cout << endl;

    return 0;
}
