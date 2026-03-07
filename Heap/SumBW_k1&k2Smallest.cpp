class Solution {
  public:
    long long sumBetweenTwoKth(long long A[], long long N, long long K1, long long K2) {
        // Your code goes here
        long long ans=0;
        priority_queue<long long> pq;
        for(int i=0;i<N;i++){
            pq.push(A[i]);
            if(pq.size()>K2) pq.pop();
        }
        pq.pop();
        while(pq.size()>K1){
            ans+=pq.top();
            pq.pop();
        }
        return ans;
    }
};
