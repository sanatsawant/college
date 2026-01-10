#include<iostream> 
#include<iomanip>
#include<cmath>
#define sp setw(10)
#define MAX 50
using namespace std;

int v[MAX];
int path[MAX];

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
    cout<<"enter prev r/w head\n";
    int y;cin>>y;
    v[n++]=x;

    //sort
    for(int i=0;i<n;i++){
        for(int j=0;j<n-1;j++){
            if(v[j]>v[j+1]) swap(v[j],v[j+1]);
        }
    }
    int idx=-1;
    for(int i=0;i<n;i++){
        if(v[i]==x){
            idx=i;
            break;
        }
    }
    if(y<x){
        int k=0;
        for(int i=idx;i<n;i++) path[k++]=v[i];
        for(int i=idx-1;i>=0;i--) path[k++]=v[i]; 
    }
    else{
        int k=0;
        for(int i=idx;i>=0;i--) path[k++]=v[i];
        for(int i=idx+1;i<n;i++) path[k++]=v[i];
    }
    int ans=0;
    cout<<"from"<<sp<<"to"<<sp<<"dist"<<"\n\n";
    for(int i=0;i<n-1;i++){
        cout<<path[i]<<sp<<path[i+1]<<sp<<abs(path[i+1]-path[i])<<'\n';
        ans+=abs(path[i+1]-path[i]);
    }
    cout<<"\n";
    for(int i=0;i<n;i++){
        cout<<path[i];
        if(i!=n-1) cout<<"->";
    }
    cout<<'\n';
    cout<<"head mov="<<ans<<'\n';

}