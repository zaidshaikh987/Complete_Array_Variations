// - Find the Repeating and Missing Number (Range [1, n])

#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

// Find the number that appears twice and the number that is missing in range [1, n].
// Method: Math (Sum and Sum of Squares)
pair<int, int> findRepeatingMissing(vector<int>& arr) {
    long long n = arr.size();
    long long S = (n * (n + 1)) / 2;
    long long S2 = (n * (n + 1) * (2 * n + 1)) / 6;

    long long actualS = 0;
    long long actualS2 = 0;
    for (int x : arr) {
        actualS += x;
        actualS2 += (long long)x * x;
    }

    // val1 - val2 = actualS - S
    // val1^2 - val2^2 = actualS2 - S2
    long long diff = actualS - S; // x - y
    long long diff2 = actualS2 - S2; // x^2 - y^2 = (x - y)(x + y)

    long long sum = diff2 / diff; // x + y

    int repeating = (sum + diff) / 2;
    int missing = (sum - diff) / 2;

    return {repeating, missing};
}

int main() {
    vector<int> arr = {4, 3, 6, 2, 1, 1}; // n = 6, 1 is repeating, 5 is missing
    pair<int, int> result = findRepeatingMissing(arr);
    cout << "Repeating: " << result.first << ", Missing: " << result.second << endl;
    return 0;
}
