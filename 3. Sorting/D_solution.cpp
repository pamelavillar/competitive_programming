#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    
    while(true){
        int num;
        cin >> num;
        if(num == 0) break;

        vector<string> nombres(num);

        for(int i  = 0; i < num; i++){
            cin >> nombres[i];
        }

        sort(nombres.begin(), nombres.end());


        int n2 = num/2;
        int n1 = n2-1;  
        string sol;
        int i = 0;  

        while(i < nombres[n1].size() && i < nombres[n2].size() && nombres[n1][i] == nombres[n2][i]) i++;

        if(i == nombres[n1].size() ||  i+1 == nombres[n1].size()){
            sol = nombres[n1];
        }
        else{
            bool cut = (nombres[n1][i]+1 <nombres[n2][i] || nombres[n1][i]+1 == nombres[n2][i] && i+1 < nombres[n2].size());
            
            if(cut){
                sol = nombres[n1].substr(0,i) + char (nombres[n1][i]+1);
            }
            else{
                int j = i+1;
                while(j < nombres[n1].size()-1 && nombres[n1][j] == 'Z') j++;
                if(j < nombres[n1].size()-1 ){
                    sol = nombres[n1].substr(0,j) + char (nombres[n1][j]+1);
                }
                else{
                    sol = nombres[n1];
                }
            }
        }
        

        cout<<sol<<"\n";


    }
}