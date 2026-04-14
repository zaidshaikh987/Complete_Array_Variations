// - Largest Rectangle in a Binary Matrix

#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

// Find the area of the largest rectangle containing only 1s in a binary matrix.
// Method: Histograms for each row (O(m * n))
int largestRectangleAreaInHistogram(vector<int>& heights) {
    stack<int> s;
    int maxArea = 0;
    int n = heights.size();

    for (int i = 0; i <= n; i++) {
        int h = (i == n) ? 0 : heights[i];
        while (!s.empty() && h < heights[s.top()]) {
            int height = heights[s.top()];
            s.pop();
            int width = s.empty() ? i : i - s.top() - 1;
            maxArea = max(maxArea, height * width);
        }
        s.push(i);
    }
    return maxArea;
}

int maximalRectangle(vector<vector<int>>& matrix) {
    if (matrix.empty()) return 0;
    int rows = matrix.size();
    int cols = matrix[0].size();
    vector<int> heights(cols, 0);
    int maxArea = 0;

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (matrix[i][j] == 1) {
                heights[j]++;
            } else {
                heights[j] = 0;
            }
        }
        maxArea = max(maxArea, largestRectangleAreaInHistogram(heights));
    }
    return maxArea;
}

int main() {
    vector<vector<int>> matrix = {
        {1, 0, 1, 0, 0},
        {1, 0, 1, 1, 1},
        {1, 1, 1, 1, 1},
        {1, 0, 0, 1, 0}
    };

    cout << "Area of the largest rectangle with all 1s: " << maximalRectangle(matrix) << endl; // 6
    return 0;
}
