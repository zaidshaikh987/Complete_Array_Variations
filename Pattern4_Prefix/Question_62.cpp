// - Range Sum Queries (Static Array)

#include <iostream>
#include <vector>
using namespace std;

class RangeSum {
    vector<int> prefixSum;

public:
    RangeSum(vector<int>& arr) {
        int n = arr.size();
        prefixSum.resize(n + 1, 0);
        for (int i = 0; i < n; i++) {
            prefixSum[i + 1] = prefixSum[i] + arr[i];
        }
    }

    int getSum(int left, int right) {
        // Sum between indices [left, right] inclusive
        return prefixSum[right + 1] - prefixSum[left];
    }
};

int main() {
    vector<int> arr = {1, 2, 3, 4, 5, 6};
    RangeSum rs(arr);
    
    cout << "Sum [1, 3]: " << rs.getSum(1, 3) << endl; // 2+3+4 = 9
    cout << "Sum [0, 5]: " << rs.getSum(0, 5) << endl; // 21
    
    return 0;
}
