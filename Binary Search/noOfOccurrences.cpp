#include<iostream>
#include<vector>
using namespace std;

int lowerbound(vector<int> &nums,int target){
    int high=nums.size()-1,low=0;
    int ans=-1;
    while(high>=low){
        int mid=low+(high-low)/2;
        if(nums[mid]>=target){
            ans=mid;
            high=mid-1;
        }
        else{
            low=mid+1;
        }
    }
    return ans;
}
int upperbound(vector<int> &nums,int target){
    int high=nums.size()-1,low=0;
    int ans=-1;
    while(high>=low){
        int mid=low+(high-low)/2;
        if(nums[mid]>target){
            ans=mid;
            high=mid-1;
        }
        else{
            low=mid+1;
        }
    }
    if(ans==-1){
        if(nums.empty()==false && nums.back()==target) return nums.size()-1;
        return -1;
    }
    return ans-1;
}

void no_of_occurrences(vector<int> &nums,int target){
    int first=lowerbound(nums,target),last=upperbound(nums,target);
    if(first==-1){
        cout<<"The total number of occurrences are:"<<0<<endl;
    }
    else{
        cout<<"The total number of occurrences are:"<<last-first+1<<endl;
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
    int target;
    cout<<"Enter Target"<<endl;
    cin>>target;
    no_of_occurrences(nums,target);
}