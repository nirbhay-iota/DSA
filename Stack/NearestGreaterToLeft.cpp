#include<iostream>
#include<vector>

using namespace std;
int main(){
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    cout << "Input Array" << endl;
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    stack<int> st;
    vector<int > ans;
    for(int i=0;i<n;i++){
        if(st.empty())  ans.push_back(-1);
        else if(st.size()>0 && st.top()>arr[i]){
            ans.push_back(st.top());
        }
        else if(st.size()>0 && st.top()<=arr[i]){
            while(st.size()>0 && st.top()<=arr[i]){
                st.pop();
            }
            if(st.empty()) ans.push_back(-1);
            else ans.push_back(st.top());
        }
        st.push(arr[i]);
    }

    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }
    cout<<endl;
}
