class Solution {
  public:
    int minCost(vector<int>& arr) {
        // code here
        if(arr.size()==1) return 0;
        int n=arr.size();
        priority_queue<int,vector<int>,greater<int>> pq;
        for(int i=0;i<n;i++){
            pq.push(arr[i]);
        }
        int cost=0;
        for(int i=0;i<n-1;i++){
            int temp=0;
            temp+=pq.top();
            pq.pop();
            temp+=pq.top();
            pq.pop();
            pq.push(temp);
            cost+=temp;
        }
        return cost;
        
    }
};
