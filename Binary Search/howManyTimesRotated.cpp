#include<iostream>
#include<vector>
using namespace std;
void how_many_times_rotated(vector<int> nums){
    int ans=INT_MAX,min_index=-1;
    int low=0,high=nums.size()-1;
    while(low<=high){
        int mid=low+(high-low)/2;
        if(low!=nums.size()-1 && nums[low]<=nums[mid]){
            if(nums[low]<ans) {ans=nums[low]; min_index=low;}
            low=mid+1;
        }
        else{
            if(nums[mid]<ans) {ans=nums[mid]; min_index=mid;}
            high=mid-1;
        }
    }
    cout<<"The number of times the array has been rotated is:"<<min_index<<endl;
}
int main(){
    int n; cin>>n;
    vector<int> nums(n);
    for(int i=0;i<n;i++){
        cin>>nums[i];
    }
    cout<<"Input Array:"<<endl;
    for(int i=0;i<n;i++){
        cout<<nums[i]<<" ";
    }
    cout<<endl;
    
    how_many_times_rotated(nums);
}