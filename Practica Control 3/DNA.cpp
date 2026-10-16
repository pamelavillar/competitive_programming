#include <iostream>
#include <vector>
#include <set>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int n ;
        cin>>n;
        vector<string> sets;
        for(int i  = 0; i<n; i++){
            string a;
            cin>> a;
            sets.push_back(a);
        }
        
        
        vector<bool> common(26,false);

        for(int i  = 0; i<sets[0].size(); i++){
            char letra = sets[0][i];
            int num = letra-'a';
            common[num] =true;
        }

        int corte = 0;
        for(int i  = 1; i<n; i++){
            vector<bool> abecedario(26,false);

            for(int j = 0; j < sets[i].size(); j++){
                char letra = sets[i][j];
                int num = letra-'a';
                abecedario[num] = true;
            }
            int cont =0;
            for(int k = 0; k < 26; k++){
                if(common[k] != abecedario[k]){
                    common[k]= false;
                }
                if(!common[k]) cont++;
            }
            //cout<<cont;
            if(cont == 26)  {
                corte++;
                common = abecedario;
            }

        }
        cout<<corte<<endl;

    }
}