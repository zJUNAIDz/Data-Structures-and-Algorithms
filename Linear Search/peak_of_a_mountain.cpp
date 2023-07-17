#include <iostream>
using namespace std;
int peak(int arr[], int size){
    for(int i = 0; i < size; i++){
        if(arr[i] > arr[i-1] && arr[i] > arr[i + 1]) return arr[i];
    }
    return -1;
}
int main(){
     int  arr[]= {0,1,2,3,4,5,6,8,9,7,5,3};
    int size=sizeof(arr)/sizeof(arr[0]);
    cout<<peak( arr,size)<<endl;
}