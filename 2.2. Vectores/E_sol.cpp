#include <iostream>
#include <vector>
using namespace std;



int main(){

    int test_case = 0;
    int i = 1;
    cin>>test_case;
    while(test_case--){
        int nums_tel=0; 
        cin>>nums_tel;

        vector<string> posible_nums;
        vector<string> nums(nums_tel);

        
        for(int j=0; j < nums_tel; j++){
            string num;
            cin>>num;
            nums[j] = num;
        }

        string mom_num;
        cin>>mom_num;

        for(int i = 0; i < nums_tel; i++){
            int diferencias = 0;
            bool correct = true;
            for(int j = 0; j < mom_num.size(); j++){
                if(mom_num[j] != nums[i][j]){
                    diferencias++;
                }
                if (diferencias>1) {
                    correct =false;
                    break;
                }
            }

            if(correct) posible_nums.push_back(nums[i]);  
        }
        cout<<"Case " << i++ <<":\n";
        for(auto a: posible_nums) cout << a <<"\n";
        

    }
}


