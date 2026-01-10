// #include<iostream>
// #include<vector>
// #include<queue>
// #include<algorithm>
// #include<utility>
// #include<iomanip>
// #define sp setw(10)
// using namespace std;
// int n;
// class process{
//     public:
//     int at;
//     int bt;
//     int orig_bt;
//     int ct;
//     int id;
//     int tat;
//     int wt;
//     bool done;
//     bool in_queue;
//     process(){
//         at=bt=ct=id=tat=wt=0;
//         done=false;
//         in_queue=false;
//     }
// };

// vector<process> v(10000);
// void sortby_at(vector<int>& t){
//     int m=t.size();
//     for(int i=0;i<m;i++){
//         for(int j=0;j<m-1;j++){
//             if(v[t[j]].at>v[t[j+1]].at) swap(t[j],t[j+1]);
//         }
//     }
// }
// int main(){
//     cin>>n;
//     int tq;cin>>tq;
    
//     for(int i=0;i<n;i++){
//         cin>>v[i].at>>v[i].bt;
//         v[i].orig_bt=v[i].bt;
//         v[i].id=i;
//     }

//     int curr=0;
//     int completed=0;
//     queue<int> q;

//     while(completed < n){

//         // add newly arrived processes
//         for(int i = 0; i < n; i++){
//             if(!v[i].done && !v[i].in_queue && v[i].at <= curr){
//                 q.push(i);
//                 v[i].in_queue = true;
//             }
//         }

//         if(q.empty()){
//             curr++;
//             continue;
//         }

//         int p = q.front();
//         q.pop();

//         int exec = min(v[p].bt, tq);
//         v[p].bt -= exec;
//         curr += exec;

//         // add arrivals during execution
//         for(int i = 0; i < n; i++){
//             if(!v[i].done && !v[i].in_queue && v[i].at <= curr){
//                 q.push(i);
//                 v[i].in_queue = true;
//             }
//         }

//         if(v[p].bt == 0){
//             v[p].ct = curr;
//             v[p].tat = v[p].ct - v[p].at;
//             v[p].wt = v[p].tat - v[p].orig_bt;
//             v[p].done = true;
//             completed++;
//         } else {
//             q.push(p);
//         }
// }


//     cout<<"id"<<sp<<"at"<<sp<<"bt"<<sp<<"ct"<<sp<<"tat"<<sp<<"wt"<<endl;
//     for(int i=0;i<n;i++){
//         cout<<v[i].id<<sp<<v[i].at<<sp<<v[i].orig_bt<<sp<<v[i].ct<<sp<<v[i].tat<<sp<<v[i].wt<<endl;
//     }



// }