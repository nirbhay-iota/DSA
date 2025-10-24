// Question: Given an integer array nums, return all the triplets [nums[i], nums[j], nums[k]] 
// such that i != j, i != k, and j != k, and nums[i] + nums[j] + nums[k] == 0.
#include<iostream>
#include<map>
#include<algorithm>
#include<set>
using namespace std;
//time comp=O(n^3)
//space comp=O((no.of unique triplets)*2)...no.of unique triplets stored in set will take space and same *2 for the ans
void three_sum_brute(vector<int> nums){
    vector<vector<int>> ans;
    set <vector<int>> st;
    for(int i=0;i<nums.size();i++){
        for(int j=i+1;j<nums.size();j++){
            for(int k=j+1;k<nums.size();k++){
                if(nums[i]+nums[j]+nums[k]==0){
                    vector<int> temp={nums[i],nums[j],nums[k]};
                    sort(temp.begin(),temp.end());
                    st.insert(temp);
                }
            }
        }
    }
    for(auto &it:st){       //& is used so it does not make a copy which will save memory
        ans.push_back(it);
    }
    cout<<"Available triplets using brute approach:"<<endl;
    for(auto &it:ans){
        cout<<"[ ";
        for(int x: it){
            cout<<x<<" ";
        }
        cout<<"]"<<endl;
    }
}

// Now we have to reduce. time comp from n^3 to n^2 so we have to reduce one loop and we can do it by 
// help of a hashset
//time comp=O(n^2log(M))..log(M) for finding in set everytime
//space comp=O(n)+O(no.of unique elements*2)
void three_sum_better(vector<int> nums){
    vector<vector<int>> ans;
    set<vector<int>> st;
    for(int i=0;i<nums.size();i++){
        set<int> hashset;               // hashset becomes empty after completion of j loop
        for(int j=i+1;j<nums.size();j++){
            int number=(0-(nums[i]+nums[j]));
            if(hashset.find(number)!= hashset.end()){
                vector<int> temp={nums[i],nums[j],number};
                    sort(temp.begin(),temp.end());
                    st.insert(temp);
            }

            hashset.insert(nums[j]);
            
        }
    }
    for(auto &it:st){       //& is used so it does not make a copy which will save memory
        ans.push_back(it);
    }
    cout<<"Available triplets using better approach:"<<endl;
    for(auto &it:ans){
        cout<<"[ ";
        for(int x: it){
            cout<<x<<" ";
        }
        cout<<"]"<<endl;
    }

}

//time comp=O(nlogn)+O(n^2)...nlogn for sorting and n^2 for while loop inside for loop
//space comp=O(no.of unique elements)...we didi not use ant other data structure like we used a set in the previous approaches
void three_sum_optimal(vector<int> nums){
    vector<vector<int>> ans;
    sort(nums.begin(),nums.end());
    for(int i=0;i<nums.size();i++){
        if(i>0 && nums[i]==nums[i-1])  continue;
        int j=i+1;
        int k=nums.size()-1;
        while(j<k){
            int sum=nums[i]+nums[j]+nums[k];
            if(sum<0){
                j++;
            }
            else if(sum>0){
                k--;
            }
            else{
                vector<int> temp={nums[i],nums[j],nums[k]};
                ans.push_back(temp);
                j++;
                k--;
                while(j<k && nums[j]==nums[j-1]) j++;
                while(j<k && nums[k]==nums[k+1]) k--;
            }
        }
    }

    cout<<"Available triplets using optimal approach:"<<endl;
    for(auto &it:ans){
        cout<<"[ ";
        for(int x: it){
            cout<<x<<" ";
        }
        cout<<"]"<<endl;
    }
}
int main(){
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    cout<<"Input Array:"<<endl;
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    three_sum_brute(arr);
    three_sum_better(arr);
    three_sum_optimal(arr);
}
