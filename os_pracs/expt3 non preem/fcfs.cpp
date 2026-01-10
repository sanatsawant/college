#include<iostream>
#include<vector>
#include<algorithm>
#include<utility>
#include<iomanip>
#define sp setw(10)
using namespace std;
class process{
    public:
    int at;
    int bt;
    int ct;
    int id;
    int tat;
    int wt;
    process(){
        at=bt=ct=id=tat=wt=0;
    }
};
int main(){
    int n;cin>>n;
    vector<int> at(n);
    vector<int> bt(n);
    vector<process> v(n);
    for(int i=0;i<n;i++){
        cin>>at[i]>>bt[i];
        v[i].id=i;
        v[i].at=at[i];
        v[i].bt=bt[i];
    }
    
    for(int i=0;i<n;i++){
        for(int j=0;j<n-1;j++){
            if(v[j].at>v[j+1].at) swap(v[j],v[j+1]);
        }
    }
    int curr=0;
    for(int i=0;i<n;i++){
        if(curr<v[i].at){
            curr=v[i].at;
        }
        curr+=v[i].bt;
        v[i].ct=curr;
        v[i].tat=v[i].ct-v[i].at;
        v[i].wt=v[i].tat-v[i].bt;


    }
    cout<<"id"<<sp<<"at"<<sp<<"bt"<<sp<<"ct"<<sp<<"tat"<<sp<<"wt"<<endl;

    for(int id=0;id<n;id++){
        for(int i=0;i<n;i++){
            if(id==v[i].id) cout<<v[i].id<<sp<<v[i].at<<sp<<v[i].bt<<sp<<v[i].ct<<sp<<v[i].tat<<sp<<v[i].wt<<endl;
        }
        
    }

    
    

}