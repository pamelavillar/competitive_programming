#include <iostream>
#include <vector>
#include <map>
#include <list>
using namespace std;

int vecinos;
map<char, list<char>> adj;
map<char,bool> visited;
bool isTree;

void util(char v , char padre){

    visited[v]= true;
    if(!isTree) return;
    ++vecinos;

    list<char>::iterator i;
    for (i = adj[v].begin(); i != adj[v].end(); ++i){
        if(*i == padre) continue;
        if (!visited[*i]) util(*i, v);
        else isTree = 0; //its a cycle
    }
}

int main(){

    int test_cases = 1;
    cin>>test_cases;

    while(test_cases--){
        adj.clear();
        visited.clear();
        
        string edge;
        
        while(cin>>edge && edge[0] != '*'){
            char a,b;
            a = edge[1]; b = edge[3];
            adj[a].push_back(b);
            adj[b].push_back(a);
        }

        string vertices;
        cin>>vertices;

        int trees = 0;
        int acorn = 0;

        for(int i = 0; i < vertices.size(); i+=2){
            if (visited[vertices[i]]) continue;

            isTree=1;
            vecinos =0;
            util(vertices[i], '\0');

            if(vecinos == 1) acorn +=1;
            else if (isTree) trees+=1;
        }

		cout << "There are " << trees << " tree(s) and " << acorn <<" acorn(s).\n";
    }
}