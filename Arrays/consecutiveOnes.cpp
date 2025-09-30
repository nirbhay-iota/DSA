#include<iostream>
using namespace std;
//time comp=O(n)
//space comp=O(1)
void consecutive_ones(vector <int > arr, int n){
    int largest=0,consecutive=0;
    for(int i=0;i<n;i++){
        if(arr[i]==1){
            consecutive++;
        }
        if(largest<consecutive){
            largest=consecutive;
        }
        if(arr[i]==0){
            consecutive=0;
        }
    }
    cout<<largest<<endl;

}
int main(){
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    cout<<"input array"<<endl;
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    consecutive_ones(arr,n);

}