class Solution {
  public:
    int celebrity(vector<vector<int>>& mat) {
        int n=mat.size();
        int m=mat[0].size();
        vector<int> height(m,0);
        int index=-1;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(mat[i][j]==1){
                    height[j]+=1;
                }
                else height[j]=0;
            }
        }
        for(int i=0;i<height.size();i++){
            if(height[i]==m){
                index=i;
            }
        }
        if(index==-1) return -1;
        for(int i=0;i<m;i++){
            if(i!=index && mat[index][i]==1) return -1;
        }
        return index;
        
    }
};
