//  - Rearrange Positive and Negative Numbers Alternately

#include <iostream>
using namespace std;

void Rearrange_Positive_and_Negative_Numbers_Alternately(int arr[],int n){
    int left = 0;
    int right = n-1;
    while(left < right){
        if(arr[left] < 0){
            left++;
        }
        else if(arr[right] > 0){
            right--;
        }
        else{
            swap(arr[left],arr[right]);
            left++;
            right--;
        }
    }
}

int main(){
    int n;
    cout << "Enter the size of the array";
    cin >> n;

    int arr[n];
    cout << "Enter " << n << " elements of the array : " << endl;
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }

    Rearrange_Positive_and_Negative_Numbers_Alternately(arr,n);
    cout << "The segregated array is : ";
    for(int i = 0; i < n; i++){
        cout << arr[i] << " ";
    }
    return 0;
}
