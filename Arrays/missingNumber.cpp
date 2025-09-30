//The question is that we are given a number N and an array of size N-1...now the array has all the numbers
// except the number N...we have to find what that number is.
//for ex== we are given N=5 so the array may contain arr=[1,2,4,5]... 4 elements and here 3 is missing
//so we have to return the missing number which is 3
#include<iostream>
using namespace std;
//time comp=O(n^2)
//space comp=O(1)
int find_missing_number_brute(vector <int> arr,int n){
    
    for(int i=1;i<=n;i++){
        int cnt=0;
        for(int j=0;j<n-1;j++){
            
            if(i==arr[j]){
            break;
            }
            cnt++;
        }
        if(cnt>=n-1){
            return i;
            break;
        }
    }
    return 0;
}
//We will use the concept of hashing.
//time comp=O(n)+O(n)
//space comp=O(n)...hash array
void find_missing_number_better(vector <int> arr,int n){
    vector<int> hash(n+1,0);
    for(int i=0;i<n;i++){
        hash[arr[i]]+=1;
    }
    for(int i=1;i<=n;i++){
        if(hash[i]==0){
            cout<<"Missing number by hashing: "<<i<<endl;
        }
    }
}
//time comp=O(n)
//space comp=O(1)
void find_missing_number_optimal_sum(vector<int> arr,int n){
     int sum=(n*(n+1))/2;
     int given=0;
     for(int i=0;i<n-1;i++){
        given+=arr[i];
     }
     cout<<"Missing number by optimal solution: "<<sum-given<<endl;
}

void find_missing_number_optimal_XOR(vector<int> arr,int n){
    
}
int main(){
    int n;
    cin>>n;
    vector <int> arr(n-1);
    for(int i=0;i<n-1;i++){
        cin>>arr[i];
    }
    cout<<"Input Array"<<endl;
    for(int i=0;i<n-1;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    int x=find_missing_number_brute(arr,n);
    cout<<"Missing number is by brute approach: "<<x<<endl;
    find_missing_number_better(arr,n);
    find_missing_number_optimal_sum(arr,n);
}