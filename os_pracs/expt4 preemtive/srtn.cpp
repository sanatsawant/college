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
    int orig_bt;
    int ct;
    int id;
    int tat;
    int wt;
    bool done;
    process(){
        at=bt=ct=id=tat=wt=0;
        done=false;
    }
};
int main(){
    int n;cin>>n;
    vector<process> v(n);
    for(int i=0;i<n;i++){
        cin>>v[i].at>>v[i].bt;
        v[i].orig_bt=v[i].bt;
        v[i].id=i;
    }

    int curr=0;
    int completed=0;
    while(completed<n){

        int idx=-1;
        int mnbt=1e9;
        for(int i=0;i<n;i++){
            if(!v[i].done && v[i].at<=curr){
                if(v[i].bt<mnbt){
                    idx=i;
                    mnbt=v[i].bt;
                }
                else if(v[i].bt==mnbt){
                    if(v[i].at < v[idx].at){
                        idx=i;
                        mnbt=v[i].bt;
                    }
                    else if(v[i].at == v[idx].at){
                        if(v[i].id < v[idx].id){
                            mnbt=v[i].bt;
                            idx=i;
                        }
                    }
                }                
            }
        }

        if(idx==-1){
            curr++;
            continue;
        }
        curr++;
        v[idx].bt--;
        if(v[idx].bt==0){
            v[idx].ct=curr;
            v[idx].tat=v[idx].ct-v[idx].at;
            v[idx].wt=v[idx].tat-v[idx].orig_bt;
            completed++;
            v[idx].done=true;
        }
    }

    cout<<"id"<<sp<<"at"<<sp<<"bt"<<sp<<"ct"<<sp<<"tat"<<sp<<"wt"<<endl;
    for(int i=0;i<n;i++){
        cout<<v[i].id<<sp<<v[i].at<<sp<<v[i].orig_bt<<sp<<v[i].ct<<sp<<v[i].tat<<sp<<v[i].wt<<endl;
    }
}

// 4
// 0 5
// 1 3
// 2 4
// 4 1

// id        at        bt        ct       tat        wt
// 0         0         5         9         9         4
// 1         1         3         4         3         0
// 2         2         4        13        11         7
// 3         4         1         5         1         0