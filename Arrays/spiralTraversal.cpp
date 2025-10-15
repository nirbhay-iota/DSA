//Question: Given a matrix...print the elements in spiral order
#include<iostream>
using namespace std;

//time=O(n*m)
//space=O(n*m)-->Since the space required will be equal to number of elements.-->also this is only used for displaying the answer and not solve the question
void spiral_traversal_only(vector<vector<int>> nums){
    int n=nums.size();
    int m=nums[0].size();
    int top=0,left=0,right=m-1,bottom=n-1;
    vector<int> ans;
    while(top<=bottom && left<=right){
        for(int i=left;i<=right;i++){
            ans.push_back(nums[top][i]);
        }
        top++;
        for(int i=top;i<=bottom;i++){
            ans.push_back(nums[i][right]);
        }
        right--;
        if(top<=bottom){
            for(int i=right;i>=left;i--){
                ans.push_back(nums[bottom][i]);
            }
            bottom--;
        }
        if(left<=right){
            for(int i=bottom;i>=top;i--){
                ans.push_back(nums[i][left]);
            }
            left++;
        }
    }
    cout<<endl<<"Output array using only approach possible:"<<endl;
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }
    cout<<endl;
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
    spiral_traversal_only(nums);
}