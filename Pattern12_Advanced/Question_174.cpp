// - Equilibrium Index of an Array

#include <iostream>
#include <vector>
#include <numeric>
using namespace std;

// An equilibrium index is an index such that the sum of elements at lower 
// indices is equal to the sum of elements at higher indices.
// Method: Prefix Sum / Running Sum (O(n))
int findEquilibriumIndex(vector<int>& arr) {
    long long totalSum = accumulate(arr.begin(), arr.end(), 0LL);
    long long leftSum = 0;

    for (int i = 0; i < arr.size(); i++) {
        // totalSum - leftSum - currentElement = rightSum
        if (leftSum == (totalSum - leftSum - arr[i])) {
            return i;
        }
        leftSum += arr[i];
    }

    return -1;
}

int main() {
    vector<int> arr = {-7, 1, 5, 2, -4, 3, 0};
    // Sums: 
    // i=3: left = -7+1+5 = -1; right = -4+3+0 = -1 (Equilibrium!)
    int result = findEquilibriumIndex(arr);
    if (result != -1) {
        cout << "Equilibrium index found at: " << result << endl;
    } else {
        cout << "No equilibrium index found." << endl;
    }
    return 0;
}
