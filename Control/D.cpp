// HAVE FUN WITH MATRICES

// HOW TO SOLVE
// Lo basico, solo cambias columnas por filas, y para el (modulo 10) para decrementar en vez de quitar 1 , sumas 9
// y recuerda para convertir un char 9 en int 9 solo tienes que hacer (9 - '0')


#include <iostream>
#include <vector>
#include <map>
using namespace std;


int main(){
    int T;
    cin >> T;
    int t = 1;
    while(T--){
        int N;
        cin>>N;
        vector<vector<int>> matrix(N);
        
        for(int i = 0; i < N; i++){
            string numbers;
            cin>>numbers;
            for(int j = 0; j < N; j++){
                matrix[i].push_back(numbers[j] -'0');
            }
        }




        int M;
        cin >> M;

        for(int k = 0; k < M; k++){
            string command; cin>>command;
            int a,b;
            if (command == "row"){
                cin>>a>>b;

                for(int j = 0; j < N; j++){
                    int aux = matrix[a-1][j] ;
                    matrix[a-1][j] = matrix[b-1][j];
                    matrix[b-1][j] = aux;
                }

            }
            else if (command == "col"){
                cin>>a>>b;


                 for(int j = 0; j < N; j++){
                    int aux = matrix[j][a-1] ;
                    matrix[j][a-1] = matrix[j][b-1];
                    matrix[j][b-1] = aux;
                }
                
            }

            else if (command == "inc"){
               for(int i = 0; i < N; i++){
                    for(int j = 0; j < N; j++){
                        matrix[i][j] = (matrix[i][j]+1)%10;
                    }
                }

                
            }

            else if (command == "dec"){
               
                for(int i = 0; i < N; i++){
                    for(int j = 0; j < N; j++){
                       matrix[i][j] = (matrix[i][j]+9)%10;
                    }
                }
            }

            else if (command == "transpose"){
               vector<vector<int>> matrix_t(N, vector<int>(N));

               for(int i = 0; i < N; i++){
                    for(int j = 0; j < N; j++){
                       matrix_t[j][i] = matrix[i][j];
                    }
                }
                matrix = matrix_t;
            }


        }
        
        cout<< "Case #"<<t<<endl;
        for(int i = 0; i < N; i++){
            for(int j = 0; j < N; j++){
                cout<< matrix[i][j];
            }
            cout<<endl;
        }
        cout<<endl;


        t++;
        
    }
}