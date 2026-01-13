#include<iostream>
#include<vector>
#include<iomanip>
#include<queue>
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
    int ct;
    int tat;
    int wt;
    bool done;
    bool inqueue;
    process(){
        inqueue=done=false;
    }
};
process v[MAX];
int main(){
    int n;cin>>n;
    int tq;cin>>tq;
    for(int i=0;i<n;i++){
        cin>>v[i].at>>v[i].bt;
        v[i].orig_bt=v[i].bt;
        v[i].id=i+1;
    }
    //sort based on at
    for(int i=0;i<n;i++){
        for(int j=0;j<n-1;j++){
            if(v[j].at>v[j+1].at) swap(v[j],v[j+1]);
        }
    }
    queue<process> q;
    int completed=0;
    int curr=0;
    while(completed<n){
        int f=0;
        int a=0;
        int id;
        if(q.size()){
            a=1;
            id=q.front().id;
            int idx=-1;
            for(int i=0;i<n;i++){
                if(v[i].id==id){
                    idx=i;
                    break;
                }
            }
            q.pop();
            
            curr+=min(v[idx].bt,tq);
            v[idx].bt-=min(v[idx].bt,tq);
            gantt.push_back(v[idx].id);
            if(v[idx].bt==0){
                v[idx].ct=curr;
                v[idx].done=true;
                v[idx].tat=v[idx].ct-v[idx].at;
                v[idx].wt=v[idx].tat-v[idx].orig_bt;
                completed++;
                f=1;

            }

        }
        for(int i=0;i<n;i++){
            if(v[i].at<=curr && !v[i].done && !v[i].inqueue){
                q.push(v[i]);
                v[i].inqueue=true;

            }
        }
        if(a && f==0){
            for(int i=0;i<n;i++){
                if(v[i].id==id){
                    q.push(v[i]);
                    break;
                }
            }

        }
        if(!q.size()){
            curr++;
        }
    }
    cout<<"id"<<sp<<"at"<<sp<<"bt"<<sp<<"ct"<<sp<<"tat"<<sp<<"wt"<<endl;
    for(int id=1;id<=n;id++){
        for(int i=0;i<n;i++){
            if(id==v[i].id){
                cout<<v[i].id<<sp<<v[i].at<<sp<<v[i].orig_bt<<sp<<v[i].ct<<sp<<v[i].tat<<sp<<v[i].wt<<endl;
                break;
            }
        }
    }

    cout<<"gantt chart\n";
    for(auto x:gantt){
        cout<<"P"<<x<<' ';
    }
}
