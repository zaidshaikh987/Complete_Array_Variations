// - Find Nth Root of an Integer (Binary Search on Answer Space)

#include <iostream>
#include <cmath>
using namespace std;

// Method: Binary Search (O(log(m) * log(n)))
// Checks if mid^n is <, == or > m. 
// 0: ==, 1: >, 2: <
int check(long long mid, int n, long long m) {
    long long ans = 1;
    for (int i = 1; i <= n; i++) {
        ans *= mid;
        if (ans > m) return 1;
    }
    if (ans == m) return 0;
    return 2;
}

int getNthRoot(int n, int m) {
    int low = 1, high = m;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        int res = check(mid, n, m);
        if (res == 0) return mid;
        else if (res == 1) high = mid - 1;
        else low = mid + 1;
    }
    return -1;
}

int main() {
    int n, m;
    cout << "Enter n (root) and m (number): ";
    cin >> n >> m;
    int result = getNthRoot(n, m);
    if (result != -1) {
        cout << n << "-th root of " << m << " is " << result << endl;
    } else {
        cout << n << "-th root of " << m << " does not exist as an integer." << endl;
    }
    return 0;
}
