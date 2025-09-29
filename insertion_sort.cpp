//insertion sort me direct value ko uski place me insert krna hota hai apne peeche ke saare elements 
//se compare krke
//time complexity=O(n^2)---->for worst and avarage and best cases for my code(the function insertion_sort())
//time complexity=O(n^2)---->for worst and avarage case (for function insertion_sort_optimized)
//time complexity=O(n)---->for best case (for function insertion_sort_optimized)
# include <iostream>
using namespace std;
void insertion_sort(int arr[],int n){
    for (int i=1;i<=n-1;i++){
        for(int j=i;j>0;j--){
            if(arr[j]<arr[j-1]){          
                swap(arr[j],arr[j-1]); 
            }
        }
    }

}
void insertion_sort_optimized(int arr[],int n){
    for (int i=1;i<=n-1;i++){
        int j=i;
        while(j>0 && arr[j]<arr[j-1]){
                swap(arr[j],arr[j-1]);
                j--;
        }
    }

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
    insertion_sort(arr,n);
    cout<<"sorted array"<<endl;
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    
}