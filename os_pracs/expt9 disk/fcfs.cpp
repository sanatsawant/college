#include<iostream> 
#include<iomanip>
#include<cmath>
#define sp setw(10)
#define MAX 50
using namespace std;

int v[MAX];
int abs_val(int x) {
    return (x < 0) ? -x : x;
}

int main(){
    cout<<"enter request queue (-1 to exit)\n";
    int n=0;
    while(1){
        int x;cin>>x;
        if(x==-1) break;
        v[n++]=x;
    }
    cout<<"enter current r/w head\n";
    int x;cin>>x;
    cout<<"from"<<sp<<"to"<<sp<<"dist"<<"\n\n";

    int ans=abs_val(x-v[0]);
    cout<<x<<sp<<v[0]<<sp<<abs(x-v[0])<<'\n';

    for(int i=0;i<n-1;i++){
        cout<<v[i]<<sp<<v[i+1]<<sp<<abs(v[i+1]-v[i])<<'\n';
        ans+=abs_val(v[i+1]-v[i]);

    }
    cout<<"\n";
    cout<<x<<"->";
    for(int i=0;i<n;i++){
        cout<<v[i];
        if(i!=n-1) cout<<"->";
    }
    cout<<'\n';
    cout<<"head mov="<<ans<<'\n';
}