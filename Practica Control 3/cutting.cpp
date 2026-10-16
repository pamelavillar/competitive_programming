#include <iostream>
#include <vector>
#include <set>
#include <queue>
using namespace std;

int main(){
    int l;
    
    while(cin>>l && l != 0){
        int c ;
        cin>>c;

        vector<vector<int>> dp(c+2,vector<int> (c+2,0));

        vector<int> cortes;
        cortes.push_back(0);
        for(int i = 0; i < c; i++){
            int n;
            cin>>n;
            cortes.push_back(n);
        }
        cortes.push_back(l);

        //AQUI EMPIEZA PROGRAMACION DINAMICA

        for(int len = 2; len < c+2; len++){
            for(int i = 0; len + i < c+2; i++){
                int j = i +len;
                dp[i][j]= 1e9;
                for (int k = i + 1; k < j; k++) {
                    dp[i][j] = min(dp[i][j], cortes[j] - cortes[i] + dp[i][k] + dp[k][j]);
                }
            }
        }

        cout<<"The minimum cutting is "<<dp[0][c+1]<<".\n";

    }
}