// This problem is solved with a single pass algorithm 
// Space complexity:  O(N)

#include <iostream>
using namespace std;
#include <vector>


int main(){

    string row1;

    vector<string> inputs;

    while(std::getline(std::cin, row1) && !row1.empty()){
        inputs.push_back(row1);
    }

    for(auto ix : inputs){

        int result = 0;
        int gap_count = 0;
        int max = 0;
        int last_x = 0;

        string row = ix;


        // RIGHT EDGE
        int ind = 0;
        if (row[0] == '.'){
            while(ind < row.length() && row[ind] != 'X'){
                gap_count++;
                ind++;
            }

            max = gap_count-1;
            gap_count = 0;
            last_x = ind;
            

        }
        
        //MIDDLE EDGE
        for(int i = ind; i < row.length(); i++){
            
            if (row[i] == '.'){
                gap_count++;
                
            }
            else{
                if(i == last_x){
                    last_x =i ;
                    gap_count = 0;
                    continue;
                } 
                int gap = abs(i - last_x-2)/2;
                last_x = i;
                if (gap > max) max = gap;
                gap_count = 0;
            }
        }

        // LEFT 

        if (gap_count != 0){
            if(gap_count > max) max = gap_count-1;
        }
        cout << max << "\n" ;
    }

    return 0;
}


