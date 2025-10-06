#include<iostream>
using namespace std;
//time=O(n^2)
//space=O(1)
void maximum_subarray_sum_better(vector<int> arr,int n){
    int maxSum=INT16_MIN;
    for(int i=0;i<n;i++){
        int sum=0;
        for(int j=i;j<n;j++){
            sum+=arr[j];
            maxSum=max(maxSum,sum);
        }
        
    }
    cout<<"Maximum Subarray Sum by better approach: "<<maxSum<<endl;
}

void maximum_subarray_sum_optimal(vector<int> arr,int n){
    int sum=0,maxSum=INT16_MIN;
    for(int i=0;i<n;i++){
        sum+=arr[i];
        maxSum=max(maxSum,sum);
        if(sum<0){
            sum=0;
        }
    }
    cout<<"Maximum Subarray Sum by better approach: "<<maxSum<<endl;
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
    cout << "Input Array" << endl;
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    maximum_subarray_sum_better(arr,n);
    maximum_subarray_sum_optimal(arr,n);
}