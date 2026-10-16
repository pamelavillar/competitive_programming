#include <iostream>
#include <vector>
using namespace std;


int main(){


    int n_cars = 0;

    while(cin>> n_cars && n_cars != 0){
        vector<pair<int,int>> final(n_cars);
        vector<int> original(n_cars,-1);
        bool correct = true;
        for(int i = 0; i < n_cars; i++){
            cin >> final[i].first;
            cin >> final[i].second;
        }

        for(int i = 0; i < n_cars; i++){
            int car = final[i].first;
            int pos = final[i].second;
            
            int new_pos = i+pos;

            if(new_pos < 0 || new_pos > n_cars-1 ||original[new_pos] != -1  ) {
                cout<<-1<<"\n"; correct = false; 
                break;
            }

            original[new_pos] = car;
        }

        if(correct){
            for(int i = 0; i < n_cars; i++){
                cout<< original[i];
                if(i != n_cars-1) cout<< " ";
            }
            cout<< "\n";
        }
       
        

    }



}