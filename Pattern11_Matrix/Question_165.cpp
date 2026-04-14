// - Matrix Path Finding (Simple Path Existence)

#include <iostream>
#include <vector>
using namespace std;

// Check if there's a path from (0,0) to (m-1, n-1) using only 1s.
// Allowed moves: Right, Down.
bool hasPath(vector<vector<int>>& matrix, int r, int c, vector<vector<int>>& memo) {
    int rows = matrix.size();
    int cols = matrix[0].size();

    if (r == rows - 1 && c == cols - 1) return matrix[r][c] == 1;
    if (r >= rows || c >= cols || matrix[r][c] == 0) return false;

    if (memo[r][c] != -1) return memo[r][c];

    return memo[r][c] = (hasPath(matrix, r + 1, c, memo) || hasPath(matrix, r, c + 1, memo));
}

int main() {
    vector<vector<int>> matrix = {
        {1, 1, 0, 1},
        {0, 1, 1, 0},
        {1, 0, 1, 1},
        {1, 1, 1, 1}
    };
    int rows = matrix.size();
    int cols = matrix[0].size();
    vector<vector<int>> memo(rows, vector<int>(cols, -1));

    if (hasPath(matrix, 0, 0, memo)) {
        cout << "Path exists from top-left to bottom-right." << endl;
    } else {
        cout << "No path exists." << endl;
    }

    return 0;
}
