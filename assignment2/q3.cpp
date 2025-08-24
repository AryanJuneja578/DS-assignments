#include <iostream>
#include <algorithm>
using namespace std;
int linear_search(int arr[],int n){
    int i=1;
    while(i==arr[i-1]){
        i++;
    }
    cout<<i;
    return i;
}
int binary_search(int arr[],int n){
    int low=0,high= n-1,x;
    while(low<=high){
        int mid = low + ((high-low)/2);
        if(arr[mid]==mid+1){
            low=mid+1;
        }
        else{
            x=mid +1;
            high=mid-1;
            
        }
    }
        return x;
}


int main(){
    
    int arr[]={ 1 , 2 , 3 , 4 , 5 , 6 , 7 , 8 , 9  , 11 , 12 ,13 , 14 , 15 , 16 , 17 , 18 , 19 , 20 , 21 , 22 ,23, 24 , 25 };
    int n=sizeof(arr)/sizeof(arr[0]);
    // int a=linear_search(arr,n);
    int a= binary_search(arr,n);
    cout<<a;
    return 0;
}
