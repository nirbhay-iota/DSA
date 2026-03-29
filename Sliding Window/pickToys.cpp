class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        unordered_map<int,int> mp;
        int n=fruits.size();
        int i=0,j=0;
        int maximum=0;
        if(n==1) return 1;
        else if(n==2) return 2;
        while(j<n){
            mp[fruits[j]]++;
            if(mp.size()<=2){
                maximum=max(maximum,j-i+1);
                j++;
            }
            else if(mp.size()>2){
                while(mp.size()>2){
                    mp[fruits[i]]--;
                    if(mp[fruits[i]]==0) mp.erase(fruits[i]);
                    i++;
                }
                j++;
            }
        }
        return maximum;
    }
};
