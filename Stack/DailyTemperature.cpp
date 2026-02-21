class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int> ans(temperatures.size(),0);
        stack<int> st;
        for(int i=temperatures.size()-1;i>=0;i--){
            if(st.empty()) ans[i]=0;
            else if(!st.empty() && temperatures[st.top()]>temperatures[i]){
                ans[i]=st.top()-i;
            }
            else if(!st.empty() && temperatures[st.top()]<=temperatures[i]){
                while(!st.empty() && temperatures[st.top()]<=temperatures[i]) st.pop();
                if(st.empty()) ans[i]=0;
                else ans[i]=st.top()-i;
            }
            st.push(i);
        }
        
        return ans;
    }
};
