// - Maximum Consecutive Ones | Count | Count continuous 1s in fixed or variable window |

#include <iostream>
using namespace std;

int maxConsecutiveOnes(int arr[], int n) {
    int maxCount = 0; // Maximum consecutive ones
    int count = 0;    // Current count of consecutive ones

    for(int i = 0; i < n; i++) {
        if(arr[i] == 1) {
            count++;               // Increment current streak
            if(count > maxCount)   // Update max
                maxCount = count;
        } else {
            count = 0;             // Reset streak on 0
        }
    }

    return maxCount;
}

int main() {
    int arr[] = {1, 1, 0, 1, 1, 1, 0, 1};
    int n = sizeof(arr) / sizeof(arr[0]);

    int result = maxConsecutiveOnes(arr, n);
    cout << "Maximum consecutive ones: " << result << endl;

    return 0;
}


