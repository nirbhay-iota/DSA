// With Negatives
class Solution {
  public:
    int longestSubarray(vector<int>& arr, int k) {
        // code here
        int n=arr.size();
        unordered_map<long long,int> mp;
        int longest=0;
        long long sum=0;
        for(int i=0;i<n;i++){
            sum+=arr[i];
            
            if(sum==k) longest=i+1;
            
            long long remaining=sum-k;
            if(mp.find(remaining) != mp.end()){
                int len= i-mp[remaining];
                longest=max(longest,len);
            }
            
            if(mp.find(sum)==mp.end()){
                mp[sum]=i;
            }
        }
        return longest;
    }
};

// Without Negatives 
int longest_subarray_optimal(vector<int> arr,int n,long long k){
    int j=0,sum=0,longest=0;
    for(int i=0;i<n;i++){
        sum+=arr[i];
        while(j<=i && sum>k){
            sum=sum-arr[j];
            j++;
        }
        if(sum==k){
            int length=i-j+1;
            longest=max(longest,length);
        }
    }
    return longest;
}
