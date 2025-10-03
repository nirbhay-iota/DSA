//Question:Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.
//You may assume that each input would have exactly one solution, and you may not use the same element twice.
//You can return the answer in any order.
#include<iostream>
#include<map>
#include<algorithm>
using namespace std;
//time comp=O(n^2)
//space=O(1)
void two_sum_brute(vector<int> arr,int target){
    int sum=0;
    for(int i=0;i<arr.size();i++){
        for(int j=i+1;j<arr.size();j++){
            if(arr[i]+arr[j]==target){
                cout<<"Answer by brute approach"<<"["<<i<<","<<j<<"]"<<endl;
            }
        }
    }
}
//time comp=O(nlogn)..n for for loop and log n for finfing in map.
//if we use unordered map we can reduce time comp to O(n) as unordered map has average TC of O(1)...but is worst case it can become O(n^2)
//space comp=O(n)...space for the hashmap
void two_sum_better(vector<int> arr,int target){
    map<long long,int> mpp;
    for(int i=0;i<arr.size();i++){
        int rem=target-arr[i];
        if(mpp.find(rem)!=mpp.end()){
            cout<<"Answer by brute approach"<<"["<<mpp[rem]<<","<<i<<"]"<<endl;
        }
        if(mpp.find(arr[i])==mpp.end()){
            mpp[arr[i]]=i;
        }

    }
}
//The above better approach is the optimal one for the problem in which we have to return indices of the the elements.
//but if we just have to tell if 2 elements exit whose sum is equal to targes as YES or NO..then we can optimise it
//by 2 pointer approach only
//time=O(n)+O(nlogn)...O(n) for the while loop and O(nlogn) for sorting the array.
//space=O(1)...no extra space needed...sorting is done in same array only
void two_sum_optimal(vector<int> arr,int target){
    int left=0,right=arr.size()-1;
    int sum=0;
    sort(arr.begin(),arr.end());
    while(left<right){
        sum=arr[left]+arr[right];
        if(sum<target){
            left++;
        }
        if(sum>target){
            right--;
        }
        if(sum==target){
            left++;
            right--;
            cout<<"Yes"<<endl;

        }
    }
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
    int target;
    cout<<"Enter Target"<<endl;
    cin>>target;
    two_sum_brute(arr,target);
    two_sum_better(arr,target);
    two_sum_optimal(arr,target);
}