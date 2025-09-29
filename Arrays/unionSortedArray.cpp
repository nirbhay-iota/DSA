#include<iostream>
#include<set>
using namespace std;
//A set's elements are all unique and sorted
//time complexity used by set is logn ...and since we are inserting elements of array to set....it will
//take O(nlogn) time
//time complexity=O(n1logn)+O(n2logn)+O(n1+n2)...[n1+n2 is worst case for pushing elements of the set to vector temp]
//space complexity= O(n1+n2)..[for set] + O(n1+n2)..[for array temp]...please remember that array temp is 
//only used to display the answer and not to solve the question...we need to clear that to tha interviewer.
void union_by_set_brute(vector<int> arr1,vector<int> arr2,int n1,int n2){
    //initializing a set
    set<int> st;
    //putting values inside it
    for(int i=0;i<n1;i++){
        st.insert(arr1[i]);
    }
    for(int i=0;i<n2;i++){
        st.insert(arr2[i]);
    }
    //copying values from set to a temporary array named temp
    vector<int> temp;
    for(auto it:st){
        temp.push_back(it);
    }
    //displaying the union array
    cout<<"Union of arr1 and arr2"<<endl;
    for(int i=0;i<temp.size();i++){
        cout<<(temp[i])<<" ";
    }
    cout<<endl;

}
//time complexity=O(n1+n2)
//space complexity=O(n1+n2)...in worst case if all the elements are unique
//dono arrays pe pointer lagayenge alag alag aur compare krke jo dono me se chhota hai usse temp me daal 
//denge,aur duplicate check krne k liye temp ke last element se match krenge aur nhi dalenge.
void union_by_2_pointer_optimal(vector<int> arr1,vector<int> arr2,int n1,int n2){
    vector<int> temp;
    int i=0,j=0;
    while(i<n1 && j<n2){
        if(arr1[i]<=arr2[j]){
            if(temp.size()==0 || temp.back() != arr1[i]){
            temp.push_back(arr1[i]);
            }
            i++;
        }
        if(arr1[i]>=arr2[j]){
            if(temp.size()==0 || temp.back() != arr2[j]){
            temp.push_back(arr2[j]);
            }
            j++;
        }
    }
    while(j<n2){
        if(temp.back() != arr2[j]){
            temp.push_back(arr2[j]);
        }
        j++;
    }
    while(i<n1){
        if(temp.back() != arr1[i]){
            temp.push_back(arr1[i]);
        }
        i++;
    }
    cout<<"Union Array:"<<endl;
    for(int i=0;i<temp.size();i++){
        cout<<temp[i]<<" ";
    }
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
    union_by_set_brute(arr1,arr2,n1,n2);
    union_by_2_pointer_optimal(arr1,arr2,n1,n2);
}