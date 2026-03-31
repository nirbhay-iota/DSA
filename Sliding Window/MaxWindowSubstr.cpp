// Optimal soln

class Solution {
public:
    string minWindow(string s, string t) {
        int m=s.length();
        int n=t.length();
        int shortest=INT_MAX;
        int start=0;
        unordered_map<char,int> mp;
        int i=0,j=0;
        while(j<n){
            mp[t[j]]++;
            j++;
        }
        j=0;
        int count=mp.size();
        while(j<m){
            if(mp.find(s[j]) != mp.end()){
                mp[s[j]]--;
                if(mp[s[j]]==0) count--;
            }

            while(count==0){
                if(j - i + 1 < shortest){
                    shortest = j - i + 1;
                    start = i;
                }
                if(mp.find(s[i]) != mp.end()){
                    mp[s[i]]++;
                    if(mp[s[i]]>0) count++;
                }
                i++;
            }
            j++;

            
        }
        if (shortest == INT_MAX) return "";
        return s.substr(start, shortest);
    }
};


// slightly complex but similar approach

class Solution {
public:
    string minWindow(string s, string t) {
        int m=s.length();
        int n=t.length();
        int shortest=INT_MAX;
        int start=0;
        unordered_map<char,int> mp;
        int i=0,j=0;
        while(j<n){
            mp[t[j]]++;
            j++;
        }
        j=0;
        while(j<m){
            if(mp.find(s[j])!=mp.end()){
                mp[s[j]]--;
            }
            bool check = true;
            for(auto &p : mp){
                if(p.second > 0) check=false;
            }
            while(check==true){
                if(j - i + 1 < shortest){
                    shortest = j - i + 1;
                    start = i;
                }
                if(mp.find(s[i]) != mp.end()) mp[s[i]]++;
                i++;
                check = true;
            for(auto &p : mp){
                if(p.second > 0) check=false;
            }
            }
            
            j++;
            
        }
        if (shortest == INT_MAX) return "";
        return s.substr(start, shortest);
    }
};
