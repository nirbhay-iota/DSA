#include <iostream>
#include <map>
using namespace std;
// TC=O(n^2)
// SC=O(1)
void majority_element_brute(vector<int> arr, int n)
{

    for (int i = 0; i < n; i++)
    {
        int cnt = 0;
        for (int j = 0; j < n; j++)
        {
            if (arr[i] == arr[j])
                cnt++;
        }
        if (cnt > n / 2)
        {
            cout << "Majority element by brute apprach: " << arr[i] << " appearing " << cnt << " times " << endl;
            break;
        }
    }
}
// TC=O(nlogn) since each map operation is logn done n times
// SC=O(n)   for map
void majority_element_hash_better(vector<int> arr, int n)
{
    map<int, int> mpp;
    for (int i = 0; i < n; i++)
    {
        mpp[arr[i]] += 1;
        if (mpp[arr[i]] > n / 2)
        {
            cout << "Majority element by better apprach: " << arr[i] << " appearing " << mpp[arr[i]] << " times " << endl;
        }
    }
}
//Read point 6 of readme and apply moore's voting algorithm for the optimal solution
//time=O(n)
//space=O(1)
void majority_element_optimal(vector<int> arr,int n){
    int element=-1,cnt=0;
    for(int i=0;i<n;i++){
        if(cnt==0){
        element=arr[i];
        if(arr[i]==element){
            cnt++;
        }
        else
        cnt--;
        }
    }
    if(cnt>0){
        int finalCount=0;
        for(int i=0;i<n;i++){
            if(arr[i]==element)
            finalCount++;
        }
        if(finalCount>n/2){
        cout << "Majority element by optimal apprach: " << element << " appearing " << finalCount << " times " << endl;
    }
}
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
    majority_element_brute(arr, n);
    majority_element_hash_better(arr, n);
    majority_element_optimal(arr, n);
}