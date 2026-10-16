#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <set>


using namespace std;



int main(){
    int test_cases = 1;
    cin>>test_cases;
    while(test_cases--){
        
        int places= 0;
        cin>>places;
        cin.ignore();

        set<pair<int,int>> vecinos;

        for(int i = 0; i < places ; i++){
            
            string linea;
            getline(cin,linea);

            stringstream ss(linea);
            int x;
            int cantidad= 0;

            while(ss>>x) {
                cantidad++;
            }
            vecinos.insert({cantidad,i+1});
        }
        
        int minimo = vecinos.begin()->first;
        bool primero = true;
        for(auto i  = vecinos.begin(); i != vecinos.end() && i->first == minimo; i++){
            if(!primero) cout<<" ";
            cout<<i->second;
            primero = 0;
        }
        cout<<"\n";
    }
}