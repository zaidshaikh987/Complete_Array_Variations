// - Minimize Maximum Distance to Gas Station (Binary Search on Answer Space)

#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;

// Find the minimum distance such that all gas stations are at most this distance apart.
// We can add 'k' additional gas stations.
// Method: Binary Search on the distance (O(n log(max_dist / precision)))
bool canPlace(vector<int>& stations, int k, double maxDist) {
    int count = 0;
    for (int i = 0; i < stations.size() - 1; i++) {
        double dist = stations[i + 1] - stations[i];
        count += (int)(dist / maxDist);
    }
    return count <= k;
}

double minMaxDistance(vector<int>& stations, int k) {
    double low = 0, high = stations.back() - stations[0];
    double precision = 1e-6;

    while (high - low > precision) {
        double mid = low + (high - low) / 2.0;
        if (canPlace(stations, k, mid)) {
            high = mid;
        } else {
            low = mid;
        }
    }
    return high;
}

int main() {
    vector<int> stations = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int k = 9;
    cout << fixed << setprecision(6);
    cout << "Minimum possible maximum distance: " << minMaxDistance(stations, k) << endl; 
    return 0;
}
