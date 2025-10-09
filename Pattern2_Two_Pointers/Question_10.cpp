// -  - Segregate 0s and 1s

#include <iostream>
using namespace std;

void Segregate_0s_and_1s(int arr[],int n){
    int left = 0;
    int right = n-1;
    while(left < right){
        if(arr[left] == 0){
            left++;
        }
        else if(arr[right] == 1){
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

    Segregate_0s_and_1s(arr,n);
    cout << "The segregated array is : ";
    for(int i = 0; i < n; i++){
        cout << arr[i] << " ";
    }
    return 0;
}
