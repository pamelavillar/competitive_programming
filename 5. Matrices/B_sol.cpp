#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

vector<vector<int>> new_matrix(vector<vector<int>>& matriz){

    vector<vector<int>> newi(3,vector<int>(3)) ;

    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            int suma = 0;
            int arriba = i-1;
            int abajo  = i+1;
            int izq = j-1;
            int der = j+1;

            if(arriba >= 0) suma += matriz[arriba][j];
            if(abajo < 3) suma += matriz[abajo][j];
            if(izq >= 0) suma += matriz[i][izq];
            if(der < 3) suma += matriz[i][der];

            suma = suma % 2;

            newi[i][j] = suma;
        }
    }
    return newi;

}

int main(){

    int num_tests = 0;
    cin >> num_tests;
    vector<int> results;


    while(num_tests--){

        vector<int> nums(512,-1);
        

        vector<vector<int>> matriz(3,vector<int>(3));

        for(int i = 0; i < 3; i++){
            string first_row;
            cin>>first_row;
            for(int j = 0; j < 3; j++){
                matriz[i][j] = first_row[j]-'0';
            }
        }

        int cont = 0;
        
        while(true){
            int estado = 0;

            for(int i = 0; i < 3; i++){
                for(int j = 0; j < 3; j++){
                    estado = estado * 2 + matriz[i][j];
                }
            }

            if(nums[estado] != -1) {
                cout<<nums[estado]-1<<"\n";
                //results.push_back(nums[estado]-1); 
                break;
            }

            nums[estado] = cont;
            //vector<vector<int>> new_matriz = new_matrix(matriz);
            matriz = new_matrix(matriz);
            cont++;

            
        }

    }
    /*
    for(auto a:results){
        cout<<a<<"\n";
    }*/
}