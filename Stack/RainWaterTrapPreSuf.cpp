class Solution {
public:
    int trap(vector<int>& height) {
        vector<int> prefix(height.size(),0);
        vector<int> suffix(height.size(),0);
        int ans=0;
        int largest=0;
        for(int i=0;i<height.size();i++){
            largest=max(largest,height[i]);
            prefix[i]=largest;
        }
        largest=0;
        for(int i=height.size()-1;i>=0;i--){
            largest=max(largest,height[i]);
            suffix[i]=largest;
        }
        for(int i=0;i<height.size();i++){

            ans+=min(prefix[i],suffix[i])-height[i]; 

        }
        return ans;
    }
};
