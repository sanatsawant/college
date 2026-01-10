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
    int pri;
    int ct;
    int id;
    int tat;
    int wt;
    bool done;
    process(){
        at=bt=ct=id=tat=wt=pri=0;
        done=false;
    }
};
int main(){
    int n;cin>>n;
    vector<process> v(n);
    for(int i=0;i<n;i++){
        cin>>v[i].at>>v[i].bt>>v[i].pri;
        v[i].id=i;
    }

    int curr=0;
    int completed=0;
    while(completed<n){
        int mnpri=1e9;
        int idx=-1;
        for(int i=0;i<n;i++){
            if(!v[i].done && v[i].at<=curr){
                if(v[i].pri<mnpri){
                    mnpri=v[i].pri;
                    idx=i;
                }

            }
        }
        if(idx==-1){
            curr++;
            continue;
        }
        curr+=v[idx].bt;
        v[idx].ct=curr;
        v[idx].tat=v[idx].ct-v[idx].at;
        v[idx].wt=v[idx].tat-v[idx].bt;
        v[idx].done=true;
        completed++;
    }
    cout<<"ID"<<sp<<"AT"<<sp<<"BT"<<sp<<"PRI"<<sp<<"CT"<<sp<<"TAT"<<sp<<"WT"<<endl;
    for(int i=0;i<n;i++){
        cout<<v[i].id<<sp<<v[i].at<<sp<<v[i].bt<<sp<<v[i].pri<<sp<<v[i].ct<<sp<<v[i].tat<<sp<<v[i].wt<<endl;
    }

}
