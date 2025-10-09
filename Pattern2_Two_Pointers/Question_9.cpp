//  - Reverse an Array

#include <iostream>
#include <algorithm>
using namespace std;

void Reverse_Array(int arr[],int n){
    int start = 0;
    int end = n-1;
    while(start < end){
        swap(arr[start],arr[end]);
        start++;
        end--;
    }
}

int main(){
    int n;
    cout << " Enter the size of the array";
    cin >> n;

    int arr[n];
    cout << "Enter " << n << " elements of the array : " << endl;
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }

    Reverse_Array(arr,n);
    cout << "The reversed array is : ";
    for(int i = 0; i < n; i++){
        cout << arr[i] << " ";
    }
    return 0;
}