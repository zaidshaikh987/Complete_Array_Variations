// - Find Pairs with a Given Sum (unsorted array)

#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

void findPairsSum(vector<int>& arr, int target) {
    unordered_set<int> seen;
    bool found = false;

    for (int x : arr) {
        int complement = target - x;
        if (seen.count(complement)) {
            cout << "(" << complement << ", " << x << ")" << endl;
            found = true;
        }
        seen.insert(x);
    }

    if (!found) cout << "No pairs found." << endl;
}

int main() {
    vector<int> arr = {1, 5, 7, -1, 5};
    int target = 6;
    cout << "Pairs with sum " << target << ":" << endl;
    findPairsSum(arr, target);
    return 0;
}
