#include <iostream>
#include <list>
#include <vector>
#include <string>
using namespace std;

int main(){
    int num_teams = 1;
    
    while(num_teams){
        cin >> num_teams;
        if(!num_teams) break;

        vector<vector<int>>(num_teams);

        list<pair<int,int>> queue;

        //REGISTRO
        for(int i = 0; i <= num_teams; i++){
            int num_int=0;
            cin >> num_int;

            for(int j = 0; j< num_int; j++){
                int id_int = 0;
                cin >> id_int;
                num_teams[i].push_back(id_int);

                queue.push_back({id_int,i});
            }

        }

        //EMPIEZA EL PROCESAMIENTO

        

        string instruction;

        while(instruction != "STOP"){
            
            if(instruction == "ENQUEUE"){

            }
        }
    }
}
