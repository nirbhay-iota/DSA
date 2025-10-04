#include<iostream>
using namespace std;
//The brute force will be obviously just a normal merge sort 
//time comp=O(2n)...one n for the counters and the other for the 3 for loops which run for n times
//space=O(1)
void sort_array_better(vector<int> arr,int n){
    int cnt0=0,cnt1=0,cnt2=0;
    for(int i=0;i<n;i++){
        if(arr[i]==0)
        cnt0++;
        if(arr[i]==1)
        cnt1++;
        if(arr[i]==2)
        cnt2++;
        
    }
    //These all 3 loops actually run over just n times so these 3 loops together account for O(n) TC.
    for(int i=0;i<cnt0;i++){
        arr[i]=0;
    }
    for(int i=cnt0;i<cnt1+cnt0;i++){
        arr[i]=1;
    }
    for(int i=cnt1+cnt0;i<cnt2+cnt1+cnt0;i++){
        arr[i]=2;
    }
    cout<<"Output array by better method:"<<endl;
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

//Read point 5 of readme to understand the algorithm
//time=O(n)
//space=O(1)
void sort_array_optimal(vector<int> arr,int n){
    int low=0,mid=0,high=n-1;
    while(mid<=high){
        if(arr[mid]==0){
            swap(arr[mid],arr[low]);
            low++;
            mid++;
        }
        else if(arr[mid]==1){
            mid++;
        }
        else{
            swap(arr[mid],arr[high]);
            high--;
        }
    }
    cout<<"Output array by optimal method:"<<endl;
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }

}
int main(){
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    cout<<"Input array:"<<endl;
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    sort_array_better(arr,n);
    sort_array_optimal(arr,n);

}