#include <iostream>
#include <vector>
#include <map>
using namespace std;

int main(){
    int n_elem = 1;
    int n_queries = 1;
    
    while( cin>>n_elem>>n_queries){
       
        map<int, vector<int>> nums;

        for (int i = 0; i < n_elem; i++){
            int num; cin>>num;
            auto it = nums.find(num);
            nums[num].push_back(i);
        }
        

        for (int i = 0; i < n_queries; i++){
            int k_ocurrence = 0, integer= 0;
            cin>>k_ocurrence>>integer;

            auto it = nums.find(integer);
            if(it!= nums.end()){
                if(k_ocurrence > nums[integer].size())cout<<"0"<<"\n";
                else{
                    cout<<nums[integer][k_ocurrence-1] + 1<<"\n";
                }
            }else{
                cout<<"0"<<"\n";
            }

        }
    }
}
