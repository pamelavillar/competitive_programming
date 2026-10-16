// CORPORATIVE NETWORK

// HOW TO SOLVE


#include <iostream>
#include <vector>
#include <map>
using namespace std;


int main(){
    int T; cin>>T;
    while(T--){
        int N; cin>>N;

        vector<int> enterprises(N);

        for(int i=0; i < N; i++){
            enterprises[i]= i;
        }

        char command; 
        while(cin>>command && command != 'O'){
            if(command == 'E'){
                int n; cin>>n;
                n-=1;
                int lenght = 0;
                while(enterprises[n] != n){
                    lenght+=(abs(n-enterprises[n]))%1000;
                    n = enterprises[n];
                }
                cout<<lenght<<endl;
            }
            else if(command == 'I'){
                int e1, e2;
                cin>>e1>>e2;
                e1--;e2--;

                enterprises[e1] = e2;
            }
        }

    }
}