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
//preSumMap.end() means not found....{.end() gives the element which is one past the last element}
//time comp=O(n*logn)... n for the for loop and logn for finding in the hashmap
//time complexity can be reduced to O(n*1)..if we use an unordered map but in the worst with collisions
//..an unordered map finding time is n so in the worst case it can become O(n^2)...that's why we use ordered map with worst case TC=O(nlogn)
//space comp=O(n)-->for the hashmap
void longest_subarray_better(vector<int> arr,int n,long long k){
    map<long long,int> preSumMap;
    int longest=0;
    long long sum=0;
    for(int i=0;i<n;i++){
        sum+=arr[i];
        if(sum==k){
            longest=max(longest,i+1);     //this is for the condition if the starting elements make up to k
                                          //ex...there was 1,1,1 in the starting 
        }

        long long remaining=sum-k;
        //read point 4 of readme once
        //So this if statement returns true if find(remaining) is no equal to not found...i.e. it is present in map
        if(preSumMap.find(remaining) != preSumMap.end()){
            int length=i-preSumMap[remaining];    //this gives the length of subarray...preSumMap[remaining] gives value at key remaining
            longest=max(longest,length);
        }

        if(preSumMap.find(sum)==preSumMap.end()){
            preSumMap[sum]=i;
        }
    }
    cout<<"Longest subarray with sum k using better approach has length: "<<longest<<endl;
}
//We will apply kind of a 2 pointer and greedy approach
//time comp=O(n)
//space comp=O(1)
void longest_subarray_optimal(vector<int> arr,int n,long long k){
    int j=0,sum=0,longest=0;
    for(int i=0;i<n;i++){
        sum+=arr[i];
        if(sum>k){
            sum=sum-arr[j];
            j++;
        }
        if(sum==k){
            int length=i-j+1;
            longest=max(longest,length);
        }
    }
    cout<<"Longest subarray with sum k using optimal approach has length: "<<longest<<endl;
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
    longest_subarray_better(arr,n,k);
    longest_subarray_optimal(arr,n,k);}
}
