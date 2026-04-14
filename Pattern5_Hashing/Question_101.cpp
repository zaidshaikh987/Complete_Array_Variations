// - Happy Number (Cycle detection using Hash Set)

#include <iostream>
#include <unordered_set>
using namespace std;

// A happy number is a number which eventually reaches 1 when replaced
// by the sum of squares of its digits.
int sumOfSquares(int n) {
    int sum = 0;
    while (n > 0) {
        int digit = n % 10;
        sum += digit * digit;
        n /= 10;
    }
    return sum;
}

bool isHappy(int n) {
    unordered_set<int> seen;
    while (n != 1 && !seen.count(n)) {
        seen.insert(n);
        n = sumOfSquares(n);
    }
    return n == 1;
}

int main() {
    int n;
    cout << "Enter a number: ";
    cin >> n;
    
    if (isHappy(n)) {
        cout << n << " is a Happy Number!" << endl;
    } else {
        cout << n << " is not a Happy Number." << endl;
    }
    
    return 0;
}
