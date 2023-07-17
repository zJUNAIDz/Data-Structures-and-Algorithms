#include <iostream>
using namespace std;

// returning index of peak position in a mountain array
int peak(int arr[],int size){
    int start = 0;
    int end = size;
    int mid = start + (end-start) / 2;
    while(start < end){
        // if(arr[mid] > arr[mid -1] && arr[mid] > arr[mid+1]) return mid;
        if(arr[mid] < arr[mid+1]) start = mid + 1;
        // else if(arr[mid] > arr[mid+1]) end = mid ;
        else  end = mid ;

        mid =start + (end-start) / 2;
    }
    return start;   
}
int main(){
    int arr[]= {0,1,2,3,4,5,6,6,7,8,9,6,5,3,1};
    int arr_size = sizeof(arr)/sizeof(arr[0]);
    cout << "Index of Peak Element : " << peak(arr,arr_size) << endl;
}



