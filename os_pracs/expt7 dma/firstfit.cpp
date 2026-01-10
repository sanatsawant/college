// #include<iostream>
// #include <cstring>
// #include<iomanip>
// #define MAX 50
// #define sp setw(8)
// using namespace std;

// int v[MAX];
// int p[MAX];
// int alloc[MAX];
// int avail[MAX];

// int main(){
//     memset(alloc,-1,sizeof(alloc));

//     cout<<"enter no. of blocks\n";
//     int n;cin>>n;
//     for(int i=0;i<n;i++) cin>>v[i];
//     cout<<"enter no. of processes\n";
//     int m;cin>>m;
//     for(int i=0;i<m;i++) cin>>p[i];
    
//     for(int i=0;i<m;i++){
//         for(int j=0;j<n;j++){
//             if(p[i]<=v[j]){
//                 alloc[i]=j;
//                 v[j]-=p[i];
//                 avail[j]=v[j];
//             }
//         }
//     }

//     for(int i=0;i<n;i++){
//         cout<<"Block"<<i+1<<sp<<alloc[i]<<"-"<<
//     }

    


// }