class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        int n=points.size();
        int m=points[0].size();
        vector<vector<int>> ans;
        unordered_map<int,int> mp;
        for(int i=0;i<n;i++){
            mp[i]=(points[i][0]*points[i][0])+(points[i][1]*points[i][1]);
        }
        priority_queue<pair<int,int>> pq;
        for(auto it: mp){
            pq.push({it.second,it.first});
            if(pq.size()>k) pq.pop();
        }
        for(int i=0;i<k;i++){
            ans.push_back(points[pq.top().second]);
            pq.pop();
        }
        return ans;
    }
};
