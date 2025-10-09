//  - Move all Zeros to the End
#include <iostream>
using namespace std;

void MoveZeroesToEnd(int arr[],int n){
    int Left = 0;
    int Right = n-1;
    while(Left < Right){
        if(arr[Left] != 0){
            Left++;
        }
        else if(arr[Right] == 0){
            Right--;
        }
        else{
            swap(arr[Left],arr[Right]);
            Left++;
            Right--;
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

    MoveZeroesToEnd(arr,n);
    cout << "The segregated array is : ";
    for(int i = 0; i < n; i++){
        cout << arr[i] << " ";
    }
    return 0;
}
