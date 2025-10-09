// - Find the Second Largest/Smallest Element

#include <iostream>
#include <climits>
using namespace std;

int find_Second_Largest_Element(int arr[], int n){
    int first = INT_MIN;
    int second = INT_MIN;
    for (int i = 0; i < n; i++){
        if (arr[i] > first){
            second = first;
            first = arr[i];
        } else if (arr[i] < first && arr[i] > second){
            second = arr[i];
        }
    }
    if (second == INT_MIN){
        return -1; // No second largest (all equal or <2 unique values)
    }
    return second;
}

int main(){
    int n;
    cout << "Enter the size of the array";
    cin >> n;

    if (n < 2){
        cout << "Array must have at least 2 elements" << endl;
        return 0;
    }

    int* arr = new int[n];
    cout << "Enter " << n << " elements of the array: " << endl;
    for (int i = 0; i < n ; i++){
        cin >> arr[i];
    }

    int Second_Max_Element = find_Second_Largest_Element(arr, n);

    if(Second_Max_Element!= -1){
    cout << "The second largest element in the array is : " << Second_Max_Element << endl;
    }
    else{
        cout << "No second largest element found" << endl;
    }
    delete[] arr;
    return 0;
}