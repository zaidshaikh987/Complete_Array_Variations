//- Container With Most Water

#include <iostream>
using namespace std;

int Container_With_Most_Water(int arr[],int n){
    int Left = 0;
    int Right = n-1;
    int best = 0;
    while(Left <Right){
        int height = min(arr[Left],arr[Right]);
        int width = Right - Left;
        int currentArea = height * width;
        best = max(best,currentArea);
        if(arr[Left] < arr[Right]){
            Left++;
        }
        else{
            Right--;
        }
    }
    return best;
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

    int best = Container_With_Most_Water(arr,n);
    cout << "The maximum area of the container is : " << best << endl;
    return 0;
}
