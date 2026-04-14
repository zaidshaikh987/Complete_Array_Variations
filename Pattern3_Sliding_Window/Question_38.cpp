// | - Smallest Subarray with Sum ≥ S | Shrinking window | Minimize window length for sum ≥ S |
 
#include <iostream>
#include <climits>
using namespace std;

// Function to find smallest subarray length with sum ≥ S
int smallestSubarrayWithSum(int arr[], int n, int S) {
    int left = 0;
    int currentSum = 0;
    int minLength = INT_MAX;

    // Expand the right pointer
    for (int right = 0; right < n; right++) {
        currentSum += arr[right]; // Add current element to window

        // Shrink from left while sum ≥ S
        while (currentSum >= S) {
            // Update smallest length if this window is smaller
            int currentLength = right - left + 1;
            if (currentLength < minLength)
                minLength = currentLength;

            // Remove element at 'left' and move left forward
            currentSum -= arr[left];
            left++;
        }
    }

    // If no subarray found, return 0
    if (minLength == INT_MAX)
        return 0;

    return minLength;
}

// Main function to take input and call the function
int main() {
    int n, S;

    cout << "Enter number of elements: ";
    cin >> n;

    int arr[n];
    cout << "Enter elements: ";
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    cout << "Enter target sum S: ";
    cin >> S;

    int result = smallestSubarrayWithSum(arr, n, S);
    cout << "\nSmallest subarray length = " << result << endl;

    return 0;
}
