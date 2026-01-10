#include<iostream>
#include<vector>
#include<iomanip>
#define MAX 50
#define sp setw(10)

using namespace std;
int alloc[MAX][MAX];
int mx[MAX][MAX];
int avail[MAX];
int need[MAX][MAX];
bool finish[MAX];
int req[MAX];
int work[MAX];
int n,m;


int bankers(){
    //safety algo
    vector<int> safeseq;
    for(int i=0;i<n;i++){
        finish[i]=false;
    }
    for(int i=0;i<m;i++){
        work[i]=avail[i];
    }
   
    int check=0;
    while(check<n){
        for(int i=0;i<n;i++){
            if(finish[i]==false){
                int f=1;
                for(int j=0;j<m;j++){
                    if(need[i][j]>work[j]) f=0;
                }
                if(f){
                    for(int j=0;j<m;j++){
                        work[j]+=alloc[i][j]; 
                    }
                    finish[i]=true;
                    safeseq.push_back(i);
                    f=0;
                }
            }
        }
        int flag=0;
        for(int i=0;i<n;i++){
            if(finish[i]==false){
                flag=1;
                break;
            }
        }
        if(flag) check++;
        else break;
        
    }

    if(check==n){
        cout<<"No safeseq\n";
        //restore

        return 0;
    }
    else{
        cout<<"safe seq\n";
        for(int i=0;i<safeseq.size();i++) cout<<"P"<<safeseq[i]<<' ';
        cout<<'\n';
        cout<<"work\n";
        for(int i=0;i<m;i++) cout<<work[i]<<' ';
        cout<<"\n\n\n";
        return 1;
    }

}

int main(){
    cin>>n; //process
    cin>>m;  //resources
    cout<<"enter alloc\n";
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>alloc[i][j];
        }
    }
    cout<<"enter max mat\n";
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>mx[i][j];
        }
    }
    cout<<"enter avail\n";
    for(int i=0;i<m;i++) cin>>avail[i];
    cout<<'\n';

    //calc need
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            need[i][j]=mx[i][j]-alloc[i][j];
        }

    }

    int k=bankers();



    //resource-req algo
    int ok=0;
    while(1){
        cout<<"currrent state\n";
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                cout<<alloc[i][j]<<' '; 
            }
            cout<<sp;
            for(int j=0;j<m;j++){
                cout<<mx[i][j]<<' '; 
            }
            cout<<sp;
            for(int j=0;j<m;j++){
                cout<<need[i][j]<<' '; 
            }
            cout<<sp;
            if(i==0){
                for(int j=0;j<m;j++) cout<<avail[j]<<' ';
            }
            cout<<'\n';
        }
        cout<<"\ndo you want to request?(1/0)\n";
        cin>>ok;
        if(!ok) break;
        int p;
        cout<<"enter p\n";
        cin>>p;
        cout<<"enter req\n";
        for(int i=0;i<m;i++){
            cin>>req[i];
        }

        // check req<=need
        int f=0;
        for(int i=0;i<m;i++){
            if(req[i]>need[p][i]){
                f=1;
                break;
            }
        }
        if(f){
            cout<<"req>need  process exceed max claim\n";
            f=0;
            break;
        }

        //check req<=avail
        f=0;
        for(int i=0;i<m;i++){
            if(req[i]>avail[i]){
                f=1;
                break;
            }
        }
        if(f){
            cout<<"avail>need  not enough avail\n";
            f=0;
            break;
        }
        //update
        for(int i=0;i<m;i++){
            avail[i]-=req[i];
            need[p][i]-=req[i];
        }
        for(int i=0;i<m;i++){
            alloc[p][i]+=req[i];
        }
        int k=bankers();
        if(!k){
            cout<<"\nrestoring states\n";
            for(int i=0;i<m;i++){
                avail[i]+=req[i];
                need[p][i]+=req[i];
            }
            for(int i=0;i<m;i++){
                alloc[p][i]-=req[i];
            }
        }
    }
}



// 5
// 4
// 0 0 1 2
// 1 0 0 0 
// 1 3 5 4
// 0 6 3 2
// 0 0 1 4
// 0 0 1 2
// 1 7 5 0
// 2 3 5 6
// 0 6 5 2
// 0 6 5 6
// 1 5 2 0