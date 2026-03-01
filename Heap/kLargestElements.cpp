class Solution {
  public:
    vector<int> kLargest(vector<int>& arr, int k) {
        // Your code here
        vector<int> ans;
        priority_queue<int> maxheap;
        int n=arr.size();
        for(int i=0;i<n;i++){
            maxheap.push(arr[i]);
        }
        while(k>0){
            ans.push_back(maxheap.top());
            maxheap.pop();
            k--;
        }
        return ans;
        
    }
};
