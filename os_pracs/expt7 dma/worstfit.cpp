#include<iostream>
#include<vector>
#include<iomanip>
#define sp setw(5)
using namespace std;
int main(){
    cout<<"no. of blocks\n";
    int n;cin>>n;
    cout<<"no. of processes\n";
    int m;cin>>m;

    vector<int> v(n);
    for(int i=0;i<n;i++) cin>>v[i];
    vector<int> p(m);
    for(int i=0;i<m;i++) cin>>p[i];

    vector<int> ans[n];
    

    vector<int> notalloc;
    //best fit
    for(int i=0;i<m;i++){
        int idx=-1;
        int mx=-1e9;
        for(int j=0;j<n;j++){
            if(v[j]>=p[i] && v[j]-p[i]>mx){
                mx=max(mx,v[j]-p[i]);
                idx=j;
            }
        }
        if(idx==-1) notalloc.push_back(i);
        else{
            v[idx]-=p[i];
            ans[idx].push_back(i);
        }

    }

    //output
    for(int i=0;i<n;i++){
        cout<<"block"<<i+1<<sp;
        for(auto x:ans[i]) cout<<x+1<<' ';
   
        cout<<"                 "<<v[i]<<'\n';
    }
    cout<<'\n';
    cout<<"not allocated processes\n";
    for(auto x:notalloc) cout<<x+1<<' ';

}