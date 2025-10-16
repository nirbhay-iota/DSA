#include<iostream>
#include<map>
using namespace std;
//time=O(n*n)
//space=O(1)
void no_of_subarrays_with_sum_k_brute(vector<int> nums,int k){
    int n=nums.size();
    int count=0;
    for(int i=0;i<n;i++){
        int sum=0;
        for(int j=i;j<n;j++){
            sum+=nums[j];
            if(sum==k){
                count++;
            }
        }
    }
    cout<<"Answer by brute approach is: "<<count<<endl;
}

//time=O(n*logn)
//space=O(n)
void no_of_subarrays_with_sum_k_optimal(vector<int> nums,int k){
    int n=nums.size();
    map<long long,int> preSumMap;
    int sum=0,count=0;
    preSumMap[0]=1;
    for(int i=0;i<n;i++){
        sum+=nums[i];
        
        int remaining=sum-k;
        if(preSumMap.find(remaining) != preSumMap.end()){
            count=count+preSumMap[remaining];
        }
        
        preSumMap[sum]++;
        
    }
    cout<<"Answer by better approach is: "<<count<<endl;
}
int main()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    cout<<"Enter the value of k"<<endl;
    long long k;
    cin>>k;
    cout << "Input Array" << endl;
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    no_of_subarrays_with_sum_k_brute(arr,k);
    no_of_subarrays_with_sum_k_optimal(arr,k);
    
}