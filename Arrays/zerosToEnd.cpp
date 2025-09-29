#include<iostream>
using namespace std;

//time complexity=O(n)
//space complexity=O(n) as we are using an array temp of size n.
void zeros_to_end_brute(vector<int> arr,int n){
    //int index=0;
    vector<int> temp;
    for(int i=0;i<n;i++){
        if(arr[i]!=0){
            temp.push_back(arr[i]);
        }
        // if(arr[i]!=0){
        //     temp[index]=arr[i];      //we can do this also instead of pushback
        //     index++;
        // } 
    }
    int x=temp.size()-1;
    for(int i=x;i<n;i++){
        temp.push_back(0);
    }
    for(int i=0;i<n;i++){
        arr[i]=temp[i];
    }

    cout<<"All zeros to end array by brute approach:"<<endl;
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;

}

//We will just use 2 pointer method which we used while reducing duplicate elements 
//time complexity=O(n)
//space complexity=O(1) as we are NOT using any extra array.
void zeros_to_end_optimal(vector<int> arr,int n){
    int index=0;
    for(int i=0;i<n;i++){
        if(arr[i]!=0)
        {
            if(arr[index]==0){
            swap(arr[index],arr[i]);
            index++;
        }
        else{
            index++;
        }
        }
    }
    
    cout<<"All zeros to end array by optimal approach:"<<endl;
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
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
    cout<<"input array:"<<endl;
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    zeros_to_end_brute(arr,n);
    zeros_to_end_optimal(arr,n);


}