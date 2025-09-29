#include<iostream>
#include<set>
using namespace std;
//time complexity=O(n1*n2)...=O(n^2)
//space complexity=O(n1) or O(n2)
//this approach is done using pure sets concept...in this the duplicates are not considered...
//but if we take the concept of multiset then we have to keep in mind that if arr1 has 2 3's and arr2 has 
//3 3's...then there will be 2 3's in the intersection array.
//in short intersection array me duplicates ho skte hai but tabhi agar dono input arrays me utne same elements ho.
//jaise agar dono arrays me 3 baar 6 hoga toh intersection array me bhi 3 baar 6 hoga...agar 1 arr me 
//2 baar 6 hoga aur doosre me 3 baar toh intersection array me 2 baar 6 hoga.
void intersection_by_2_pointer_brute_pureset(vector<int> arr1,vector<int> arr2,int n1,int n2){
    vector <int> temp;
    for(int i=0;i<n1;i++){
        for(int j=0;j<n2;j++){
          if(temp.size()==0 || temp.back() != arr1[i]){
            if(arr1[i]==arr2[j]){
                temp.push_back(arr1[i]);
                break;
            }
        }
     }
    }
    cout<<"Intersection Array:"<<endl;
    for(int i=0;i<temp.size();i++){
        cout<<temp[i]<<" ";
    }
    cout<<endl;
}
//in this we are just keeping a visited array to keep tract for the more than one number of common elements
void intersection_by_2_pointer_brute_multiset(vector<int> arr1,vector<int> arr2,int n1,int n2){
    vector <int> temp;
    vector <int> visited(n2,0);
    for(int i=0;i<n1;i++){
        for(int j=0;j<n2;j++){
          if(temp.size()==0 || visited[j]==0){
            if(arr1[i]==arr2[j]){
                temp.push_back(arr1[i]);
                visited[j]=1;
                break;
            }
            if(arr2[j]>arr1[i])
            break;
        }
     }
    }
    cout<<"Intersection Array:"<<endl;
    for(int i=0;i<temp.size();i++){
        cout<<temp[i]<<" ";
    }
    cout<<endl;
}
//time complexity=O(n1+n2)
//space complexity=O(n1) or O(n2)...worst case
void intersection_by_2_pointer_optimal(vector<int> arr1,vector<int> arr2,int n1,int n2){
    vector<int> temp;
    int j=0,i=0;
    while(i<n1 && j<n2){
        if(arr1[i]>arr2[j]){
            j++;
        }
        if(arr1[i]<arr2[j]){
            i++;
        }
        if(arr1[i]==arr2[j]){
            temp.push_back(arr1[i]);
            i++;
            j++;
        }
    }
    cout<<"Intersection Array:"<<endl;
    for(int i=0;i<temp.size();i++){
        cout<<temp[i]<<" ";
    }
    cout<<endl;
}
int main(){
    int n1,n2;
    cout<<"size of the first array"<<endl;
    cin>>n1;
    cout<<"size of the second array"<<endl;
    cin>>n2;
    vector<int> arr1(n1);
    vector<int> arr2(n2);
cout<<"enter elements of first array"<<endl;
    for(int i=0;i<n1;i++){
        cin>>arr1[i];
    }
cout<<"enter elements of second array"<<endl;
    for(int i=0;i<n2;i++){
        cin>>arr2[i];
    }
    cout<<"input array1:"<<endl;
    for(int i=0;i<n1;i++){
        cout<<arr1[i]<<" ";
    }
    cout<<endl;
    cout<<"input array2:"<<endl;
    for(int i=0;i<n2;i++){
        cout<<arr2[i]<<" ";
    }
    cout<<endl;
    //union_by_set_brute(arr1,arr2,n1,n2);
    intersection_by_2_pointer_brute_pureset(arr1,arr2,n1,n2);
    intersection_by_2_pointer_brute_multiset(arr1,arr2,n1,n2);
    intersection_by_2_pointer_optimal(arr1,arr2,n1,n2);
}