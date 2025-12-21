class Solution {
public:
    bool possible(vector<int> &bloomDay,long days,int m,int k){
        long cnt=0;
        int noOfBouq=0;
        for(int i=0;i<bloomDay.size();i++){
            if(bloomDay[i]<=days){
                cnt++;
            }
            else{
                noOfBouq+=cnt/k;
                cnt=0;
            }
            
        }
        noOfBouq+=cnt/k;
        if(noOfBouq>=m) return true;
        else return false;
    }
    int minDays(vector<int>& bloomDay, int m, int k) {
        if(bloomDay.size() < (long long)m*k){
            return -1;
        }
        int ans=-1;
        long low=*min_element(bloomDay.begin(),bloomDay.end());
        long high=*max_element(bloomDay.begin(),bloomDay.end());
        while(low<=high){
            long mid=low+(high-low)/2;
            if(possible(bloomDay,mid,m,k)){
                ans=mid;
                high=mid-1;
            }
            else low=mid+1;
        }
        return ans;
    }
};
