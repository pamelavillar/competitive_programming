#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main()
{
    int test_cases = 1;
    cin>> test_cases;
    vector<string> results;
    while(test_cases--){
        int n, m;
        cin>>n>>m;
        
        bool correct = true;
        vector<vector<int>> matriz_incidencia(n,vector<int> (m));
        for(int i = 0; i < n ; i++){
            for(int j = 0; j < m ; j++){  
                cin>> matriz_incidencia[i][j]; 
                
            }
        }
        
        vector<vector<int>> existe(n,vector<int> (n,false));
        int counter = 0;
        if(n > 1 && m == 0) correct = false;
        if(m > n*(n-1)/2) correct= false;

        for(int j = 0; j < m ; j++){
            int u = -1;
            int v = -1;
            counter = 0;
            for(int i = 0; i < n ; i++){  
                if(matriz_incidencia[i][j] == 1) {
                    counter++;
                    if(u == -1) u =  i;
                    else v = i;
                }
            }
            
            if (counter != 2){
                correct = false;
                break;
            }
            
            if(existe[u][v]){
                correct = false;
                break;
            }
            
            existe[u][v] = true;
            existe[v][u] = true;
        }
        
      
        if(correct) results.push_back("Yes");
        else results.push_back("No");
        
    }
    
    for(auto a: results){
        cout<<a<<"\n";
    
    }
}