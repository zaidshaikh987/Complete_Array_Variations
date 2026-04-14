// - Trapping Rain Water

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int trap(vector<int>& height) {
    int n = height.size();
    if (n <= 2) return 0;

    int left = 0, right = n - 1;
    int leftMax = 0, rightMax = 0;
    int waterTrapped = 0;

    while (left < right) {
        if (height[left] < height[right]) {
            if (height[left] >= leftMax) {
                leftMax = height[left];
            } else {
                waterTrapped += leftMax - height[left];
            }
            left++;
        } else {
            if (height[right] >= rightMax) {
                rightMax = height[right];
            } else {
                waterTrapped += rightMax - height[right];
            }
            right--;
        }
    }

    return waterTrapped;
}

int main() {
    int n;
    cout << "Enter the number of bars: ";
    cin >> n;

    vector<int> height(n);
    cout << "Enter the height of " << n << " bars: ";
    for (int i = 0; i < n; i++) cin >> height[i];

    int result = trap(height);
    cout << "Total water trapped: " << result << endl;

    return 0;
}
