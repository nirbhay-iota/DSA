class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n=nums.size();
        int high=n-1,low=0;
        while(high>=low){
            int mid=low+(high-low)/2;
            if(nums[mid]==target) return mid;
            if(nums[mid]>target) {
                high=mid-1;
            }
            else
                low=mid+1;
        }
        return -1;
        
    }
};
