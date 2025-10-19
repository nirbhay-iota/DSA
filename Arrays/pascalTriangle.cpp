//Question: 3 types of questions
//1> given row and column number...return the element
//2> given row number...return the full row
//3> given value of no.of rows...print the whole pascal's triangle
#include<iostream>
#include<vector>
using namespace std;

//---> Solution for 1
// It is predermined that the value at row n and column r will be equal to nCr(n-1,r-1)
// time=O(r)-->since we ran the for loop just r times
//space=(1)
int nCr(int n,int r){
    long long result=1;
    // for(int i=0;i<r;i++){
    //     result=result*(n);       //this works same as below
    //     result=result/(r);
    //     n--;r--;
    // }
    for(int i=0;i<r;i++){
        result=result*(n-i);        //by this approach we can eradicate unnecessary multiplications...simplest way to calculate nCr
                                    //as n is multiplied as many times as the value of r in nCr
        result=result/(i+1);
    }
    return result;
}

// Solution for 2
//time=O(n*r)--> for loop runs n times and inside it nCr for loop r times every iteration
//space=O(1)...vector used to just give the output
void full_row_brute(int n){
    //we will use the nCr fn to find the values at each column
    // If row number is n we would have n elements
    vector<int> ans;
    for(int i=0;i<n;i++){
        ans.push_back(nCr(n-1,i));
    }
    cout<<"Answer by brute approach:"<<endl;
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }
    cout<<endl;
}
void full_row_better(int n){
    vector<int> ans;
    int element=1;
    ans.push_back(element);
    for(int i=1;i<n;i++){
        element=element*(n-i);
        element=element/(i);
        ans.push_back(element);
    }
    cout<<"Answer by better approach:"<<endl;
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }
    cout<<endl;
}
int main(){
    cout<<"enter value of n and r:"<<endl;
    int n,r;
    cin>>n;
    cin>>r;

    cout<<"Solution 1 for given n and r:"<<endl;
    int x=nCr(n-1,r-1);
    cout<<x<<endl;
    cout<<"Solution 2 for given n:"<<endl;
    full_row_brute(n);
    full_row_better(n);
}