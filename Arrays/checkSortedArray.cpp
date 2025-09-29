#include<iostream>
using namespace std;
void check_sorted_array_brute(int arr[],int n){
    int counter=0;
    for (int i=1;i<=n-1;i++){
        for(int j=i;j>0;j--){
            if(arr[j]<arr[j-1]){          
                counter++;
            }
        }
    }
    cout<<"Brute approach solution:";
    if(counter==0){
        cout<<"array is sorted"<<endl;
    }
    else{
        cout<<"array is NOT sorted"<<endl;
    }

}
void check_sorted_array_better(int arr[],int n){
    int largest=0,counter=0;
    for(int i=0;i<n;i++){
        if(arr[i]>=largest){
            largest=arr[i];
            counter++;
        }
    }
    cout<<"optimal approach solution:";
    if(counter==n){
        cout<<"array is sorted"<<endl;
    }
    else{
        cout<<"array is NOT sorted"<<endl;
    }
}

int check_sorted_array_optimal(int arr[],int n){
    for(int i=1;i<n;i++){
        if(arr[i]>arr[i-1]){
            
        }
        else{
            return false;
        }
    }
    return true;
}
int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    cout<<"input array"<<endl;
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    check_sorted_array_brute(arr,n);
    check_sorted_array_better(arr,n);
    bool x=check_sorted_array_optimal(arr,n);
    cout<<x<<endl;
}