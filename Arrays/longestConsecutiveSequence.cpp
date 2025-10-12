#include<iostream>
#include<unordered_set>
using namespace std;
bool linear_search(vector<int> nums,int number){
    for(int i=0;i<nums.size();i++){
        if(nums[i]==number){
            return true;
        }
    }
    return false;
}
//time=O(n^2)
//space=O(1)
void longest_consecutive_sequence_brute(vector<int> nums){
    int n=nums.size();
    int longest=1;
    for(int i=0;i<n;i++){
        int x=nums[i];
        int cnt=1;
        while(linear_search(nums,x+1)==true){
            x=x+1;
            cnt+=1;
            longest=max(longest,cnt);
        }
    }
    cout<<"Answer by Brute Approach: "<<longest<<endl;
}
//time=O(n+nlogn)--> n for for loop and nlogn for sort() function
void longest_consecutive_sequence_better(vector<int> nums){
    int n=nums.size();
    sort(nums.begin(),nums.end());
    int maxlen=1;
    int len=1;
    for(int i=0;i<n-1;i++){
       if(nums[i+1]==nums[i]+1){
        len++;
       }
       else if(nums[i+1]==nums[i]) continue;  //as sorted array will have duplicates and we have to ignore them
       else if(nums[i+1]!=nums[i]+1){
        len=1;
       }
       maxlen=max(len,maxlen);
    }
    cout<<"Answer by Better Approach: "<<maxlen<<endl;

}

// Idea:
// Use an unordered_set to store all unique elements for O(1) average lookup.
// Then, only start counting a sequence from numbers that are the beginning of 
// a sequence (i.e., their previous number doesn’t exist).

//time=O(n+n)--> 1st n for filling the set and 2nd n for iterating over the set and the while inside the
            //   second for loop is only taking O(1) as find on unordered set takes O(1) in average case
//space=O(n)...for unordered set            
void longest_consecutive_sequence_optimal (vector<int> nums){
    int longest=1;
    unordered_set<int> st;
    for(int i=0;i<nums.size();i++){
        st.insert(nums[i]);
    }
    for(auto it : st){
        if(st.find(it-1)==st.end()){       //this if is true if the previous element is not found in the set    
            int x=it;
            int cnt=1;
            while(st.find(x+1)!=st.end()){
                cnt+=1;
                x=x+1;
            }
            longest=max(longest,cnt);
        }
    }
    cout<<"Answer by optimal Approach: "<<longest<<endl;
}

int main(){
    int n;
    cin>>n;
    vector <int> arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    cout<<"Input Array"<<endl;
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    longest_consecutive_sequence_brute(arr);
    longest_consecutive_sequence_better(arr);
    longest_consecutive_sequence_optimal(arr);

}