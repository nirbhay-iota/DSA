#include<iostream>
#include<algorithm>
using namespace std;

//time comp=O(n)
//also while telling the SPACE COMPLEXITY , we should answer what is asked...taking this example
//If we are asked what is the space I used in this algorithm then i have to answer O(n) as i am using my
//own array but if I am asked how much extra space i am using then i have to answer O(1) as we are not using 
//any extra space in this approach
void rotate_by_one(vector<int> arr,int n){
    int temp=arr[0];
    for(int i=0;i<n-1;i++){
        arr[i]=arr[i+1];
    }
    arr[n-1]=temp;
    cout<<"rotated array by 1 place:"<<endl;
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;

}

void rotate_by_D_places_recursive(vector<int> arr,int n,int D){
    if(D>0){
    int temp=arr[0];
    for(int i=0;i<n-1;i++){
        arr[i]=arr[i+1];
    }
    arr[n-1]=temp;
    rotate_by_D_places_recursive(arr,n,D-1);
    }
    if(D==0){
    cout<<"rotated array by "<<"D"<<" places using recursion"<<endl;
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    }   
}

//time complexity=O(n+D)
//space complexity=O(D)....as the only extra space we are using is by creating a temp array
void rotate_by_D_places_brute(vector<int> arr,int n,int D){
    if(D>n){
        D=D%n;      //this is done to reduce no.of calculations because if we rotate an n sized array
                    //n times ...it results in the same array
    }
    vector<int> temp(D);
    for(int i=0;i<D;i++){
        temp[i]=arr[i];
    }
    for(int i=D;i<n;i++){
        arr[i-D]=arr[i];
    }
    for(int i=D;i<n;i++){
        arr[i]=temp[i-D];
    }
    cout<<"rotated array by "<<D<<" places using brute approach"<<endl;
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

//time complexity=O(n)-->for 1st reverse O(d),2nd reverse O(n-d),3rd reverse O(n)...n+n-d+n=2n=O(n)
//space complexity=O(1)....as we are not using any extra space.
//In this optimal approach we are reversing array from first to D'th element and then D'th+1 to n'th element
//and then reversing the whole array which will give us the desired output 
void rotate_by_D_places_optimal(vector<int> arr,int n,int D){
    reverse(arr.begin(),arr.begin()+D);
    reverse(arr.begin()+D,arr.begin()+n);
    reverse(arr.begin(),arr.begin()+n);
    cout<<"rotated array by "<<D<<" places using optimal approach"<<endl;
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
}
//{this I have done using normal array and the below it using vectors}
// int main(){
//     int n;
//     cin>>n;
//     int arr[n];
    
//     for(int i=0;i<n;i++){
//         cin>>arr[i];
//     }
//     cout<<"input array:"<<endl;
//     for(int i=0;i<n;i++){
//         cout<<arr[i]<<" ";
//     }
//     cout<<endl;
//     rotate_by_one(arr,n);
//     int D; 
//     cin>>D;
    
//     rotate_by_D_places(arr,n,D);
// }
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
    rotate_by_one(arr,n);
    int D; 
    cin>>D;
    
    rotate_by_D_places_recursive(arr,n,D);
    rotate_by_D_places_brute(arr,n,D);
    rotate_by_D_places_optimal(arr,n,D);
}