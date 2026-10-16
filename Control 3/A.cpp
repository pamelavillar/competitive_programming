// STATION BALANCE

// HOW TO SOLVE
// GREEDY ALGO:
// Solo tienes que ordenar los espcimenes en un vector de 2*C los espacios faltantes los llenas de 0 y vas haciendo
// match del mas pequeño al mas grande y asi sucesivamente
//#include <iomanip> 
//  cout<<"IMBALANCE = "<< std::fixed << std::setprecision(5) << imbalance<<"\n";

#include <iostream>
#include <vector>
#include <map>
#include <cmath>
#include <algorithm>
#include <iomanip> 
using namespace std;


int main(){
    
    int c,s;
    int t =0;
    while(cin>>c>>s){
        vector<int> weights(2*c);

        int zeros = 2*c - s;
        float suma_total = 0;

        for(int i = 0; i < zeros; i++){
            weights[i] = 0;
        }

        for(int i = zeros; i < 2*c; i++){
            int n; cin>>n;
            weights[i] = n;
            suma_total+=n;
        }
        sort(weights.begin(), weights.end());

        vector<vector<int>>results(c);
        vector<float> masa_chamber(c);

        int a =0, b = 2*c-1;
        for(int i = 0; i < c; i++){
            int f = weights[a];
            int l = weights[b];
            results[i].push_back(f);
            results[i].push_back(l);
            a++; b--;
            masa_chamber[i] = f+l;
        }

        float promedio  = suma_total/c;
        float imbalance = 0;

        for (auto a : masa_chamber){
            imbalance += abs(a-promedio);
        }


        cout<<"Set #"<<++t<<endl;

        for(int i = 0; i < c; i++){
            cout<<" "<< i<<":";
            if(results[i][0]) cout<<" "<<results[i][0];
            if(results[i][1]) cout<<" "<<results[i][1];
            cout<<"\n";
        }

        cout<<"IMBALANCE = "<< std::fixed << std::setprecision(5) << imbalance<<"\n";
        cout<<endl;

        

    }
}