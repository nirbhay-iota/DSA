#include<iostream>
using namespace std;
void sqrt(int n){
    int low=0,high=n;
    int ans=-1;
    while(high>=low){
        int mid=(low+high)/2;
        if(mid*mid<=n){
            ans=mid;
            low=mid+1;
        }
        else{
            high=mid-1;
        }
    }
    cout<<"The square root of n is:"<<ans<<endl;
}
int main(){
    int n;
    cout<<"enter the number:";
    cin>>n;
    sqrt(n);
}