//bubble sort is just comparing 2 adjacent elements and swapping the larger one to the rightmost position.
//Once the largest elemnt is at last then perform the same for the remaining array leaving the last position.
//Time Complexity=O(n^2)--->Worst and average case
//Time Complexity=O(n)--->Best case

# include <iostream>
using namespace std;
void bubble_sort(int arr[],int n){
    for (int i=n-1;i>=1;i--){
        for(int j=0;j<=i-1;j++){
            if(arr[j]>arr[j+1]){          //isme humne andar swap kiya hai because hum selection sort me 
                                          //phle saare bache hue array m minimum dhoondhte h aur phir swap
                                          //hai but isme do ko hi compare krke direct swap krna hota hai isliye
                                          //direct if ke andar hi swap krte hai
                swap(arr[j],arr[j+1]);
            }
        }
    }

}
//If we want to optimize this code for the best case(best case in this case is when the input array is already sorted)
//we will have to define a condition to just stop after first iteration if no swap is performed(no swap performed means input array is sorted).
void bubble_sort_optimized(int arr[],int n){
    int counter=0;
    for (int i=n-1;i>=1;i--){
        for(int j=0;j<=i-1;j++){
            if(arr[j]>arr[j+1]){          
                swap(arr[j],arr[j+1]);
                counter=1;
            }
        }
        if(counter==0){
            cout<<"sorted array2"<<endl;
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
            break;
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
    bubble_sort(arr,n);
    cout<<"sorted array"<<endl;
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    bubble_sort_optimized(arr,n);
}