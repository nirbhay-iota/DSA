class Solution {
public:                                                                                                       long daysReq(vector<int> &weights, long mid){
    int days = 1;
        int load = 0;

        for (int w : weights) {
            if (load + w > mid) {
                days++;
                load = 0;
            }
            load += w;
        }
        return days;
    }    
   int shipWithinDays(vector<int>& weights, int d){
    long low=*max_element(weights.begin(),weights.end());
    long high=accumulate(weights.begin(),weights.end(),0);
    long ans=-1;
    while(low<=high){
        long mid=low+(high-low)/2;
        long count=daysReq(weights,mid);
        if(count<=d){
            high=mid-1;
            ans=mid;
        }
        else low=mid+1;
    }
    return ans;
    }
}; 

