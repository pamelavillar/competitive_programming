// WHERE IS THE MARBLE

// HOW TO SOLVE
// SOLO USA LOWER BOUND Y YA , Y VERIFIQUE QUE SI COINCIDE CON EL NUMERO SOLICITADO

#include<iostream>
#include <vector>
#include <set>
#include <cmath>
#include <algorithm>
using namespace std;

int main (int argc, char *argv[]) {
	
	int n, q ;
	int t = 1;
	while(cin>>n>>q && n != 0){
		vector<int> marbles;
		
		for(int i = 0; i < n; i++){
			int num; cin>> num;
			marbles.push_back(num);
		}
		
		sort(marbles.begin(), marbles.end());

        vector<int>queries;
        for(int i = 0; i < q; i++){
            int num; cin>>num;
            queries.push_back(num);
        }
       
        cout<<"CASE# "<<t<<":\n";

        for(int i = 0; i < q; i++){
            int num = queries[i];
            auto a = std::lower_bound(marbles.begin(), marbles.end(),num);
            if(*a == num){
                cout<<num<<" found at "<<(a-marbles.begin())+1<<"\n";
            }
            else{
                cout<<num<<" not found\n";
            }
        }
        t++;
	}
	return 0;
}
