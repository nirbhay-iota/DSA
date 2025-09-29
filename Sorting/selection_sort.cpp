//selection sort is just iterating the array to get minimum element then swapping it with the first
//index then repeating the process for the remaining array leaving the first index of the array.
//time complexity=O(n^2)
#include <iostream>
using namespace std;
int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    cout<<"input array"<<endl;
    for(int i=0;i<n;i++){
        cout<<arr[i];
    }

    //selection sort algo
    for(int i=0;i<=n-2;i++){
        int minim=i;
        for(int j=i;j<=n-1;j++){
            if(arr[j]<arr[minim]){          //maine phle if ke andar swap likh diya tha par that is a 
                                            //wrong practice as hame poore array pe phle iterate krna
                                            //hai aur phir smallest number pe jab point krega uske baad 
                                            //swap krna h
                minim=j;
            }
            swap(arr[i],arr[minim]);
        }
    }
    cout<<"sorted array"<<endl;
    for(int i=0;i<n;i++){
        cout<<arr[i];
    }

    
}