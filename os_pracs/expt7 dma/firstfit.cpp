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
    //first fit
    for(int i=0;i<m;i++){
        int f=0;
        for(int j=0;j<n;j++){
            if(v[j]>=p[i]){
                v[j]-=p[i];
                ans[j].push_back(i);
                f=1;
                break;
            }
        }
        if(!f) notalloc.push_back(i);
    }

    //output
    for(int i=0;i<n;i++){
        cout<<"block"<<i<<sp;
        for(auto x:ans[i]) cout<<x<<' ';
        cout<<sp<<sp;
        cout<<v[i]<<'\n';
    }
    cout<<'\n';
    cout<<"not allocated processes\n";
    for(auto x:notalloc) cout<<x<<' ';

}
