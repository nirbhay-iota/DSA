#include<iostream>
#include<vector>
using namespace std;
void single_element(vector<int> nums){
    if(nums.size()==1) {
        cout<<"The single element is: "<<nums[0]<<endl;
        return;
    }
    if(nums[0]!=nums[1]){
        cout<<"The single element is: "<<nums[0]<<endl;
        return;
    }
    if(nums[nums.size()-1]!=nums[nums.size()-2]){
        cout<<"The single element is:"<<nums[nums.size()-1]<<endl;
        return;
    }
    int low=1,high=nums.size()-2;
    while(low<=high){
        int mid=low+(high-low)/2;
        if(nums[mid]!=nums[mid-1] && nums[mid]!=nums[mid+1]){
            cout<<"The single element is:"<<nums[mid]<<endl;
        return;
        }
        if((mid%2!=0 && nums[mid]==nums[mid-1]) || (mid%2==0 && nums[mid]==nums[mid+1])){
            high=mid-1;
        }
        else{
            low=mid+1;
        }
    }

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
    
    single_element(nums);
}
