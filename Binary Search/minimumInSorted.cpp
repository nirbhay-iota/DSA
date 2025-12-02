//Question: Find the minimum element in a roated sorted array
#include<iostream>
#include<vector>
using namespace std;
void minimum_in_rotated_array(vector<int> nums){
    int ans=INT_MAX;
    int low=0,high=nums.size()-1;
    while(low<=high){
        int mid=low+(high-low)/2;
        if(nums[low]<=nums[mid]){
            if(low<ans) ans=low;
            low=mid+1;
        }
        else{
            if(mid<ans) ans=mid;
            high=mid-1;
        }
    }
    cout<<"The minimum element in the array is:"<<ans<<endl;
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
    
    minimum_in_rotated_array(nums);
}