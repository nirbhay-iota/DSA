class Solution {
public:
    long long total_hours(vector<int> &piles,long mid){
        long long totalHours=0;
        for(int i=0;i<piles.size();i++){
            totalHours+= (piles[i] + mid - 1) / mid;
        }
        return totalHours;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int n=*max_element(piles.begin(),piles.end());
        long low=1,high=n;
        long ans=-1;
        while(high>=low){
            long mid=low+(high-low)/2;
            long reqTime=total_hours(piles,mid);
            if(reqTime<=h){
                high=mid-1;
                ans=mid;
            }
            else low=mid+1;

        }
        return ans;
    }
};
