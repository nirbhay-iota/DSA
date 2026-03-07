
class Solution {
  public:
    string isKSortedArray(int arr[], int n, int k) {
        // code here.
        
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        for(int i=0;i<n;i++){
            pq.push({arr[i],i});
        }
        bool check =true;
        for(int i=0;i<n;i++){
            if(abs(i-pq.top().second) > k){
                check=false;
                break;
            }
            pq.pop();
        }
        if(check==false) return "No";
        return "Yes";
    }
};
