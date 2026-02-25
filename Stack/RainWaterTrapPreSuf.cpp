class Solution {
public:
    int trap(vector<int>& height) {
        /*
        Logic last loop me :-
        => dekh logic ye h ki hm ek point se dusre point pe hoop kar rhe aur hm ab tk jo largest
        height mila h usse naap rhe h ki paani store hoga ki nhi jiske liye hm prefix use kar rhe hn
        Ab har point se future me two possible cases h :-
        1. agar hm ek point pe hn toh aage hmko usse jyda milega
        2. yaa nhi milega iske liye hm suffix use kar rhe
        */
        vector<int> prefix(height.size(),0);
        vector<int> suffix(height.size(),0);
        int ans=0;
        int largest=0;
        for(int i=0;i<height.size();i++){
            largest=max(largest,height[i]);
            prefix[i]=largest;
        }
        largest=0;
        for(int i=height.size()-1;i>=0;i--){
            largest=max(largest,height[i]);
            suffix[i]=largest;
        }
        for(int i=0;i<height.size();i++){

            ans+=min(prefix[i],suffix[i])-height[i]; 

        }
        return ans;
    }
};
