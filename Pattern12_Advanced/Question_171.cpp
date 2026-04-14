// - Range Minimum Query (RMQ) using Segment Tree

#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

// Find the minimum element in a given range [L, R].
class SegmentTree {
    int n;
    vector<int> tree;

public:
    SegmentTree(vector<int>& arr) {
        n = arr.size();
        tree.resize(4 * n);
        build(arr, 1, 0, n - 1);
    }

    void build(vector<int>& arr, int node, int start, int end) {
        if (start == end) {
            tree[node] = arr[start];
            return;
        }
        int mid = (start + end) / 2;
        build(arr, 2 * node, start, mid);
        build(arr, 2 * node + 1, mid + 1, end);
        tree[node] = min(tree[2 * node], tree[2 * node + 1]);
    }

    int query(int node, int start, int end, int L, int R) {
        if (R < start || end < L) return INT_MAX;
        if (L <= start && end <= R) return tree[node];

        int mid = (start + end) / 2;
        int leftMin = query(2 * node, start, mid, L, R);
        int rightMin = query(2 * node + 1, mid + 1, end, L, R);
        return min(leftMin, rightMin);
    }

    int rangeMin(int L, int R) {
        return query(1, 0, n - 1, L, R);
    }
};

int main() {
    vector<int> arr = {1, 3, 2, 7, 9, 11};
    SegmentTree st(arr);

    cout << "Range Minimum Query [1, 4]: " << st.rangeMin(1, 4) << endl; // 2
    cout << "Range Minimum Query [0, 5]: " << st.rangeMin(0, 5) << endl; // 1
    
    return 0;
}
