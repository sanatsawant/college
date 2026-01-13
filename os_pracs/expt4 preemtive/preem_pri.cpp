#include<iostream>
#include<vector>
#include<iomanip>
#define MAX 20
#define sp setw(5)
using namespace std;

vector<int> gantt;
class process{
    public:
    int id;
    int at;
    int bt;
    int orig_bt;
    int pri;
    int ct;
    int tat;
    int wt;
    bool done;
    process(){
        done=false;
    }
};
process v[MAX];
int main(){
    int n;cin>>n;
    for(int i=0;i<n;i++){
        cin>>v[i].at>>v[i].bt>>v[i].pri;
        v[i].orig_bt=v[i].bt;
        v[i].id=i+1;
    }
    
    int completed=0;
    int curr=0;


    // low number -> high pri
    while(completed<n){
        int pri=1e9;
        int idx=-1;
        for(int i=0;i<n;i++){
            if(!v[i].done && v[i].at<=curr){
                if(v[i].pri<pri){
                    pri=v[i].pri;
                    idx=i;
                }
            }
        }
        curr++;
        if(idx==-1){
            continue;
        }
        v[idx].bt--;
        gantt.push_back(v[idx].id);
        if(v[idx].bt==0){
            v[idx].ct=curr;
            v[idx].done=true;
            v[idx].tat=v[idx].ct-v[idx].at;
            v[idx].wt=v[idx].tat-v[idx].orig_bt;
            completed++;
        }

    }

    cout<<"id"<<sp<<"at"<<sp<<"bt"<<sp<<"ct"<<sp<<"tat"<<sp<<"wt"<<endl;
    for(int i=0;i<n;i++){
        cout<<i+1<<sp<<v[i].at<<sp<<v[i].orig_bt<<sp<<v[i].ct<<sp<<v[i].tat<<sp<<v[i].wt<<endl;
    }

    cout<<"gantt chart\n";
    for(auto x:gantt){
        cout<<"P"<<x<<' ';
    }

}
