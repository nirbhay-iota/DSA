class Solution {
  public:
    vector<int> nextSmallerEle(vector<int>& arr) {
        
        stack<int> st;
        vector<int > ans;
        for(int i=arr.size()-1;i>=0;i--){
            if(st.empty())  ans.push_back(-1);
            else if(st.size()>0 && st.top()<arr[i]){
                ans.push_back(st.top());
            }
            else if(st.size()>0 && st.top()>=arr[i]){
                while(st.size()>0 && st.top()>=arr[i]){
                    st.pop();
                }
                if(st.empty()) ans.push_back(-1);
                else ans.push_back(st.top());
            }
            st.push(arr[i]);
        }
        reverse(ans.begin(),ans.end());
        return ans;
    
    
    }
};
