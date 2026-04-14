// - Count of Smaller Elements Before Self

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// This can be solved using Fenwick Tree or Segment Tree for efficiency.
// Here we use a Fenwick Tree (Binary Indexed Tree) to count frequencies.

class FenwickTree {
    vector<int> tree;
    int size;

public:
    FenwickTree(int n) : size(n) {
        tree.resize(n + 1, 0);
    }

    void update(int i, int val) {
        for (; i <= size; i += i & -i) {
            tree[i] += val;
        }
    }

    int query(int i) {
        int sum = 0;
        for (; i > 0; i -= i & -i) {
            sum += tree[i];
        }
        return sum;
    }
};

vector<int> countSmallerBeforeSelf(vector<int>& arr) {
    int n = arr.size();
    if (n == 0) return {};

    // Coordinate compression for negative numbers or large values
    vector<int> sortedArr = arr;
    sort(sortedArr.begin(), sortedArr.end());
    sortedArr.erase(unique(sortedArr.begin(), sortedArr.end()), sortedArr.end());

    auto getRank = [&](int val) {
        return lower_bound(sortedArr.begin(), sortedArr.end(), val) - sortedArr.begin() + 1;
    };

    FenwickTree ft(sortedArr.size());
    vector<int> result(n);

    for (int i = 0; i < n; i++) {
        int rank = getRank(arr[i]);
        result[i] = ft.query(rank - 1); // Count elements with smaller rank
        ft.update(rank, 1);
    }

    return result;
}

int main() {
    vector<int> arr = {5, 2, 6, 1, 3};
    vector<int> result = countSmallerBeforeSelf(arr);

    cout << "Count of smaller elements before self: ";
    for (int x : result) cout << x << " ";
    cout << endl;

    return 0;
}
