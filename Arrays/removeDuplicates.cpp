#include <iostream>
using namespace std;
void reduce_duplicates_optimal(int arr[],int n){
    int index=0;
    for(int i=1;i<n;i++){
        if(arr[i]!=arr[index]){
            index++;
            arr[index]=arr[i];
        }
    }
    for(int i=0;i<=index;i++){
        cout<<arr[i]<<" ";
    }
}
void reduce_duplicates_brute(int arr[],int n){
    for(int i=0;i<n;i++){
        for(int j=i;j<n;j++){
            if(arr[j+1]>arr[i]){
                arr[i+1]=arr[j+1];
                break;
            }
        }
    }
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
}
  

int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    cout<<"input array"<<endl;
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    reduce_duplicates_optimal(arr,n);
    reduce_duplicates_brute(arr,n);
}    