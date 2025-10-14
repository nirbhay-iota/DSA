// Question:rotate matrix by 90 degrees
#include<iostream>
using namespace std;

//time=O(n^2)
//space=O(n^2)
void rotate_by_90_brute(vector<vector<int>> nums){
    int n=nums.size();
    int m=nums[0].size();
    vector<vector<int>> temp(n,vector<int>(m));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            temp[j][m-i-1]=nums[i][j];
        }
    }
    cout<<"Answer array using brute approach:"<<endl;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cout<<temp[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
}

void rotate_by_90_better(vector<vector<int>> nums){
    int n=nums.size();
    int m=nums[0].size();
    //we will take transpose first: Intuition made when we saw that the first column became first row
    //and the second column become second row in the reversed order
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(i!=j){
                swap(nums[i][j],nums[j][i]);
            }
        }
    }
    
}
int main(){
cout<<"Enter number of rows and columns: ";
    int n,m;
    cin>>n>>m;
    vector<vector<int>> nums(n,vector<int>(m));  //Create a vector arr of size n,
                                                //and each element of it is initialized with a vector<int> of size m.
    for(int i=0;i<n;i++){
        cout<<"Input elements in row "<<i+1<<":"<<endl;
        for(int j=0;j<m;j++){
            cin>>nums[i][j];
        }
    }
    cout<<endl<<"Input array"<<endl;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
           cout<<nums[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
    rotate_by_90_brute(nums);
}