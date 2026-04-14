// - Diagonal Traversal of a Matrix

#include <iostream>
#include <vector>
#include <map>
using namespace std;

// Traverse a matrix diagonally.
// Elements on the same diagonal have the same row + col sum.
vector<int> diagonalTraversal(vector<vector<int>>& matrix) {
    if (matrix.empty()) return {};

    int rows = matrix.size();
    int cols = matrix[0].size();
    map<int, vector<int>> diagonals;

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            diagonals[i + j].push_back(matrix[i][j]);
        }
    }

    vector<int> result;
    bool flip = true;
    for (auto& [sum, diag] : diagonals) {
        if (flip) {
            for (int i = diag.size() - 1; i >= 0; i--) {
                result.push_back(diag[i]);
            }
        } else {
            for (int x : diag) {
                result.push_back(x);
            }
        }
        flip = !flip;
    }
    return result;
}

int main() {
    vector<vector<int>> matrix = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    vector<int> result = diagonalTraversal(matrix);

    cout << "Diagonal Traversal (Zigzag):" << endl;
    for (int x : result) cout << x << " ";
    cout << endl;

    return 0;
}
