#include<iostream>
#include<vector>
#include<algorithm>
#include<utility>
#include<iomanip>
#define sp setw(10)
#define size 4
using namespace std;

int mutex=1;
int full=0;
int empt=size;
vector<string> buffer(size,"_");
int in=0,out=0;

void wait(int& s){
    if(s>0) s--;
    else cout<<"s is 0"<<'\n';
}
void signal(int& s){
    s++;
}
void produce(string item){
    if(empt==0){
        cout<<"buffer full\n";
        return;
    }
    wait(empt);
    wait(mutex);
    buffer[in]=item;
    in=(in+1)%size;
    signal(mutex);
    signal(full);
}
void consume(){
    if(full==0){
        cout<<"buffer empty\n";
        return;
    }
    wait(full);
    wait(mutex);
    buffer[out]="_";
    out=(out+1)%size;
    signal(mutex);
    signal(empt);
}

int main(){
    while(1){
        printf("\n--- MENU ---\n");
        printf("1. Produce Item\n");
        printf("2. Consume Item\n");
        printf("3. Display Buffer\n");
        printf("4. Exit\n");
        printf("Enter choice: ");
        int n;cin>>n;
        if(n==1){
            string i;
            cin>>i;
            produce(i);

        }
        else if(n==2){
            consume();

        }
        else if(n==3){
            for(int i=0;i<size;i++) cout<<buffer[i]<<' ';
            cout<<'\n';

        }
        else if(n==4){
            exit(0);

        }

    }

}