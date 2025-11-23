#include<iostream>
using namespace std;

void floor(vector<int> nums,int target){
    int low=0,high=nums.size()-1;
    int ans;
    while(high>=low){
        int mid= low+(high-low)/2;
        if(nums[mid]==target) cout<<"Element found on index: "<<mid<<endl;
        if(nums[mid]>target){
            high=mid-1;
        }
        else{
            low=mid+1;
            ans=nums[mid];
        }
    }
    cout<<"The floor of "<<target<<" is: "<<ans<<endl;
}
void ceil(vector<int> nums,int target){
    int low=0,high=nums.size()-1;
    int ans;
    while(high>=low){
        int mid= low+(high-low)/2;
        if(nums[mid]==target) cout<<"Element found on index: "<<mid<<endl;
        if(nums[mid]>target){
            high=mid-1;
            ans=nums[mid];
        }
        else{
            low=mid+1;
        }
    }
    cout<<"The ceil of "<<target<<" is: "<<ans<<endl;
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
    int target;
    cout<<"Enter Target"<<endl;
    cin>>target;
    floor(nums,target);
    ceil(nums,target);
}