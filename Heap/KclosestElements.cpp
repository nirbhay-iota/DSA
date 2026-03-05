class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        vector<int> ans(k);
        priority_queue<pair<int,int>> pq;
        int n=arr.size();
        for(int i=0;i<n;i++){
            
            pq.push({abs(arr[i]-x),arr[i]});
            if(pq.size()>k) pq.pop();

        }
        for(int i=0;i<ans.size();i++){
            ans[i]=pq.top().second;
            pq.pop();
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};
