class Solution {
public:
    long sumOfNums(vector<int>& nums,int divisor){
        long sum=0;
        for(int i=0;i<nums.size();i++){
            sum+=(nums[i]+divisor-1)/divisor;
        }
        return sum;
    }
    int smallestDivisor(vector<int>& nums, int threshold) {
        int ans=-1;
        int low=1;
        int high=*max_element(nums.begin(),nums.end());
        while(low<=high){
            long mid=low+(high-low)/2;
            long value=sumOfNums(nums,mid);
            if(value<=threshold){
                ans=mid;
                high=mid-1;
            }
            else low=mid+1;
        }
        return ans;
    }
};
