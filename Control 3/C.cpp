// THE BUS DRIVER PROBLEM

// HOW TO SOLVE
    // JUST ORDER MORNING (creciente) AND AFTERNOON (decreciente) ROUTES VECTORS
    // IN THAT ORDER IS HOW THE BUSES ARE GOING TO BE MATCHED

#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;


int main(){

    int n,d,r;
    while(cin>>n>>d>>r && n){
        vector<int> morning;
        vector<int> afternoon;

        for(int i = 0; i < n; i++){
            int n ; cin>>n;
            morning.push_back(n);
        }
        sort(morning.begin(), morning.end());
        for(int i = 0; i < n; i++){
            int n ; cin>>n;
            afternoon.push_back(n);
        }
        sort(afternoon.begin(), afternoon.end(), std::greater<int>());

        int res= 0;
        for(int i = 0; i < n; i++){
            int sum  = morning[i]+afternoon[i];
            if(sum>d) res += sum-d;
        }

        cout<< r*res<<endl;

    }

}