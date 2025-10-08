#include<iostream>
using namespace std;
//time=O(n+n/2)
//space=O(n)-->O(n/2)+O(n/2)
void rearrange_by_sign_brute(vector<int> arr,int n){
    vector<int> pos;
    vector<int> neg;
    for(int i=0;i<n;i++){
        if(arr[i]<0){
            neg.push_back(arr[i]);
        }
        else
        pos.push_back(arr[i]);
    }
    for(int i=0;i<n/2;i++){
        arr[2*i]=pos[i];
        arr[2*i+1]=neg[i];
    }
    cout<<"Rearranged array using brute approach:"<<endl;
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;

}
//time=O(n)
//space=O(n)
void rearrange_by_sign_optimal(vector<int> arr,int n){
    vector<int> ans(n,0);
    int posIndex=0,negIndex=1;
    for(int i=0;i<n;i++){
        if(arr[i]<0){
            ans[negIndex]=arr[i];
            negIndex+=2;
        }
        else{
            ans[posIndex]=arr[i];
            posIndex+=2;
        }
    }
    cout<<"Rearranged array using optimal approach:"<<endl;
    for(int i=0;i<n;i++){
        cout<<ans[i]<<" ";
    }
    cout<<endl;

}
int main(){
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    cout<<"Input Array:"<<endl;
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    rearrange_by_sign_brute(arr,n);
    rearrange_by_sign_optimal(arr,n);
}
