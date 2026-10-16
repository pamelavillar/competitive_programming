
#include <iostream>
#include <string>
#include <vector>
using namespace std;
int main()
{
    int T;
    cin>> T;
    if(T<1 || T>50){
    return 0;
    }
    vector<string> vtor(T);
    for(int i=0;i<T;i++){
        cin>>vtor[i]; 
    }
    
    for(int i=0;i<vtor.size();i++){



        string road = vtor[i];

        int ocupados = 0;
        vector<bool> available(road.length(), true);

        for(int j = 0; j < road.length(); j++){
            int i5 = j-1;
            int i10 = j-2;
            int i5p = j+1;

            switch (road[j]){
                case '-':
                    break;
                case 'B':
                    if(available[j]) {
                        available[j] = false; ocupados++;
                    }

                    if (i5 >= 0 && available[i5] ) {                    
                        available[i5] = false;
                        ocupados++;
                    }

                    if (i10 >= 0 && available[i10] ) {
                         available[i10] = false;
                        ocupados++;
                    }
                    
                    break;
                    
                case 'D':  
                    if(available[j]) {
                        available[j] = false; ocupados++;
                    }
                    break;
                case 'S':
                    if(available[j]) {
                        available[j] = false; ocupados++;
                    }
                    
                    if (i5 >= 0 && available[i5] ) {
                        available[i5] = false;
                        ocupados++;
                    }

                    if (i5p < road.size() && available[i5p] ){
                        available[i5p] = false;
                        ocupados++;
                    }
                    break;
            }

        }
        cout<<"Case "<<i+1<<": "<<road.size() - ocupados << "\n" ;
        
    }
    return 0;
}