class Solution {
  public:
    int longestKSubstr(string &s, int k) {
        // code here
        int n=s.length();
        unordered_map<char,int> mp;
        int i=0,j=0;
        int longest=-1;
        while(j<n){
            mp[s[j]]++;
            
            
            if(mp.size()<k){
                j++;
            }
            else if(mp.size()==k){
               
                longest=max(longest,j-i+1);
                j++;
            }
            else if(mp.size()>k){
                while(mp.size()>k){
                    mp[s[i]]--;
                    if(mp[s[i]]==0) mp.erase(s[i]);
                    i++;
                }
                j++;
            }
            
        }
        return longest;
    }
};
