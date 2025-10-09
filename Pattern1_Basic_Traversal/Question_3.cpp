//  - Find the Sum & Average of all Elements

#include <iostream>
using namespace std;

// Function to find sum of all elements
int findSum(int arr[], int n) {
    int sum = 0;
    for(int i = 0; i < n; i++) {
        sum += arr[i];
    }
    return sum;
}

// Function to find average of all elements
double findAverage(int arr[], int n) {
    int sum = findSum(arr, n); // reuse sum function
    return (double)sum / n;
}


int main() {
    int arr[] = {10, 5, 8, 20, 15};
    int n = sizeof(arr) / sizeof(arr[0]);
    int sum = findSum(arr, n);
    double average = findAverage(arr, n);

    cout << "Sum of all elements: " << sum << endl;
    cout << "Average of all elements: " << average << endl;

    return 0;
}