class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n=heights.size();
        vector<int> right(n);
        vector<int> left(n);
        stack<pair<int,int>> st1;
        stack<pair<int,int>> st2;

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
        
        //for nearest smaller left
        for(int i=0;i<n;i++){
            if(st2.empty()) left[i]=(-1);
            else if(!st2.empty() && st2.top().first<heights[i]) left[i]=(st2.top().second);
            else if(!st2.empty() && st2.top().first>=heights[i]){
                while(!st2.empty() && st2.top().first>=heights[i]) st2.pop();
                if(st2.empty()) left[i]=(-1);
                else left[i]=(st2.top().second);
            }
            st2.push({heights[i],i});
        }
        int longest=0;
        for(int i=0;i<heights.size();i++){
            left[i]=right[i]-left[i]-1;
            int area=heights[i]*left[i];
            if(longest<area)
            longest=area;
        }
        return longest;
    }
};
