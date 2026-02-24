class Solution {
public:
    int MAH(vector<int> heights){
        int n=heights.size();
        vector<int> right(n);
        vector<int> left(n);
        stack<pair<int,int>> st1;

        //for nearest smaller right
        for(int i=n-1;i>=0;i--){
            if(st1.empty()) right[i]=(heights.size());
            else if(!st1.empty() && st1.top().first<heights[i]) right[i]=(st1.top().second);
            else if(!st1.empty() && st1.top().first>=heights[i]){
                while(!st1.empty() && st1.top().first>=heights[i]) st1.pop();
                if(st1.empty()) right[i]=(heights.size());
                else right[i]=(st1.top().second);
            }
            st1.push({heights[i],i});
        }
        // empty the stack
        while(!st1.empty()){
            st1.pop();
        }
        //for nearest smaller left
        for(int i=0;i<n;i++){
            if(st1.empty()) left[i]=(-1);
            else if(!st1.empty() && st1.top().first<heights[i]) left[i]=(st1.top().second);
            else if(!st1.empty() && st1.top().first>=heights[i]){
                while(!st1.empty() && st1.top().first>=heights[i]) st1.pop();
                if(st1.empty()) left[i]=(-1);
                else left[i]=(st1.top().second);
            }
            st1.push({heights[i],i});
        }
        int longest=0;
        int area=0;
        for(int i=0;i<heights.size();i++){
            left[i]=right[i]-left[i]-1;
            if(heights[i]<=left[i]){

                area=heights[i]*heights[i];
            }
            else{
                area=left[i]*left[i];
            }
            longest=max(longest,area);
        }
        return longest;
    }
    int maximalSquare(vector<vector<char>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();
        vector<int> histo(m,0);
        int area=0;
        int largest=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(matrix[i][j]=='1'){
                    histo[j]+=1;
                }
                else{
                    histo[j]=0;
                }
            }
            area=MAH(histo);
            largest=max(largest,area);
        }
        return largest;
    }
};
