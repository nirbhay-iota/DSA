# include <iostream>
using namespace std;

//time comp=O(n^2)[due to insertion sort],,,but if I use merge sort I can reduce it to O(nlogn)
void second_largest_element_brute(int arr[],int n){
    for(int i=0;i<n;i++){
        for(int j=i;j>0;j--){
            if(arr[j]<arr[j-1]){
                swap(arr[j],arr[j-1]);
            }
        }
    }
    for(int i=n-1;i>0;i--){
        if(arr[i]!=arr[n-1]){
            
            cout<<"The second largest element in brute force approach is:"<<arr[i]<<endl;
            break;
        }
    }
}

//time comp=O(2n)=O(n)....but using 2 loops
void second_largest_element_better(int arr[],int n){
    int largest=0;
    for(int i=0;i<n;i++){
        if(arr[i]>largest){
            largest=arr[i];
        }
    }
    int second_largest=-1;
    for(int i=0;i<n;i++){
        if(arr[i]>second_largest && arr[i]!=largest){
            second_largest=arr[i];
        }
    }
    cout<<"The second largest element in brute better approach is:"<<second_largest<<endl;

}

//time comp=O(n)....but in a single loop
void second_largest_element_optimal(int arr[],int n){
    int largest=-1,second_largest=-1;
    for(int i=0;i<n;i++){
        if(arr[i]>largest){
            second_largest=largest;
            largest=arr[i];
        }
        if(arr[i]>second_largest && arr[i]!= largest){
            second_largest=arr[i];
        }
    }
    cout<<"The second largest element in optimal force approach is:"<<second_largest<<endl;
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
    second_largest_element_brute(arr,n);
    second_largest_element_better(arr,n);
    second_largest_element_optimal(arr,n);

}