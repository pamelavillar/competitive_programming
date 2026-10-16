#include <iostream>
#include <vector>
using namespace std;


int main(){
    int num_stacks = 1;
    int j = 1;
    while (cin>>num_stacks && num_stacks != 0){
        vector<int> bricks(num_stacks);

        int total_bricks = 0;
        for(int i = 0; i < num_stacks; i++){
            cin>> bricks[i] ;
            total_bricks+=bricks[i];
        }

        int height = total_bricks/num_stacks;
        int moves = 0;

        for(int a: bricks){
            //cout << a << endl;
            if(a > height){
                moves+=(a-height);
            }
        }

        cout<<"Set #"<<j<<"\n";
        cout<< "The minimum number of moves is "<< moves<<".\n\n";
        j++;

    }
}