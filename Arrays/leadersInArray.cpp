//Question: Leader of an array means array of elements who have only smaller elements on the right side.
#include <iostream>
using namespace std;
//time=O(n^2)
//space=O(n)--> we have not used space to solve the question but to show the output/answer
void leaders_in_array_brute(vector<int> nums){
    int n=nums.size();
    vector<int> ans;
    for(int i=0;i<n;i++){
        int flag=1;
        for(int j=i+1;j<n;j++){
            if(nums[j]>nums[i]) flag=0;
        }
        if(flag==1){
            ans.push_back(nums[i]);
        }
    }
    cout<<"Leader array using brute approach: "<<endl;
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }
    cout<<endl;
}
//time=O(n)
//spaceO(n)
void leaders_in_array_optimal(vector<int> nums){
    int n=nums.size();
    vector<int> ans;
    int max=INT_MIN;
    for(int i=n-1;i>=0;i--){
        if(nums[i]>max){
            ans.push_back(nums[i]);
            max=nums[i];
        }
    }
    cout<<"Leader array using optimal approach: "<<endl;
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }
    cout<<endl;
}
int main(){
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    leaders_in_array_brute(arr);
    leaders_in_array_optimal(arr);
}