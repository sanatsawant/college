#include<iostream> 
#include<iomanip>
#include<cmath>
#define sp setw(10)
#define MAX 50
using namespace std;

int v[MAX];
int path[MAX];
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
    path[0]=x;
    
    for(int i=0;i<n;i++){
        int mn=1e9;
        int idx=-1;
        for(int j=0;j<n;j++){
            if(abs(x-v[j])<mn && v[j]!=-1){
                mn=abs(x-v[j]);
                idx=j;
            }
        }
        x=path[i+1]=v[idx];
        v[idx]=-1;
    }
    int ans=0;
    cout<<"from"<<sp<<"to"<<sp<<"dist"<<"\n\n";
    for(int i=0;i<n;i++){
        cout<<path[i]<<sp<<path[i+1]<<sp<<abs(path[i+1]-path[i])<<'\n';
        ans+=abs(path[i+1]-path[i]);
    }
    cout<<"\n";
    for(int i=0;i<n+1;i++){
        cout<<path[i];
        if(i!=n) cout<<"->";
    }
    cout<<'\n';
    cout<<"head mov="<<ans<<'\n';

}