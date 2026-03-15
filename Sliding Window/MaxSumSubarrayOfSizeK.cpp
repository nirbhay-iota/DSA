class Solution {
  public:
    int maxSubarraySum(vector<int>& arr, int k) {
        // code here
        int n=arr.size();
        int maximum=0;
        int i=0,j=0;
        int sum=0;
        while(j<n){
            sum+=arr[j];
            if(j-i+1 < k){
                j++;
            } 
            else if(j-i+1 == k){
                maximum=max(sum,maximum);
                sum-=arr[i];
                j++;
                i++;
            }
            
            
        }
        return maximum;
    }
};
