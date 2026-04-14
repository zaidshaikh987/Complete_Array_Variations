// - Running Average of Stream

#include <iostream>
#include <vector>
using namespace std;

// This calculates the rolling average for every new element in a stream.

class RunningAverage {
    double sum;
    int count;

public:
    RunningAverage() : sum(0), count(0) {}

    double next(int val) {
        sum += val;
        count++;
        return sum / count;
    }
};

int main() {
    RunningAverage ra;
    vector<int> stream = {1, 10, 3, 5};
    
    cout << "Running averages: " << endl;
    for (int x : stream) {
        cout << "Value: " << x << " -> Average: " << ra.next(x) << endl;
    }
    
    return 0;
}
