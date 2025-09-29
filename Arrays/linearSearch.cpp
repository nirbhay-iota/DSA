#include<iostream>
using namespace std;
//time complexity=O(n)
int linear_search(vector<int> arr,int n,int x){
    for(int i=0;i<n;i++){
        if(arr[i]==x){
        return i;
        }
    }
    return -1;
}
int main(){
    int n;
    cin>>n;
    vector<int> arr(n);
    
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    cout<<"input array:"<<endl;
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    cout<<"input number"<<endl;
    int x;
    cin>>x;
    int ans=linear_search(arr,n,x);
    cout<<"index:"<<ans<<endl;
    
}