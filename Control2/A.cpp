// INCEPTION

// HOW TO SOLVE
// USA UNA LISTA Y SOLO TIENES QUE IR RECORRIENDO Y SACANDO CUANDO YA NO ESTAN DORMIDOS Y YA

#include <iostream>
#include <vector>
#include <map>
#include <list>

using namespace std;


int main(){
    int q;cin>>q;
    list<string> personas;
    while(q--){
        string accion;
        string name;
        cin>>accion;

        if(accion == "Sleep"){
            cin>> name;
            personas.push_front(name);
        }

        else if(accion == "Kick"){  
            if(!personas.empty()) personas.pop_front();          

        }

        else if(accion == "Test"){            
            
            if(!personas.empty()) cout<<personas.front()<<endl;
            else cout<< "Not in a dream"<<endl;
        } 

    }
}