//Question: we are given an array of positives and negatives and the number of positives and negatives 
//is not given (means positives can be more or vice versa) and we have to rearrange
//them in a way that they are like one positive then negative then positive and so on.
#include<iostream>
using namespace std;
//time=O(2n)
//space=O(n)
void rearrange_by_sign2(vector<int> nums){
    int n=nums.size();
    vector<int> pos;
    vector<int> neg;
    for(int i=0;i<n;i++){
        if(nums[i]<0){
            neg.push_back(nums[i]);
        }
        else
        pos.push_back(nums[i]);
    }
    if(pos.size()>neg.size()){
        for(int i=0;i<neg.size();i++){
            nums[2*i]=pos[i];
            nums[2*i+1]=neg[i];
        }
        int index=neg.size()*2;
        for(int i=neg.size();i<pos.size();i++){
            nums[index]=pos[i];
            index++;
        }
    }
    else if(pos.size()<neg.size()){
    for(int i=0;i<pos.size();i++){
            nums[2*i]=pos[i];
            nums[2*i+1]=neg[i];
        }
        int index=pos.size()*2;
        for(int i=pos.size();i<neg.size();i++){
            nums[index]=neg[i];
            index++;
        }
    }
    else{
        for(int i=0;i<n/2;i++){
        nums[2*i]=pos[i];
        nums[2*i+1]=neg[i];
    }
    }

    cout<<"Rearranged array using brute approach:"<<endl;
    for(int i=0;i<n;i++){
        cout<<nums[i]<<" ";
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
    cout<<"Input Array:"<<endl;
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    rearrange_by_sign2(arr);
}