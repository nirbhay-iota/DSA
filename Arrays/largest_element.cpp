# include <iostream>
using namespace std;
//time comp of brute force approach= O(nlogn)
void largest_element_brute(int arr[],int n){
    for(int i=0;i<n;i++){
        for(int j=i;j>0;j--){
            if(arr[j]<arr[j-1]){
                swap(arr[j],arr[j-1]);
            }
        }
    }
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    cout<<"The largest element is:"<<arr[n-1]<<endl;
}

//time comp of brute force approach= O(n) 
void largest_element_optimal(int arr[],int n){
    int largest=0;
    for(int i;i<n;i++){
        if(arr[i]>largest){
            largest=arr[i];
        }
    }
    cout<<"The largest element is:"<<largest<<endl;
}



int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    largest_element_brute(arr,n);
        largest_element_optimal(arr,n);

}