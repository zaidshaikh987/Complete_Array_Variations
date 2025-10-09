#include <iostream>
#include <algorithm>
using namespace std;

void threeSum(int arr[], int n, int target) {
    sort(arr, arr + n); // sort the array

    bool found = false; // to track if any triplet is found

    for(int i = 0; i < n - 2; i++){
        // skip duplicates for i
        if(i > 0 && arr[i] == arr[i-1])
            continue;

        int left = i + 1;
        int right = n - 1;

        while(left < right){
            int currentSum = arr[i] + arr[left] + arr[right];

            if(currentSum == target){
                cout << arr[i] << " " << arr[left] << " " << arr[right] << endl;
                found = true;

                // skip duplicates for left
                while(left < right && arr[left] == arr[left + 1]) left++;
                // skip duplicates for right
                while(left < right && arr[right] == arr[right - 1]) right--;

                left++;
                right--;
            }
            else if(currentSum < target){
                left++;
            }
            else{
                right--;
            }
        }
    }

    if(!found)
        cout << "No triplets found" << endl;
}

int main() {
    int n;
    cout << "Enter the size of the array: ";
    cin >> n;

    int arr[n];
    cout << "Enter " << n << " elements of the array: " << endl;
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }

    int target;
    cout << "Enter the target: ";
    cin >> target;

    threeSum(arr, n, target);
    return 0;
}
