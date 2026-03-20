class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> ans;
        int n=nums.size();
        int i=0,j=0;
        deque<int> dq;
        while(j<n){
            if(!dq.empty() && nums[j]>dq.back()){
                while(!dq.empty() && nums[j]>dq.back()) dq.pop_back();
                dq.push_back(nums[j]);
            }
            else dq.push_back(nums[j]);

            if(j-i+1 < k) j++;

            else{
                ans.push_back(dq.front());
                if(nums[i]==dq.front()){
                    dq.pop_front();
                }
                i++;
                j++;
            }
        }
        return ans;
    }
};
