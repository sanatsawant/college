#include<iostream>
#include<cstring> //for memset
#include<iomanip>
#define sp setw(4)
#define MAX 50
using namespace std;
int frame[MAX][MAX];
int s[MAX];
int ans[MAX];  //1 ->hit  0->fault

int main(){
    int len;cin>>len;
    memset(frame,-1,sizeof(frame));
    memset(ans,0,sizeof(ans));

    int hits=0;
    for(int i=0;i<len;i++) cin>>s[i];
    int f;cin>>f;
    int pos=1;
    frame[0][0]=s[0];
    for(int i=1;i<len;i++){
        int p=s[i];
        for(int j=0;j<f;j++){
            if(frame[i-1][j]==p){
                ans[i]=1;
                hits++;
            }
        }
        for(int j=0;j<f;j++){
            frame[i][j]=frame[i-1][j];
        }
        if(ans[i]!=1){
            frame[i][pos]=p;
        }
        pos=(pos+1)%f;
    }
        
    for(int i=0;i<len;i++){
        for(int j=0;j<f;j++){
            cout<<frame[i][j]<<sp;
        }
        cout<<"  ";
        cout<<(ans[i]?"hit":"fault");
        cout<<'\n';
        
    }
    cout<<"\n\n";

    cout<<"Hits="<<hits<<'\n';
    cout<<"Faults="<<len-hits<<'\n';

}


// 13
// 1 2 3 7 9 1 4 3 6 2 3 2 6
// 4