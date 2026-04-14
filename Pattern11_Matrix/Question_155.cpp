// - Traverse a 2D Array (Row-wise and Column-wise)

#include <iostream>
#include <vector>
using namespace std;

void traverseRowWise(vector<vector<int>>& matrix) {
    int rows = matrix.size();
    if (rows == 0) return;
    int cols = matrix[0].size();

    cout << "Row-wise traversal:" << endl;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}

void traverseColumnWise(vector<vector<int>>& matrix) {
    int rows = matrix.size();
    if (rows == 0) return;
    int cols = matrix[0].size();

    cout << "Column-wise traversal:" << endl;
    for (int j = 0; j < cols; j++) {
        for (int i = 0; i < rows; i++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    vector<vector<int>> matrix = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    traverseRowWise(matrix);
    cout << endl;
    traverseColumnWise(matrix);

    return 0;
}
