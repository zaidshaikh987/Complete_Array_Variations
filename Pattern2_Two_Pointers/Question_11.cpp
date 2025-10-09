// - Sort Array by Parity (Segregate Even and Odd Numbers)

#include<iostream>
using namespace std;

void Sort_Array_by_Parity(int arr[],int n){
    int left = 0;
    int right = n-1;
    while(left < right){
        if(arr[left] % 2 == 0){
            left++;
        }
        else if(arr[right] % 2 == 1){
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

    Sort_Array_by_Parity(arr,n);
    cout << "The segregated array is : ";
    for(int i = 0; i < n; i++){
        cout << arr[i] << " ";
    }
    return 0;
}
