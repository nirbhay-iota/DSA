// Question: Given a 2D array of only 0's and 1's ..we have to make the colums and rows containing 0's to all 0's
#include<iostream>
using namespace std;

void zeroRow(vector<vector<int>> &nums,int i,int m){
    for(int j=0;j<m;j++){
        if(nums[i][j]==1){
            nums[i][j]=-1;
        }
    }
}
void zeroCol(vector<vector<int>> &nums,int j,int n){
    for(int i=0;i<n;i++){
        if(nums[i][j]==1){
            nums[i][j]=-1;
        }
    }
}

//time=O(n*m*(n+m))-->=O(n^3)
//space=O(1)
void set_matrix_zero_brute(vector<vector<int>> nums,int n,int m){
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(nums[i][j]==0){
                zeroRow(nums,i,m);
                zeroCol(nums,j,n);
            }
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(nums[i][j]==-1){
                nums[i][j]= 0;
            }
        }
    }
    cout<<"Answer array using brute approach:"<<endl;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cout<<nums[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;

}

void set_matrix_zero_better(vector<vector<int>> nums,int n,int m){
    vector<int> row(n,0);
    vector<int> col(m,0);
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(nums[i][j]==0){
                row[i]=1;
                col[j]=1;
            }
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(row[i]==1 || col[j]==1){
                nums[i][j]=0;
            }
        }
    }
    cout<<"Answer array using better approach:"<<endl;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cout<<nums[i][j]<<" ";
        }
        cout<<endl;
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
    set_matrix_zero_brute(nums,n,m);
    set_matrix_zero_better(nums,n,m);

}