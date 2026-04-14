// - Square Root of a Number (Binary Search on Answer Space)

#include <iostream>
using namespace std;

// Find the floor of the square root of n.
// Method: Binary Search (O(log n))
long long floorSqrt(long long n) {
    if (n == 0 || n == 1) return n;

    long long low = 1, high = n, ans = 0;
    while (low <= high) {
        long long mid = low + (high - low) / 2;
        
        if (mid <= n / mid) {
            ans = mid;
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return ans;
}

int main() {
    long long n;
    cout << "Enter a number: ";
    cin >> n;
    cout << "Floor of square root of " << n << " is: " << floorSqrt(n) << endl;
    return 0;
}
