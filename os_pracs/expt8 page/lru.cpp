#include<iostream>
#include<cstring> //for memset
#include<iomanip>
#define sp setw(4)
#define MAX 50
using namespace std;
int frame[MAX][MAX];
int s[MAX];
int ans[MAX];  //1 ->hit  0->fault
int buf[MAX];

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
            if(pos<f) frame[i][pos]=p;
            else{
                
                for(int k=0;k<f;k++){
                    buf[k]=-1;
                    for(int j=i-1;j>=0;j--){
                        if(s[j]==frame[i-1][k]){
                            buf[k]=j;
                            break;
                        }
                    }
                }
              
                int mn=1e9;
                int idx=0;
                for(int k=0;k<f;k++){
                    if(buf[k]<mn){
                        mn=buf[k];
                        idx=k;

                    }
                }
           
                frame[i][idx]=s[i];

                
            }
            
        }
        pos++;
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