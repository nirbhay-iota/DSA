// Question: Find the longest subarray with sum K.
#include<iostream>
#include<map>
using namespace std;
//time comp=O(n^3)
//space comp=O(1)
void longest_subarray_brute(vector<int> arr,int n,int k){
    int longest=0;
    for(int i=0;i<n;i++){
        for(int j=i;j<n;j++){
            int sum=0;
            for(int l=i;l<=j;l++){
                sum=sum+arr[l];
            }
            if(sum==k){
                longest=max(longest,j-i+1);
            }
        }
    }
    cout<<"Longest subarray with sum k using brute approach has length: "<<longest<<endl;
}
//One for loop can be reduced in the brute force only to make the time complexity to be O(n^2)
void longest_subarray_brute_better(vector<int> arr,int n,int k){
    int longest=0;
    for(int i=0;i<n;i++){
        int sum=0;
        for(int j=i;j<n;j++){
            sum+=arr[j];
            if(sum==k){
                longest=max(longest,j-i+1);
            }
        }
    }
    cout<<"Longest subarray with sum k using brute better approach has length: "<<longest<<endl;
}
void longest_subarray_better(vector<int> arr,int n,long long k){
    map<long long,int> preSumMap;
    int longest=0;
    long long sum=0;
    for(int i=0;i<n;i++){
        sum+=arr[i];
        if(sum==k){
            longest=max(longest,i+1);     //this if is only for the condition when first element=k
        }
        long long remaining=sum-k;
        if(preSumMap.find(remaining) != preSumMap.end()){
            int length=i-preSumMap[remaining];    //this gives the length of subarray...preSumMap[remaining] gives value at key remaining
            
        }

    }
}
int main(){
    int n;
    cin>>n;
    vector <int> arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    long long k;
    cout<<"Enter value of K"<<endl;
    cin>>k;
    cout<<"Input Array"<<endl;
    for(int i=0;i<n-1;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    longest_subarray_brute(arr,n,k);
    longest_subarray_brute_better(arr,n,k);
    cout<<endl;
}