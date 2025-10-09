// Find the Maximum/Minimum Element

// A] Max_Element

#include <iostream>
using namespace std;

int find_Maximum_Element(int arr[],int n){
    int max = arr[0];
    for(int i = 0; i < n ; i++){
        if(arr[i] > max){
            max = arr[i];
        }
    }
    return max;
}

int main(){
    int n;
    cout << "Enter the size of the array";
    cin >> n;

    int arr[n];
    cout << "Enter" << n << "elements of the array : " << endl;
    for (int i = 0; i < n ; i++){
        cin >> arr[i];
    }

    int Max_Element = find_Maximum_Element(arr, n);
    cout << "The largest element in the array is : " << Max_Element << endl;
    return 0;
}


// B] Min_Element 

#include <iostream>
using namespace std;

int find_Minimum_Element(int arr[],int n){
    int min = arr[0];
    for(int i = 0; i < n ; i++){
        if(arr[i] < min){
            min = arr[i];
        }
    }
    return min;
}

int main(){
    int n;
    cout << "Enter the size of the array : ";
    cin >> n;

    int arr[n];
    cout << "Enter " << n << " elements of the array : " << endl;
    for (int i = 0; i < n ; i++){
        cin >> arr[i];
    }

    int Min_Element = find_Minimum_Element(arr, n);
    cout << "The smallest element in the array is : " << Min_Element << endl;
    return 0;
}