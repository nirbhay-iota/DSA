// Question: Same as rotated array 1 but here duplicates can be present we just have to tell if the 
// target is present in the array or not ....not its index.

// Due to presence of duplicates...we will encouter the possibility of nums[low]=nums[mid]=nums[high]
// due to this we will not be able to divide the half which was sorted...so we will have to check for 
// this thing and then we have to eliminate those elements.
#include<iostream>
#include<vector>
using namespace std;
void index_of_target(vector<int> nums,int target){
    int low=0,high=nums.size()-1;
    int ans=-1;
    while (high>=low){
        int mid=low+(high-low)/2;
        if(nums[mid]==nums[high] && nums[mid]==nums[low]){
            high--;
            low++;
            continue;
        }
        if(nums[mid]==target){
            cout<<"The index of target is:"<<mid<<endl;
            return;
        }
        //either of the sides of mid will be sorted
        // (If left sorted)
        if(nums[low]<=nums[mid]){
            if(target<=nums[mid] && target>=nums[low]){
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        //(If right sorted)
        else{
            if(target>=nums[mid] && nums[high]>=target){
                low=mid+1;
            }
            else{
                high=mid-1;
            }
        }
        ans=mid;
    }
    cout<<"The index of target is:"<<ans<<endl;
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
    index_of_target(nums,target);
}