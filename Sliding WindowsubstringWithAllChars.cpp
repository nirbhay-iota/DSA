// Given a string s consisting only of characters a, b and c.

// Return the number of substrings containing at least one occurrence of all these characters a, b and c.



class Solution {
public:
    int numberOfSubstrings(string s) {
        unordered_map<char,int> mp;
        int i=0,j=0;
        int n=s.length();
        int count=0;
        while(j<n){
            mp[s[j]]++;
            while (mp['a'] > 0 && mp['b'] > 0 && mp['c'] > 0) {
                count += (n - j);
                mp[s[i]]--;
                i++;
            }

            j++;
        }
        return count;
    }
};
