#include <iostream>
#include <vector>
#include <set>
#include <queue>
using namespace std;

int main(){
    int t;
    cin>>t;
    for(int k = 0; k <t; k++){
        int N, K ;
        cin>>N>>K;

        vector<int> X;
        vector<int> Y;

        for(int i = 0; i < N; i++){
            int num;
            cin>>num;
            X.push_back(num);
        }
        for(int i = 0; i < N; i++){
            int num;
            cin>>num;
            Y.push_back(num);
        }

        priority_queue<int> resto;

        int negative = 0;
        for(int i = 0; i < N; i++){
            int resta = Y[i] - X[i];
            if(resta<0) negative++;
            resto.push(resta);
        }

        int deny = 0;
        if(negative>K) deny = K;
        else deny = negative;

        long long profit = 0;
        
        for(int i= 0; i < N-deny; i++){
            profit+=resto.top();
            resto.pop();
        }
        cout<< "Case "<< k+1<<": ";
        if (profit <= 0) cout<<"No Profit"<<endl;
        else cout<<profit<<endl;

    }
}