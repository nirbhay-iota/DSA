//Question: Find the number that appears only once in the array while all tha others appear twice
#include<iostream>
#include<map>
using namespace std;
//time comp=O(2n)
//space comp=O(hash.size())
void number_only_once_hash(vector<int> arr,int n){
    vector<int> hash(n+1);//here I am assuming that the maximum element possible in the array will be n.
                          //but if it is not given then we have to keep the size of the array hash as 
                          // hash(maximum+1); where maximum is the largest element in the array  
    for(int i=0;i<n;i++){
        hash[arr[i]]+=1;
    }
    for(int i=0;i<=n;i++){
        if(hash[i]==1){
            cout<<i<<endl;
        }
    }
}

//Now in some cases we cannot use hashing like if we have very large elements in the array lets say 10^12
//in those cases we should use map with a data type like long long. ex: map<long long, int> ...here
// long long is the key and int will store how many times it appears.
//time comp=O(n)+O(n/2+1)...one for filling map and other for iterating map.(n/2)+1 because every element 
//appears 2 times so there will be n/2 keys in map and +1 for the single element.
//space comp=O(n)...as we are using space for the map
void number_only_once_map(vector<int> arr,int n){
    map<int,int> mpp;
    for(int i=0;i<n;i++){
        mpp[arr[i]]+=1;
    }
    for(auto it:mpp){
        if(it.second==1){
            cout<<"Number only once by map: ";
            cout<<it.first<<endl;
        }
    }
}
//This is the simplest soln as if we do XOR of all the elements ans as all the elements appear twice ..their
// XOR will be 0 and the only elements that appears once(let it be x) will be like x^0= x.
//time comp=O(n)
// space comp=O(1)
int number_only_once_XOR(vector<int> arr,int n){
    int xor1=0;
    for(int i=0;i<n;i++){
        xor1=xor1^arr[i];
    }
    return xor1;
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
    number_only_once_hash(arr,n);
    number_only_once_map(arr,n);
    int x=number_only_once_XOR(arr,n);
    cout<<"Answer by XOR:"<<x<<endl;
}