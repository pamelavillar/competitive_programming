#include <iostream>
#include <set>

#include <vector>
using namespace std;

int main(){

    

    int days = 1 ;
    
    while(days){
        
        cin>>days;
        if (!days) break;

        std::multiset<int> bills;
        long long acumulado=0;

        for(int i = 0; i< days; i++){
            int num_bills;
            cin>>num_bills;
            for(int j = 0; j < num_bills; j++){
                int money;
                cin>>money;
                bills.insert(money);
            }

            acumulado += (*bills.rbegin() - *bills.begin());

            bills.erase(bills.begin());
            bills.erase(--bills.end());
        }
        cout<<acumulado<<"\n";

    }

}