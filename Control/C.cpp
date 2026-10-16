// AGE SORT

// HOW TO SOLVE


#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;


int main(){
    int n ;
    while(cin>>n && n){
        vector<int> ages;
        for(int i = 0; i < n; i++){
            int num; cin>>num;
            ages.push_back(num);
        }

        sort(ages.begin(), ages.end());

        for(int i = 0; i < n; i++){
            cout<<ages[i];
            if(i != n-1) cout<<" ";
        }
        cout<<"\n";

    }
}