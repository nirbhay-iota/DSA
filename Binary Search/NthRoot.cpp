#include<iostream>
#include<math.h>
using namespace std;
void NthRoot(int n,int m){
    int low=0,high=n,ans=-1;
    while(high>=low){
        int mid=(high+low)/2;
        if(pow(mid,m)==n){
            cout<<"The answer is:"<<mid<<endl;
            return;
        }
        else if(pow(mid,m)>n){
            high=mid-1;
        }
        else{
            low=mid+1;
        }
    }
    cout<<"The answer is not possible:"<<ans;
}
int main(){
    int n,m;
    cout<<"enter the number:";
    cin>>n;
    cout<<"enter the root:";
    cin>>m;
    
    NthRoot(n,m);
}